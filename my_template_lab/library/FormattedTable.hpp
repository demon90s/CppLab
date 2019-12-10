#pragma once

#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <iostream>

/*
    可打印的表，打印结果如：

    (1) formatted table
    +-----+----------+
    |field|filed|... |
    +-----+----------+
    |value|value|... |
    |value|value|... |
    +-----+----------+

    (2) listed table
    **************** 1. row ****************
    field: value
    field: value
    ...
    **************** 2. row ****************
    field: value
    field: value
    ...

    要求打印的类型已重载 std::ostream& operator<<(std::ostream &os, const T &v) 运算符
    内置类型天然满足
*/

class FormattedTable
{
private:
    using Row = std::vector<std::string>;

    struct Field
    {
        Field(const std::string &_name) :
            name(_name), hint_len(0)
        {
            hint_len = static_cast<int>(name.length());
        }
        std::string name;
        int hint_len;   // 字段长度，根据插入的值进行动态调整（取最长内容的长度）
    };

public:
    // APIS

    // 设置字段内容
    void SetFieldList(const std::initializer_list<std::string> &field_list)
    {
        m_field_list.clear();
        m_row_list.clear();

        for (const auto &field : field_list)
        {
            m_field_list.emplace_back(field);
        }
    }

    // 添加一行记录
    template <typename... Args>
    void AddRow(const Args& ... rest)
    {
        m_row_list.resize(m_row_list.size() + 1);
        Row &row = m_row_list.back();
        this->DoAddRow(row, rest...);
    }

    int GetRowNum() const
    {
        return static_cast<int>(m_row_list.size());
    }

    // 得到格式化的表格
    std::string GetFormattedTable()
    {
        this->MakeBar();
        this->MakeBarFrame();

        std::string table;

        table += m_bar_frame;
        table += '\n';
        table += m_bar;
        table += '\n';
        table += m_bar_frame;
        table += '\n';
        for (const auto &row : m_row_list)
        {
            table += '|';
            for (std::size_t i = 0; i < m_field_list.size(); i++)
            {
                if (i < row.size())
                {
                    table += this->FixValue(row[i], m_field_list[i].hint_len);
                }
                
                table += '|';
            }
            table += '\n';
        }
        table += m_bar_frame;

        return table;
    }

    // 得到listed表格
    std::string GetListedTable()
    {
        std::string table;

        for (std::size_t row = 0; row < m_row_list.size(); row++)
        {
            table += ("*************************** " + std::to_string(row + 1) + ". row ***************************\n");
            
            for (std::size_t i = 0; i < m_field_list.size() && i < m_row_list[row].size(); i++)
            {
                table += (m_field_list[i].name + ": ");
                table += m_row_list[row][i];
                table += '\n';
            }
        }

        return table;
    }

private:
    // IMPLS

    template <typename T>
    void DoAddRowHelper(Row &raw, const T &t)
    {
        auto add_index = raw.size();
        if (add_index < m_field_list.size())
        {
            std::string value = ToString(t);
            int value_len = static_cast<int>(value.length());
            if (value_len > m_field_list[add_index].hint_len)
            {
                m_field_list[add_index].hint_len = value_len;
            }
            raw.emplace_back(value);
        }
    }

    template <typename T>
    void DoAddRow(Row &raw, const T &t)
    {
        this->DoAddRowHelper(raw, t);
    }

    template <typename T, typename... Args>
    void DoAddRow(Row &raw, const T &t, const Args& ... rest)
    {
        this->DoAddRowHelper(raw, t);
        DoAddRow(raw, rest...);
    }

    void MakeBar()
    {
        m_bar_plus_index.clear();
        m_bar = "|";
        m_bar_plus_index.insert(0);

        for (std::size_t i = 0; i < m_field_list.size(); i++)
        {
            const auto &field = m_field_list[i];

            m_bar += this->FixValue(field.name, field.hint_len);

            m_bar_plus_index.insert(m_bar.size());
            m_bar += '|';
        }
    }

    void MakeBarFrame()
    {
        m_bar_frame = "";

        for (std::size_t i = 0; i < m_bar.length(); i++)
        {
            if (m_bar_plus_index.find(i) != m_bar_plus_index.end())
            {
                m_bar_frame += '+';
            }
            else
            {
                m_bar_frame += '-';
            }
        }
    }

    template<typename T>
    static std::string ToString(T &val)
    {
        std::ostringstream oss;
        if (oss << val) {
            return oss.str();
        }
        return "";
    }

    static bool IsAsc(char c)
    {
        return (c & (1 << 8)) == 0;
    }

    static int GetMBCount(const char *value, int len)
    {
        // 获得 value 的多字节字符个数（认为多字节字符占据3个字节）
        const char *p = value;
        int count = 0;
        while (p < value + len)
        {
            if (!IsAsc(*p))
            {
                p += 3;
                count++;
            }
            else
            {
                p++;
            }
        }
        return count;
    }

    static std::string FixValue(const std::string &value, int hint_len)
    {
        char buffer[1024] {};   // 不可能一个字段有这么长的

        int more_len = hint_len - static_cast<int>(value.length());

        int mb_count = GetMBCount(value.c_str(), static_cast<int>(value.length()));
        more_len += mb_count; // trick, 目的是中英文对齐（且要求中文是3字节字符编码（UTF-8满足），先这样）

        if (more_len < 0) more_len = 0;
        std::string v = value + std::string(more_len, ' ');
        snprintf(buffer, sizeof(buffer), " %-s ", v.c_str());
        return buffer;
    }

private:
    std::vector<Field> m_field_list;                        // 字段列表
    std::string m_bar;                                      // 表头
    std::set<int> m_bar_plus_index;                         // 表框+号所在下标
    std::string m_bar_frame;                                // 表框
    std::vector<Row> m_row_list;                            // 所有记录
};

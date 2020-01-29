#pragma once

// 该容器的目的是为了提供一个可直接二进制化的hash table

// 无序的定长HashTable，要求存入的元素key自己实现 std::hash<> 的特化 和 operator==
// 内置类型天然满足

// 插入读取常数效率

#include <functional>
#include "Bitset.hpp"

template<typename Key, typename Value, int Len>
class FixLenHashTable
{
private:
    struct Pair
    {
        Key key {};
        Value value {};
    };

    Pair m_data[Len];
    int m_size;

    static const int INVALID_INDEX = -1;
    static const int INDEX_COUNT = ((Len % 8 == 0) ? (Len / 8) : (Len / 8 + 1)) * 8;
    Bitset<INDEX_COUNT> m_used_flag;

public:
    FixLenHashTable() : m_size(0)
    {
        static_assert(Len > 0, "FixLenMap Len MUST > 0");
    }
    
    int Size() const 
    {
        return m_size;
    }

    bool Put(const Key &key, const Value &value)
    {
        if (this->Size() >= Len)
        {
            return false;
        }

        const int search_index = static_cast<int>(std::hash<Key>()(key) % Len);
        int index = search_index;
        bool find = false;
        
        do
        {
            if (m_used_flag.Test(index))
            {
                if (m_data[index].key == key)
                {
                    break; // 重复key
                }
                index = (index + 1) % Len;
            }
            else
            {
                find = true;
                break;
            }
        } while (index != search_index);

        if (!find)
        {
            return false;
        }

        m_data[index].key = key;
        m_data[index].value = value;

        m_used_flag.Set(index);

        m_size++;
        return true;
    }

    bool Erase(const Key &key)
    {
        int index = this->GetIndex(key);
        if (index == INVALID_INDEX)
        {
            return false;
        }

        m_used_flag.UnSet(index);
        m_size--;
        return true;
    }

    const Value *Get(const Key &key) const
    {
        int index = this->GetIndex(key);
        if (index == INVALID_INDEX)
        {
            return nullptr;
        }

        return &m_data[index].value;
    }

    Value *Get(const Key &key)
    {
        return const_cast<Value*>(
            static_cast<const FixLenHashTable*>(this)->Get(key));
    }

    void Travel(std::function<void(Key, Value&)> f)
    {
        for (int index = 0; index < Len; index++)
        {
            if (m_used_flag.Test(index))
                f(m_data[index].key, m_data[index].value);
        }
    }

private:
    int GetIndex(const Key &key) const
    {
        const int search_index = static_cast<int>(std::hash<Key>()(key) % Len);
        int index = search_index;
        bool find = false;
        
        do
        {
            if (!m_used_flag.Test(index) || !(m_data[index].key == key))
            {
                index = (index + 1) % Len;
            }
            else
            {
                find = true;
                break;
            }
        } while (index != search_index);

        if (!find)
        {
            return INVALID_INDEX;
        }

        return index;
    }
};

#pragma once

// 无序的定长HashTable，要求存入的元素key自己实现 std::hash<> 的特化 和 operator==
// 内置类型天然满足

// 插入读取常数效率

// 不允许出现碰撞，如果发生碰撞，就以失败处理

#include <functional>

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

public:
    FixLenHashTable()
    {
        static_assert(Len > 0, "FixLenMap Len MUST > 0");
    }

    bool Put(const Key &key, const Value &value)
    {
        int index = this->GetIndex(key);

        if (m_data[index].key == key)
        {
            return false;
        }
        m_data[index].key = key;
        m_data[index].value = value;
        return true;
    }

    bool Erase(const Key &key)
    {
        int index = this->GetIndex(key);

        if (m_data[index].key == key)
        {
            m_data[index] = Pair {};
            return true;
        }

        return false;
    }

    Value *Get(const Key &key)
    {
        int index = this->GetIndex(key);

        if (m_data[index].key == key)
        {
            return &m_data[index].value;
        }

        return nullptr;
    }

    const Value *Get(const Key &key) const
    {
        return static_cast<const Value*>(
            const_cast<FixLenHashTable*>(this)->Get(key));
    }

    void Travel(std::function<void(Key, Value&)> f)
    {
        for (auto &p : m_data)
        {
            f(p.key, p.value);
        }
    }

private:
    int GetIndex(const Key &key) const
    {
        return static_cast<int>(std::hash<Key>()(key) % Len);
    }
};

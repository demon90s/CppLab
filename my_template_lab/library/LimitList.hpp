#pragma once

#include <list>
#include <functional>

/*
 有上限的 list
*/

template<typename T, int Len>
class LimitList
{
public:
	LimitList() {}
	LimitList(std::initializer_list<T> il) {
		for (const auto &v : il) {
			m_list.push_back(v);
			if (Size() >= Len) break;
		}
	}

	typename std::list<T>::iterator begin() { return m_list.begin(); }
	typename std::list<T>::iterator end() { return m_list.end(); }

	bool IsEmpty() const { return m_list.empty(); }
	int Size() const { return static_cast<int>(m_list.size()); }
	void Clear() { return m_list.clear(); }

	bool PushBack(const T& v)
	{
		if (Size() >= Len) return false;
		m_list.push_back(v);
		return true;
	}

	bool PushFront(const T& v)
	{
		if (Size() >= Len) return false;
		m_list.push_front(v);
		return true;
	}

	typename std::list<T>::iterator Erase(typename std::list<T>::iterator it) { return m_list.erase(it); }

	void PopBack()
	{
		if (IsEmpty()) return;
		m_list.pop_back();
	}

	void PopFront()
	{
		if (IsEmpty()) return;
		m_list.pop_front();
	}

	void Sort(std::function<bool(const T&, const T&)> pred = nullptr)
	{
		if (pred) m_list.sort(pred);
		else m_list.sort();
	}

	// 转化成C数组
	void ToCArray(T(&arr)[Len])
	{
		int n = 0;
		for (const auto& v : m_list)
		{
			arr[n++] = v;
		}
	}

private:
	std::list<T> m_list;
};
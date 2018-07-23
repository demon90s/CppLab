#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <cstring>
#include <stdexcept>

/*
	简单的序列化工具，提供序列化内置类型、数组、聚合类型的方法
*/
class Serializer
{
	static const size_t DEFAULT_LEN = 1024;
public:
	Serializer() : m_len(DEFAULT_LEN), m_buffer(new char[m_len]{}), m_cur_pos(m_buffer) {}
	~Serializer() { delete []m_buffer; }

	size_t Size() const { return m_cur_pos - m_buffer; }	// 当前序列化缓冲区中的数据长度
	char* Ptr() const { return m_buffer; }
		
	template<typename T>
	void Write(const T &v)
	{
		while (m_cur_pos - m_buffer + sizeof(v) > m_len)
		{
			ReAllocate();
		}
		memcpy(m_cur_pos, &v, sizeof(v));
		m_cur_pos += sizeof(v);
	}

	template<typename T, typename... Args>
	void Write(const T &v, const Args&... rest)
	{
		Write(v);
		Write(rest...);
	}

private:
	// 拒绝拷贝
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);

	void ReAllocate()
	{
		char *new_buffer = new char[2 * m_len]{};
		memcpy(new_buffer, m_buffer, m_len);
		m_cur_pos = new_buffer + Size();
		delete[]m_buffer;
		m_buffer = new_buffer;
		m_len *= 2;
	}

	size_t m_len;				// buffer长度
	char *m_buffer;				// 用于存储序列化数据的缓冲区，自动增长
	char *m_cur_pos;			// 当前序列化的位置
};

class DeSerializer
{
public:
	DeSerializer(char *buffer, size_t len) : m_max_len(len), m_buffer(buffer), m_cur_pos(m_buffer) {}

	template<typename T>
	void Read(T &v)
	{
		if (m_cur_pos - m_buffer + sizeof(v) > m_max_len)
		{
			throw std::overflow_error("DeSerializer::Read failed: no more data to read");
		}
		memcpy(&v, m_cur_pos, sizeof(v));
		m_cur_pos += sizeof(v);
	}

	template<typename T, typename... Args>
	void Read(T &v, Args&... rest)
	{
		Read(v);
		Read(rest...);
	}

private:
	// 拒绝拷贝
	DeSerializer(const DeSerializer&);
	DeSerializer& operator=(const DeSerializer&);

	const size_t m_max_len;			// buffer最大长度
	const char *const m_buffer;		// 用于反序列化数据的缓冲区
	const char *m_cur_pos;			// 当前反序列化的位置
};

#endif // __SERIALIZER_HPP__

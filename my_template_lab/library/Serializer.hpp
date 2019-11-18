#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <cstring>
#include <stdexcept>

/*
	�򵥵����л����ߣ��ṩ���л��������͡����顢�ۺ����͵ķ���
*/
class Serializer
{
	static const size_t DEFAULT_LEN = 1024;
public:
	Serializer() : m_len(DEFAULT_LEN), m_buffer(new char[m_len]{}), m_cur_pos(m_buffer) {}
	~Serializer() { delete []m_buffer; }

	size_t Size() const { return m_cur_pos - m_buffer; }	// ��ǰ���л��������е����ݳ���
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
	// �ܾ�����
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

	size_t m_len;				// buffer����
	char *m_buffer;				// ���ڴ洢���л����ݵĻ��������Զ�����
	char *m_cur_pos;			// ��ǰ���л���λ��
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
	// �ܾ�����
	DeSerializer(const DeSerializer&);
	DeSerializer& operator=(const DeSerializer&);

	const size_t m_max_len;			// buffer��󳤶�
	const char *const m_buffer;		// ���ڷ����л����ݵĻ�����
	const char *m_cur_pos;			// ��ǰ�����л���λ��
};

#endif // __SERIALIZER_HPP__

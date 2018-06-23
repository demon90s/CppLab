#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

// ��ȡ��������СԪ�ص��±�
template<typename T, unsigned N>
inline int GetMinIndex(T (&arr)[N])
{
	int index = 0;
	const T *tmp = &arr[0];
	for (int i = 1; i < N; ++i)
	{
		if (*tmp > arr[i])
		{
			index = i;
			tmp = &arr[i];
		}
	}
	return index;
}

// ��ȡ���������Ԫ�ص��±�
template<typename T, unsigned N>
inline int GetMaxIndex(T(&arr)[N])
{
	int index = 0;
	const T *tmp = &arr[0];
	for (int i = 1; i < N; ++i)
	{
		if (*tmp < arr[i])
		{
			index = i;
			tmp = &arr[i];
		}
	}
	return index;
}

#endif // __TEMPLATES_HPP__
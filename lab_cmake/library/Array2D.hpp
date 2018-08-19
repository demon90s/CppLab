// 二维数组，实则用一维数组模拟

#include <utility>
#include <algorithm>
#include <functional>

template <typename T, int ROW, int COL>
class Array2D
{
public:
	Array2D() : arr{} {}
	int Row() const { return ROW; }
	int Col() const { return COL; }

	int GetIdx(int row, int col) const
	{
		if (row < 0 || row >= ROW || col < 0 || col >= COL) return -1;
		return row * COL + col;
	}

	std::pair<int, int> GetRowCol(int idx) const
	{
		int row = idx / COL;
		int col = idx - row * COL;
		return std::pair<int, int>(row, col);
	}

	const T& operator[](int idx) const
	{
		return arr[idx];
	}

	T& operator[](int idx)
	{
		return const_cast<T&>(
			static_cast<const Array2D&>(*this)[idx]
			);
	}

	// 以行为单位排序
	void Sort(int row, std::function<bool(const T&, const T&)> cmp = nullptr)
	{
		if (row < 0 || row >= ROW) return;
		std::stable_sort(arr + row * COL, arr + row * COL + COL, cmp);
	}

	// 全部排序
	void Sort(std::function<bool(const T&, const T&)> cmp = nullptr)
	{
		for (int row = 0; row < ROW; ++row)
		{
			Sort(row, cmp);
		}
	}

private:
	T arr[ROW * COL];
};
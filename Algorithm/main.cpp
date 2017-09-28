#include <iostream>

using namespace std;

#define __swap(x, y) {(x) = (x) ^ (y); (y) = (x) ^ (y); (x) = (x) ^ (y);}

void __print_list(int __src[], int __first, int __last);

void __merge_sort(int __src[], int __first, int __last, int __rst[]);
void __merge_data(int __src[], int __first, int __last, int __rst[]);


int main()
{
	int src[12] = { 1, 9, 7, 8, 23, 2, 3, 5, 6, 54, 0, 4 };
	int rst[12] = { 0 };
	__print_list(src, 0, 11);
	__merge_sort(src, 0, 11, rst);
	__print_list(rst, 0, 11);
	return 0;
}



void __merge_sort(int __src[], int __first, int __last, int __rst[])
{
	if (__first == __last)
	{
		return;
	}

	if (__first == __last - 1)
	{
		if (__src[__first] > __src[__last])
		{
			__swap(__src[__first], __src[__last]);
			__swap(__rst[__first], __rst[__last]);
		}

		return;
	}

	__merge_sort(__src, __first, __first + (__last - __first) / 2, __rst);
	__merge_sort(__src, __first + (__last - __first) / 2 + 1, __last, __rst);
	__merge_data(__src, __first, __last, __rst);
	
	memcpy(__src + __first, __rst + __first, sizeof(int) * (__last - __first + 1));
}


void __merge_data(int __src[], int __first, int __last, int __rst[])
{
	int left_index = __first, index = __first;
	int left_lenth = (__last - __first) / 2 + 1;
	int right_index = (__last + __first) / 2 + 1;
	int right_lenth = __last - right_index + 1;

	while (left_index < __first + left_lenth && right_index <= __last)
	{
		if (__src[left_index] < __src[right_index])
		{
			__rst[index++] = __src[left_index++];
		}
		else
		{
			__rst[index++] = __src[right_index++];
		}
	}

	while (left_index < __first + left_lenth)
	{
		__rst[index++] = __src[left_index++];
	}

	while (right_index <= __last)
	{
		__rst[index++] = __src[right_index++];
	}
}


void __print_list(int __src[], int __first, int __last)
{
	for (int i = __first; i <= __last; ++i)
		std::cout << __src[i] << " ";
	std::cout << std::endl;
}

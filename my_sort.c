#include <stdio.h>
#include <stdlib.h>

//#define ARR_SIZE 13
#define ARR_SIZE 5
//int arr[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
int arr[] = { 5,4,3,2,1,6,7,8,9 };

//插入排序
void insertion_sort(int size)
{
	int temp, i, j;

	//抽牌
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i; j >= 0; j--)
		{
			if (temp < arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = temp;
	}
}

//希尔排序
void shell_sort(int size)
{
	int i, j, k;
	int temp;
	//增量循环
	for (i = size / 2; i > 0; i /= 2)
	{
		printf("%d\n", i);
		//插入排序
		for (j = i; j < size; j++)
		{
			temp = arr[j];
			for (k = j; k >= i; k -= i)
			{
				if (arr[k - i] > temp)
				{
					arr[k] = arr[k - i];
				}
				else
				{
					break;
				}
			}
			arr[k] = temp;
		}
	}
}

//堆排序
//最大堆下沉函数
//i为顶点
//n为调整数组元素个数
void PercDown(int i, int n)
{
	int node, temp;
	int child, parent;
	parent = i - 1;
	child = parent * 2 + 1;

	while (child < n)
	{
		//对比左右子树 左子树大时
		if (arr[child] > arr[child + 1] && child + 1 < n)
		{
			if (arr[parent] < arr[child])
			{
				temp = arr[parent];
				arr[parent] = arr[child];
				arr[child] = temp;
				parent = child;
			}
		}//右子树大时
		else if (arr[child] < arr[child + 1] && child + 1 < n)
		{
			if (arr[parent] < arr[child + 1])
			{
				temp = arr[parent];
				arr[parent] = arr[child + 1];
				arr[child + 1] = temp;
				parent = child + 1;
			}
		}
		else
		{
			break;
		}
		child = parent * 2 + 1;
	}
}

//堆排序
void heap_sort(int size)
{
	int i, temp;
	//先执行最大顶堆的创建
	for (i = size / 2; i > 0; i--)
	{
		PercDown(i, size);
	}

	//开始排序
	for (i = size - 1; i > 1; i--)
	{
		//最大数置为末尾
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		PercDown(1, i);
	}
}

//数组中选出两个最大值
void max2(int arr[], int lo, int hi, int *x1, int *x2)
{
	int min, tmp;
	//递归基
	//因为hi为数组元素个数  所以hi-1才是真正数组坐标
	//x1为大值下标 x2为小值下标
	if (lo + 2 == hi) //两个元素时
	{
		*x1 = arr[lo] > arr[hi - 1] ? lo : hi - 1;
		*x2 = arr[lo] < arr[hi - 1] ? lo : hi - 1;
		return;
	}

	if (lo + 3 == hi) //三个元素时找出最大两个元素
	{
		if (arr[lo] > arr[lo + 1])
		{
			*x1 = lo;
			*x2 = lo + 1;
		}
		else
		{
			*x1 = lo + 1;
			*x2 = lo;
		}

		if (arr[lo + 2] > arr[*x1])
		{
			tmp = *x1;
			*x1 = lo + 2;
			*x2 = tmp;
		}
		else
		{
			if (arr[lo + 2] > arr[*x2])
			{
				*x2 = lo + 2;
			}
		}
		return;
	}

	//折半分治
	min = (lo + hi) / 2;

	//递归
	int x1l, x2l, x1r, x2r;
	max2(arr, lo, min, &x1l, &x2l);
	max2(arr, min, hi, &x1r, &x2r);

	//判断大小
	//x1为大值 x2为小值
	if (arr[x1l] > arr[x1r])
	{
		*x1 = x1l;
		*x2 = arr[x2l] > arr[x1r] ? x2l : x1r;
	}
	else
	{
		*x1 = x1r;
		*x2 = arr[x2r] > arr[x1l] ? x2r : x1l;
	}
}

//起泡排序
//[lo,hi)
int bubble_sort(int lo, int hi)
{
	int tmp, last;
	last = lo;
	while (++lo < hi)
	{
		if (arr[lo - 1] > arr[lo])
		{
			//已排序最后位置
			last = lo;
			//swap
			tmp = arr[lo - 1];
			arr[lo - 1] = arr[lo];
			arr[lo] = tmp;
		}
	}

	return last;
}

void cycle_bubble(int lo, int hi)
{
	while (lo < (hi = bubble_sort(lo, hi)));
}

//归并排序
void merge_sort(int lo, int hi)
{

}

int main()
{
	//insertion_sort(ARR_SIZE);
	//shell_sort(ARR_SIZE);
	//heap_sort(ARR_SIZE);
	//cycle_bubble(0, 9);

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[], int l, int mid, int r)
{
	int len, i, pl, pr;
	int *tmp = NULL;

	len = r - l + 1;
	tmp = (int*)malloc(len * sizeof(int));  //申请存放完整序列内存
	memset(tmp, 0x0, len * sizeof(int));

	pl = l;
	pr = mid + 1;
	i = 0;
	while (pl <= mid && pr <= r)  //两个子序列都有值，比较最小值
	{
		if (arr[pl] < arr[pr])
		{

			tmp[i++] = arr[pl++];
		}
		else
		{
			tmp[i++] = arr[pr++];
		}
	}
	while (pl <= mid)        //左边子序列还有值，直接拷贝到新序列中
	{
		tmp[i++] = arr[pl++];
	}
	while (pr <= r)      //右边子序列还有值
	{
		tmp[i++] = arr[pr++];
	}

	for (i = 0; i < len; i++)
	{
		arr[i + l] = tmp[i];
	}

	free(tmp);
	return;

}
int minn(int x, int y)
{
	return (x > y) ? y : x;
}
/*
归并完成的条件是得到子序列长度等于n，用sz表示当前子序列的长度。从1开始每次翻倍直到等于n。根据上面归并的方法，从i=0开始分组，下一组坐标应该i + 2*sz，第i组第一个元素为arr[i],最右边元素应该为arr[i+2*sz -1]，遇到序列最右边元素不够分组的元素个数时应该取n-1,中间的元素为arr[i+sz -1],依次类推进行归并得到完整的序列
*/
void mergeSortBu(int arr[], int n)
{
	int sz, i, mid, l, r;
	for (sz = 1; sz < n; sz += sz)
	{
		for (i = 0; i < n - sz; i += 2 * sz)
		{
			l = i;
			r = i + sz + sz;
			mid = i + sz - 1;
			merge(arr, l, mid, minn(r - 1, n - 1));
		}
	}
	return;
}
void mergeSort(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int mid = (l + r) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
	return;
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void main()
{
	int arr[10] = { 2,5,6,4,3,7,9,8,1,0 };
	printArray(arr, 10);
	mergeSort(arr, 0,9);
	printArray(arr, 10);
	getchar();
	return;
}

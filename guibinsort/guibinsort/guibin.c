#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[], int l, int mid, int r)
{
	int len, i, pl, pr;
	int *tmp = NULL;

	len = r - l + 1;
	tmp = (int*)malloc(len * sizeof(int));  //���������������ڴ�
	memset(tmp, 0x0, len * sizeof(int));

	pl = l;
	pr = mid + 1;
	i = 0;
	while (pl <= mid && pr <= r)  //���������ж���ֵ���Ƚ���Сֵ
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
	while (pl <= mid)        //��������л���ֵ��ֱ�ӿ�������������
	{
		tmp[i++] = arr[pl++];
	}
	while (pr <= r)      //�ұ������л���ֵ
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
�鲢��ɵ������ǵõ������г��ȵ���n����sz��ʾ��ǰ�����еĳ��ȡ���1��ʼÿ�η���ֱ������n����������鲢�ķ�������i=0��ʼ���飬��һ������Ӧ��i + 2*sz����i���һ��Ԫ��Ϊarr[i],���ұ�Ԫ��Ӧ��Ϊarr[i+2*sz -1]�������������ұ�Ԫ�ز��������Ԫ�ظ���ʱӦ��ȡn-1,�м��Ԫ��Ϊarr[i+sz -1],�������ƽ��й鲢�õ�����������
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

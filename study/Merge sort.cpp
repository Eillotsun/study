#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

/*
void mergeSort(T arr[], int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg)
	{
		for (int start = 0; start < len; start += seg + seg)
	}
}
*/

/*
void merge_Sort(vector<int> &a, int low, int high) {
	// Ҫ����������� a[low..high]
	if (low < high) { // base case: low >= high (0 or 1 item)
		int mid = (low + high) / 2;
		merge_Sort(a, low, mid); // �ֳ�һ��
		merge_Sort(a, mid + 1, high); // �ݹ�ؽ���������
		merge(a, low, mid, high); // ���: �鲢�ӳ���
	}
}

void merge(vector<int> &a, int low, int mid, int high) {
	// subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
	int N = high - low + 1;
	int *b = new int[N]; // ����: Ϊʲô������Ҫһ����ʱ������ b?
	int left = low, right = mid + 1, bIdx = 0;
	while (left <= mid && right <= high) // �鲢
		b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
	while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
	while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
	for (int k = 0; k < N; k++) a[low + k] = b[k]; // copy back
}

*/


void merge_sort(vector<int>& a, int low, int high) {
	if (low >= high) return;//���Ƿ�ֻʣ���һ��Ԫ����
	int mid = low + (high - low) / 2;//������ֳ���������
	merge_sort(a, low, mid);//����һ��һ�𣬵ݹ�ذ��������������ź���
	merge_sort(a, mid + 1, high);
	merge(a, low, mid, high);//���ź��������ϲ�����
}

void merge(vector<int>& nums, int low, int mid, int high) {
	vector<int> copy(nums);//������޸�ԭ����
	int k = low, i = low, j = mid + 1;//k��ʾ��ʲôλ�ÿ�ʼ�޸�ԭ�������飬i��ʾ���ߵ���ʼλ�ã�j��ʾ�Ұ�ߵ���ʼλ��

	while (k <= high) {
		if (i > mid) {//���ߵ�������������ˣ�ֻʣ�Ұ�ߵ�����ֻ����ұߵ������������ȥ������
			nums[k++] = copy[j++];
		}
		else if (j > high) {//�Ұ�ߵ�������������ˣ�ֻʣ���ߵ�����ֻ�����ߵ������������ȥ������
			nums[k++] = copy[i++];
		}
		else if (copy[j] < copy[i]) {//�ұߵ���С����ߵ��������ұߵ���������ȥһ��
			nums[k++] = copy[j++];
		}
		else {//��ߵ���С���ұߵ���������ߵ���������ȥһ��
			nums[k++] = copy[i++];
		}
	}
}

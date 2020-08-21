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
	// 要排序的数组是 a[low..high]
	if (low < high) { // base case: low >= high (0 or 1 item)
		int mid = (low + high) / 2;
		merge_Sort(a, low, mid); // 分成一半
		merge_Sort(a, mid + 1, high); // 递归地将它们排序
		merge(a, low, mid, high); // 解决: 归并子程序
	}
}

void merge(vector<int> &a, int low, int mid, int high) {
	// subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
	int N = high - low + 1;
	int *b = new int[N]; // 讨论: 为什么我们需要一个临时的数组 b?
	int left = low, right = mid + 1, bIdx = 0;
	while (left <= mid && right <= high) // 归并
		b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
	while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
	while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
	for (int k = 0; k < N; k++) a[low + k] = b[k]; // copy back
}

*/


void merge_sort(vector<int>& a, int low, int high) {
	if (low >= high) return;//看是否只剩最后一个元素了
	int mid = low + (high - low) / 2;//把数组分成左右两半
	merge_sort(a, low, mid);//与下一句一起，递归地把数组左右两半排好序
	merge_sort(a, mid + 1, high);
	merge(a, low, mid, high);//把排好序的数组合并起来
}

void merge(vector<int>& nums, int low, int mid, int high) {
	vector<int> copy(nums);//后面会修改原数组
	int k = low, i = low, j = mid + 1;//k表示从什么位置开始修改原来的数组，i表示左半边的起始位置，j表示右半边的起始位置

	while (k <= high) {
		if (i > mid) {//左半边的数都处理完毕了，只剩右半边的数。只需把右边的数逐个拷贝上去就行了
			nums[k++] = copy[j++];
		}
		else if (j > high) {//右半边的数都处理完毕了，只剩左半边的数。只需把左边的数逐个拷贝上去就行了
			nums[k++] = copy[i++];
		}
		else if (copy[j] < copy[i]) {//右边的数小于左边的数，将右边的数拷贝上去一个
			nums[k++] = copy[j++];
		}
		else {//左边的数小于右边的数，将左边的数拷贝上去一个
			nums[k++] = copy[i++];
		}
	}
}

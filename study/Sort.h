#pragma once
#include <iostream>
#include <vector>
using namespace std;

//In C++, you can use std::sort, std::stable_sort, or std::partial_sort in STL algorithm.

// 冒泡排序
void BubbleSort1(vector<int>& arr, int len);
void BubbleSort(vector<int>& arr, int len);


//选择排序
void selectionSort(vector <int>& a, int len);

//插入排序
void insertionSort(vector<int>& a, int N);

//归并排序
//void mergeSort(T arr[], int len);
//void merge(vector<int>& a, int low, int mid, int high);
//void merge_Sort(vector<int> &a, int low, int high);
void merge_sort(vector<int>& a, int low, int high);
void merge(vector<int>& nums, int low, int mid, int high);

//快速排序
//int partition(vector<int> &a, int i, int j);
void quickSort(vector<int>& a, int low, int high);


//头文件里如果定义函数 cpp文件如有相同函数 则分别会产生obj 所以在链接时链接器就会报错
//正确的做法应该是把定义放到.cpp文件中，然后只在头文件中声明
//对于函数来说，在 .h中添加声明即可
//对于变量来说，如果只是在.h声明，链接的时候还是会报错，因此，需要给变量添加 extern关键字

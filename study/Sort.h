#pragma once
#include <iostream>
#include <vector>
using namespace std;



// ð������
void BubbleSort1(vector<int>& arr, int len);
void BubbleSort(vector<int>& arr, int len);


//ѡ������
void selectionSort(vector <int>& a, int len);

//��������
void insertionSort(vector<int>& a, int N);

//�鲢����
//void mergeSort(T arr[], int len);
//void merge(vector<int>& a, int low, int mid, int high);
//void merge_Sort(vector<int> &a, int low, int high);
void merge_sort(vector<int>& a, int low, int high);
void merge(vector<int>& nums, int low, int mid, int high);
//ͷ�ļ���������庯�� cpp�ļ�������ͬ���� ��ֱ�����obj ����������ʱ�������ͻᱨ��
//��ȷ������Ӧ���ǰѶ���ŵ�.cpp�ļ��У�Ȼ��ֻ��ͷ�ļ�������
//���ں�����˵���� .h��������������
//���ڱ�����˵�����ֻ����.h���������ӵ�ʱ���ǻᱨ������ˣ���Ҫ���������� extern�ؼ���
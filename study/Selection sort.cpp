#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

void selectionSort(vector <int>& a, int len) {
	for (int i = 0; i < len; i++)
	{
		int k = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[i])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int temp;
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}

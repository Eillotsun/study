#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

void insertionSort(vector<int> &a, int N) {
    for (int i = 1; i < N; ++i) { // O(N)
        int X = a[i]; // X is the item to be inserted
        int j = i - 1;
        for (; j >= 0 && a[j] > X; --j) // can be fast or slow
            a[j + 1] = a[j]; // make a place for X
        a[j + 1] = X; // index j+1 is the insertion point
    }
}


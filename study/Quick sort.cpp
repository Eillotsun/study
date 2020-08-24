//
//  Quick sort.cpp
//  study
//
//  Created by 某某 s on 2020/8/21.
//  Copyright © 2020 某某 s. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Sort.h"//为什么我不加这一行就会报错啊？？说我下面 partition中的 所有a 报错Type 'vector<int>' does not provide a subscript operator


using namespace std;

/*int swap(int &a, int &b){
    int temp;
    temp = b;
    b = a;
    a = temp;
    return 0;
}
*/

int partition(vector<int> &a, int i, int j) {
  int p = a[i]; // p 是枢纽
  int m = i; // S1 和 S2 一开始是空的
  for (int k = i+1; k <= j; k++) { // 探索未知的区域
    if (a[k] < p) { // case 2
      m++;//第一次相当于枢纽前一位 需要有比他小的就++给它腾一个位置
      swap(a[k], a[m]); // C++ STL algorithm std::swap
    } // 注意：在情况1的时候我们什么不做: a[k] >= p
  }
  swap(a[i], a[m]); // 最后一步, 用a[m]交换枢纽
  return m; // 返回枢纽的指数, 用于快速排序（Quick Sort）
}



void quickSort(vector<int> &a, int low, int high) {
  if (low < high) {
    int m = partition(a, low, high); // O(N)
    // a[low..high] ~> a[low..m–1], pivot, a[m+1..high]
    quickSort(a, low, m-1); // 递归地将左子阵列排序
    // a[m] = pivot 在分区后就被排序好了
    quickSort(a, m+1, high); // 然后将右子阵列排序
  }
}


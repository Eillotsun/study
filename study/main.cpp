#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

int main(int argc, char** argv)

{
	int n;
	vector<int> num;
	while (cin >> n) {
		num.push_back(n);
		if (cin.get() == '\n')//完美
			break;
	}
	//cout << num.size() << endl;
	//BubbleSort1(num, num.size());
	//BubbleSort(num, num.size());
	//insertionSort(num, num.size());

	//merge_sort(num, 0,num.size()-1);// 当时留下的问题 本来想用模版写个通用变量的函数 结果模板产生对象造成报错
    quickSort(num, 0, int(num.size()-1));
	for (int x = 0; x < num.size(); x++)
	{
		cout << num[x] << ' ';
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include "Sort.h"
#include "Bitmask.h"
#include "List.hpp"

using namespace std;



int main(int argc, char** argv)

{
    
    /* test Sort
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
    */
    
    /* test Bitmask
     
    Permisson p;
    p.set_permisson(ALLOW_SELECT);
    cout<<"p's permission is "<<p.get_flag()<<endl;
     
     */
    List testlist;
    testlist.Init();
    testlist.Insert(0, 4);//当时出了一个错误，这是insert 由于没有写一个create链表的函数 就用insert生成 只是除了插入第一个节点的时候需要 insert 0 这个位置 之后insert的位置想在那里就在哪里 但是别超过length范围
    testlist.PrintList();

    testlist.Insert(1, 3);
    testlist.PrintList();
    
    testlist.Insert(1, 2);
    testlist.PrintList();

    testlist.Insert(1, 1);
    testlist.PrintList();
    testlist.Insert(1, 0);
    testlist.PrintList();
    testlist.Remove(4);
    testlist.PrintList();
    testlist.Update(2, 0);
    testlist.PrintList();
    
	return 0;
    
}

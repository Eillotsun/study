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
		if (cin.get() == '\n')//����
			break;
	}
	//cout << num.size() << endl;
	//BubbleSort1(num, num.size());
	//BubbleSort(num, num.size());
	//insertionSort(num, num.size());

	//merge_sort(num, 0,num.size()-1);// ��ʱ���µ����� ��������ģ��д��ͨ�ñ����ĺ��� ���ģ�����������ɱ���
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
    testlist.Insert(0, 4);//��ʱ����һ����������insert ����û��дһ��create����ĺ��� ����insert���� ֻ�ǳ��˲����һ���ڵ��ʱ����Ҫ insert 0 ���λ�� ֮��insert��λ����������������� ���Ǳ𳬹�length��Χ
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

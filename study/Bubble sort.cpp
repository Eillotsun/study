
#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

void BubbleSort1(vector<int> &arr, int len)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < len - 1; i++)//确定排序趟数
	{
		int j = 0;
		for (j = 0; j < len - 1 - i; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


void BubbleSort(vector<int> &arr, int len)
{
	int i = 0;
	int j = 0;
	int n = 0;//同时找最大值的最小需要两个下标遍历
	int flag = 0;
	int pos = 0;//用来记录最后一次交换的位置
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//确定排序趟数
	{
		pos = 0;
		flag = 0;
		//正向寻找最大值
		for (j = n; j < k; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//加入标记
				pos = j;//交换元素，记录最后一次交换的位置
				/*for (int x = 0; x < arr.size(); x++)
				{
					cout << arr[x] << ' ';
				}
				cout << endl;*/
			}
		
		}
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
		k = pos;//下一次比较到记录位置即可
		//反向寻找最小值
		for (j = k; j > n; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
				flag = 1;

				/*for (int x = 0; x < arr.size(); x++)
				{
					cout << arr[x] << ' ';
				}
				cout << endl;*/
			}
			else
				break;
			
		}
		n++;
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
	}
}

/*int main()
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
		BubbleSort(num, num.size());

		for (int x = 0; x < num.size(); x++)
		{
			cout << num[x] << ' ';
		}
		cout << endl;
		return 0;
	
}*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

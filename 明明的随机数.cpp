#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	vector<int > arr;
	int begin = -1;  //存放数字数量
	int tmp;
	while (cin >> tmp)
	{
		begin = tmp;
		int Tmp;
		for (int i = 0; i < begin; i++)
		{
			cin >> Tmp;
			if (find(arr.begin(), arr.end(), Tmp) == arr.end())  //如果查找失败
			{
				arr.push_back(Tmp);
			}
		}
		sort(arr.begin(), arr.end());  //从小到大排序
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << endl;
		}
		begin = -1;
		arr.clear();
	}
	return 0;
}

//泛型find()函数
//这里比较坑的地方是有多组测试数据，所以得将第一个数据和其他数据区分开来。
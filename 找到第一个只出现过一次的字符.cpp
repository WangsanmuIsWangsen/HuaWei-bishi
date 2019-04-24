#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef struct Node {
	char c;
	int flag;
};
int main(void)
{
	string str;
	vector<Node> R;
	Node tmp;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)  //遍历string
		{
			int j;
			for (j = 0; j < R.size(); j++)
			{
				if (R[j].c == str[i])  //如果已经存在
				{
					R[j].flag++;
					break;
				}
			}
			if (j == R.size())  //放入容器
			{
				tmp.c = str[i];
				tmp.flag = 1;
				R.push_back(tmp);
			}
		}
		int i;
		for (i = 0; i < R.size(); i++)
		{
			if (R[i].flag == 1)  //第一个只出现一次
			{
				cout << R[i].c << endl;
				break;
			}
		}
		if (i == R.size())
			cout << -1 << endl;
		R.clear();  //清空容器
	}
	return 0;
}
/*
	*找出字符串中第一个只出现一次的字符
*/

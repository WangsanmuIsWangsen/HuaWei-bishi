#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	int num = 0;  //记录数量
	string str;
	getline(cin, str);
	char C;
	cin >> C;
	for (int i = 0; i < str.size(); i++)  //全部转换为小写
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	if (C >= 'A'&&C <= 'Z') C = C - 'A' + 'a';
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == C) num++;
	}
	cout << num;
	return 0;
}
//由于牛客网测试的问题，如果在本地IDE跑需要稍微修改下代码，在cin>>C前面+getchar()
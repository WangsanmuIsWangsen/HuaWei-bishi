#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	int num = 0;  //��¼����
	string str;
	getline(cin, str);
	char C;
	cin >> C;
	for (int i = 0; i < str.size(); i++)  //ȫ��ת��ΪСд
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
//����ţ�������Ե����⣬����ڱ���IDE����Ҫ��΢�޸��´��룬��cin>>Cǰ��+getchar()
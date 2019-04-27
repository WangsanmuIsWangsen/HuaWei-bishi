#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int trans(string str);
int c_to_n(char c);
int main(void)
{
	string str;
	while (getline(cin, str))
	{
		int result = trans(str);
		cout << result << endl;
	}
	return 0;
}
int trans(string str)
{
	//reverse(str.begin(), str.end());
	int res = 0;
	char c;
	for (int i = 2; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')  //Ö±½Ó×ª»»
		{
			res = res * 16 + str[i] - '0';
		}
		else {  //×ÖÄ¸
			int tmp = c_to_n(str[i]);
			res = res * 16 + tmp;
		}
	}
	return res;
}
int c_to_n(char c)
{
	if (c >= 'a'&&c < 'z')
		return (c - 'a' + 10);
	else return (c - 'A' + 10);
}
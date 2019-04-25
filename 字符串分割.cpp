#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
string add_0(string str);
int main(void)
{
	vector<string > res;
	string str;
	while (getline(cin, str))  //得到一行字符串
	{
		if (str.size() <= 8)
		{
			str = add_0(str);
			res.push_back(str);
		}
		else {  //string长度>8
			string tmp;
			for (int i = 0; i < str.size(); i = i + 8)
			{
				tmp = str.substr(i, 8);
				if (tmp.size() < 8)
				{
					tmp = add_0(tmp);
					res.push_back(tmp);
				}
				else if (tmp.size() == 8)
					res.push_back(tmp);
			}
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}
string add_0(string str)
{
	for (;;)
	{
		if (str.size() == 8) break;
		else str += '0';
	}
	return str;
}

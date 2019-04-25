#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	string str;
	while (getline(cin, str))
	{
		int len = 0;  //¼ÇÂ¼³¤¶È
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ') len++;
			else break;
		}
		cout << len << endl;
	}
	return 0;
}

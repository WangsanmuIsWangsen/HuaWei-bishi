#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	string str1, str2;  //两个26进制的数
	cin >> str1;
	cin >> str2;
	vector<int> Int1, Int2, res;
	for (int i = str1.length()-1; i >= 0; i--)
	{
		Int1.push_back(str1[i] - 'a');
		if (i == 0) Int1.push_back(0);
	}
	for (int i = str2.length()-1; i >= 0; i--)
	{
		Int2.push_back(str2[i] - 'a');
		if (i == 0) Int2.push_back(0);
	}
	int JW = 0;
	if (Int1.size() >= Int2.size())
	{
		int i;
		for (i = 0; i < Int2.size(); i++)
		{
			res.push_back((Int1[i] + Int2[i] + JW) % 26);
			JW = (Int1[i] + Int2[i] + JW) / 26;
		}
		if (Int1.size() > i)
		{
			for (; i < Int1.size(); i++)
			{
				res.push_back((Int1[i] + JW) % 26);
				JW = (Int1[i] + JW) / 26;
			}
		}
	}
	else {
		int i;
		for (i = 0; i < Int1.size(); i++)
		{
			res.push_back((Int1[i] + Int2[i] + JW) % 26);
			JW = (Int1[i] + Int2[i] + JW) / 26;
		}
		if (Int2.size() > i)
		{
			for (; i < Int2.size(); i++)
			{
				res.push_back((Int2[i] + JW) % 26);
				JW = (Int2[i] + JW) / 26;
			}
		}
	}
	reverse(res.begin(), res.end());
	if (res[0] == 0) res.erase(res.begin());
	string result = "";
	char tmp;
	for (int i = 0; i < res.size(); i++)
	{
		tmp = res[i] + 'a';
		result = result + tmp;
	}
	cout << result;
	return 0;
}

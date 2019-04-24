#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(void)
{
	string input1, input2;
	cin >> input1;
	cin >> input2;
	if (input1.size() < 5 || input2.size() < 5 || input1.size() <= input2.size())
		return 0;
	int *ZM = new int[26];  //��¼26��ĸ  //flag
	for (int i = 0; i < 26; i++)
		ZM[i] = 0;
	for (int i = 0; i < input1.size(); i++)
	{
		int tmp;
		tmp = input1[i] - 'A';
		if (ZM[tmp] == 1) continue;
		else ZM[tmp] = 1;  //�����
	}
	int i;
	for (i = 0; i < input2.size(); i++)
	{
		int tmp;
		tmp = input2[i] - 'A';
		if (ZM[tmp] == 1) continue;
		else {
			printf("false");
			return 0;
		}
	}
	if (i == input2.size()) printf("true");
	return 0;
}
/*
   *���������ַ���input1��input2������input1�ĳ��ȴ���input2��Ҫ�����������ַ�input1��input2�ĳ��Ȳ�С��5��
   *���input2��ȫ����ĸ��������input1����ô����true�����򷵻�false��
*/
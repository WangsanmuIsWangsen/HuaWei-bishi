#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
string getResult(long uIDataInput);
string num_to_str(int num);
//bool isZhi(long num);
int main(void)
{
	long uIDataInput;
	cin >> uIDataInput;
	string res = "";
	res = getResult(uIDataInput);
	cout << res;
	return 0;
}

string getResult(long uIDataInput)
{
	string res = "";
	int i;
	for (i = 2; i <= uIDataInput; i++)
	{
		if (/*isZhi(i) &&*/uIDataInput%i == 0)
		{
			res = res + num_to_str(i) + " ";
			uIDataInput /= i;
			if (uIDataInput == 1) break;
			i = 1;
		}
	}
	return res;
}
/*
bool isZhi(long num)
{
	for (int i = 2; i < num/2; i++)
	{
		if (num%i == 0) return false;  //��������
	}
	return true;
}
*/
string num_to_str(int num)
{
	string result = "";
	char c;
	while (num)
	{
		c = num % 10 + '0';
		num = num / 10;
		result += c;
	}
	reverse(result.begin(), result.end());
	return result;
}
/*
   * �տ�ʼд��ʱ���Ǽ���ע�͵����ݣ���������ͨ��90%��˵�ǳ�������ʱ�䣬�ҾͿ����´�ҵ����������ָ������ÿ���
   * �����ǲ�����������Ϊ�Ǵ�С���������ܳ�ż����һ�����ȳ���������
*/
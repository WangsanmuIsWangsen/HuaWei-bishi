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
		for (int i = 0; i < str.length(); i++)  //����string
		{
			int j;
			for (j = 0; j < R.size(); j++)
			{
				if (R[j].c == str[i])  //����Ѿ�����
				{
					R[j].flag++;
					break;
				}
			}
			if (j == R.size())  //��������
			{
				tmp.c = str[i];
				tmp.flag = 1;
				R.push_back(tmp);
			}
		}
		int i;
		for (i = 0; i < R.size(); i++)
		{
			if (R[i].flag == 1)  //��һ��ֻ����һ��
			{
				cout << R[i].c << endl;
				break;
			}
		}
		if (i == R.size())
			cout << -1 << endl;
		R.clear();  //�������
	}
	return 0;
}
/*
	*�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
*/

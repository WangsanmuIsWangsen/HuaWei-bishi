#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	vector<int > arr;
	int begin = -1;  //�����������
	int tmp;
	while (cin >> tmp)
	{
		begin = tmp;
		int Tmp;
		for (int i = 0; i < begin; i++)
		{
			cin >> Tmp;
			if (find(arr.begin(), arr.end(), Tmp) == arr.end())  //�������ʧ��
			{
				arr.push_back(Tmp);
			}
		}
		sort(arr.begin(), arr.end());  //��С��������
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << endl;
		}
		begin = -1;
		arr.clear();
	}
	return 0;
}

//����find()����
//����ȽϿӵĵط����ж���������ݣ����Եý���һ�����ݺ������������ֿ�����
/*
	*�ַ�����ת
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(void)
{
	string str = "";
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str;
	}
	return 0;
}
/*
	*��С������
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int GBS(int a, int b);   //Ĭ��a>b
int main(void)
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a >= b) cout << GBS(a, b) << endl;
		else cout << GBS(b, a) << endl;
	}
	return 0;
}
int GBS(int a, int b)
{
	for (int i = 0;; i++)
	{
		if ((a + a * i) % a == 0 && (a + a * i) % b == 0)
			return (a + a * i);
	}
}


/*
	*��С������
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
bool IsDouble(string str);
bool isC(string str);
int main(void)
{
	vector<string> result;
	string str;
	while (cin >> str)
	{
		if (str.length() % 2 == 1)  //���������
			result.push_back("false");
		else {   //ż��
			if (IsDouble(str))
			{
				if (isC(str))
				{
					string res = "";
					for (int i = 0; i < str.length(); i = i + 2)
					{
						res += str[i];
					}
					result.push_back(res);
				}
				else result.push_back("false");
			}
			else result.push_back("false");
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
bool IsDouble(string str)
{
	string tmp = str;
	reverse(str.begin(), str.end());  //��ת�ַ���
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] != tmp[i])
			return false;
	}
	if (i == str.length()) return true;
	else return false;
}
bool isC(string str) {
	int i;
	for (i = 0; i < str.length(); i = i + 2)
	{
		if (str[i] != str[i + 1]) return false;
		else continue;
	}
	if (i == str.length()) return true;
	else return false;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(void)
{
	vector<int> res;  //���
	string number[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };  //�±��Ӧ����
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z') //����Ǵ�д��ĸ,ת��ΪСд��ĸ
				str[i] = str[i] - ('A' - 'a');
		}
		string tmp = "";  //������ȡ�ַ���
		for (int i = 0; i < str.length(); i++)
		{
			tmp += str[i];
			for (int j = 0; j < 10; j++)
			{
				if (number[j] == tmp)
				{
					res.push_back(j);
					tmp = "";
					break;
				}
			}
			//tmp = "";
		}
		for (int i = 0; i < res.size(); i++)
			cout << res[i];
		res.clear();
	}
	return 0;
}


#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
//ʹ�ö�ά����
void D_find(int **arr, int N, int yuan, int mudi, int num, int all);
int MinMoney = 99999;
int main(void)
{
	int N, M;
	cin >> N >> M;
	int **Node;
	Node = new int*[N];
	//int **Node = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		Node[i] = new int[N];
		//*Node = (int *)malloc(N * sizeof(int));
	}
	for (int i = 0; i < N; i++)    //��ʼ����0��ʾĿ�ĵؾ��Ǳ���-1��ʾ���ɴ�
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) Node[i][j] = 0;
			else Node[i][j] = -1;
		}
	}
	int xuhao, n1, n2, val;
	for (int i = 0; i < M; i++)
	{
		cin >> xuhao >> n1 >> n2 >> val;
		Node[n1 - 1][n2 - 1] = val;
		Node[n2 - 1][n1 - 1] = val;  //����ͼ
	}
	int shifa, mudi;
	cin >> shifa >> mudi;
	D_find(Node, N, shifa - 1, mudi - 1, 1, 0);
	cout << MinMoney;
	return 0;
}
void D_find(int **arr, int N, int yuan, int mudi, int num, int all)
{
	if (yuan == mudi)  //˵���ҵ����յ�
	{
		if (all < MinMoney) MinMoney = all;
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[yuan][i] == -1 || yuan >= i) continue;  //������ɴ����Դ<i
		else {
			if (num == 1) D_find(arr, N, i, mudi, num + 1, all + arr[yuan][i]);
			else D_find(arr, N, i, mudi, num + 1, all + arr[yuan][i] - 1);  //����
		}
	}
}

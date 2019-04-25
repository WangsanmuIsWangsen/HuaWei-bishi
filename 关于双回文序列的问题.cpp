#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
//使用二维数组
void D_find(int **arr, int N, int yuan, int mudi, int num, int all);
int MinMoney = 9999999;
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
	for (int i = 0; i < N; i++)    //初始化，0表示目的地就是本身，-1表示不可达
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
		Node[n2 - 1][n1 - 1] = val;  //无向图
	}
	int shifa, mudi;
	cin >> shifa >> mudi;
	D_find(Node, N, shifa - 1, mudi - 1, 1, 0);
	cout << MinMoney;
	return 0;
}
void D_find(int **arr, int N, int yuan, int mudi, int num, int all)
{
	if (yuan == mudi)  //说明找到了终点
	{
		if (all < MinMoney) MinMoney = all;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (num == 1)
		{
			if (arr[yuan][i] == -1 || yuan == i) continue;  //如果不可达或者源<i
			else D_find(arr, N, i, mudi, num + 1, all + arr[yuan][i]);  //第一次
		}
		else {
			if (arr[yuan][i] == -1 || yuan >= i) continue;
			else D_find(arr, N, i, mudi, num + 1, all + arr[yuan][i] - 1);  //连乘
		}
	}
}
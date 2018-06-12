#include<iostream>
#include<string>
using namespace std;

int col[10001];

//인덱싱이 모호하게 되었음. 배열은 0~n-1이지만 노드는 1~n이기 때문에
// 직관적으로 보기가 힘듦.

bool promising(int node,int n,int W[][4])  //node : 노드의 번호 1~n;
{
	if (node <= 1)
		return true;

	for (int i = 0; i <n ; i++)
		if (W[node - 1][i] == true)
		{	
			if(i+1<node)
				if (col[i + 1] == col[node])
					return false;
		}

	return true;
}

void Color(int i, int n, int m, int W[][4])//색은 0~ m-1, 노드는 1~n;
{
	if (promising(i,n,W))
		if (i == n)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << "번쨰 노드의 색 :" << col[i] << endl;
			}
			cout << endl;
		}
		else
		{
			for (int k = 0; k < m; k++)
			{
				col[i + 1] = k;
				Color(i + 1, n, m, W);
			}
		}
}

int main()
{
	int W[4][4] = { {false,true,true,true},{true,false,true,false },{true,true,false,true},{true,false,true,false} };
	Color(0, 4, 3, W);
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int col[10001];

//�ε����� ��ȣ�ϰ� �Ǿ���. �迭�� 0~n-1������ ���� 1~n�̱� ������
// ���������� ���Ⱑ ����.

bool promising(int node,int n,int W[][4])  //node : ����� ��ȣ 1~n;
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

void Color(int i, int n, int m, int W[][4])//���� 0~ m-1, ���� 1~n;
{
	if (promising(i,n,W))
		if (i == n)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << "���� ����� �� :" << col[i] << endl;
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
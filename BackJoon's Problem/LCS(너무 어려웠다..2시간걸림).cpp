//���� LCS
//LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������
//�־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
//
//���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else return b;
	
}

int main()
{
	char A[1000];
	char B[1000];

	int **DP;
	DP = new int*[1001];
	
	for (int i = 0; i < 1001; i++)
		DP[i] = new int[1001];
	
	cin >> A;
	cin >> B;

	int Alen = strlen(A);
	int Blen = strlen(B);

	for (int i = 0; i < Alen; i++)
	{
		for (int j = 0; j < Blen; j++)
		{
			
			if (A[i] == B[j])
			{
				if (i == 0)
					DP[i][j] = 1;
				else if (j == 0)
					DP[i][j] = 1;
				else DP[i][j] = MAX(DP[i][j-1],(DP[i - 1][j - 1] + 1));
			}
			else {
				if (i == 0 && j == 0)
					DP[i][j] = 0;
				else if (j == 0)
				{
					DP[i][j] = DP[i - 1][j];
				}
				else if (i == 0)
					DP[i][j] = DP[i][j - 1];
				 else DP[i][j] = MAX(DP[i - 1][j-1], MAX(DP[i-1][j],DP[i][j - 1]));
			}
		}
	}
	cout << DP[Alen - 1][Blen - 1];
	system("pause");
	return 0;
}
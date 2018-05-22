#include<iostream>
using namespace std;

int Brg[30][30];

void Bridge(int N, int M)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (i == j)
				Brg[i][j] = 1;
			else if (i == 1)
			{	
				Brg[i][j] = j;
			}
			else
			{	
				Brg[i][j] = 0;
				for (int k = 1; j - k >= i - 1; k++)
					Brg[i][j] += Brg[i - 1][j - k];
			}

		}

	cout << Brg[N][M] << endl;
}

int main()
{
	int n;
	int **arr;
	cin >> n;
	arr = new int*[n];


	for (int i = 0; i < n; i++)
		arr[i] = new int[2];
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
	for (int i = 0; i < n; i++)
	{
		Bridge(arr[i][0], arr[i][1]);
	}
	system("pause");
	return 0;
}
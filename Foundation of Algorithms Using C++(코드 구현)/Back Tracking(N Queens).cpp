#include<iostream>
#include<cmath>
using namespace std;

static int scount = 0;

bool Promising(int i,int *col)
{
	if (i <= 1)
		return true;

	for (int k = 1; k < i; k++)
		if (col[k] == col[i] || (abs(col[i] - col[k]) == abs(k - i)))
			return false;

	return true;
}

void Queens(int i, int n,int *col)
{
	if (Promising(i,col))
		if (i == n)
		{
			scount++;
			cout << "---- N Queens 행별 Queen 의 위치---- " << endl;
			
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (j == col[i] - 1)
					{
						cout << " O ";
					}
					else {
						cout << " * ";
					}
				}
				cout << endl;
			}
			cout << endl;
			return;
		}
		else
			for (int j = 1; j <= n; j++)
			{
				col[i + 1] = j;
				Queens(i + 1, n, col);
			}

}


int main()
{
	int n;
	cout << "체스판 열의 갯수 입력 ";
	cin >> n;
	int *arr;
	arr = new int[n + 1];
	Queens(0, n, arr);
	cout << endl << scount;
	system("pause");
	return 0;
}

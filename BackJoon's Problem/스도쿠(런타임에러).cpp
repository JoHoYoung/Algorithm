#include<iostream>
using namespace std;

int N;
int Zeros[1000];
int Arr[1000];
int pivot[13] = { 0,3,6,27,30,33,54,57,60,100,100,100,100};
static int clear = false;

bool Promising(int n)	
{
	if (!clear)
	{
		if (n < 0)
			return true;

		int row = Zeros[n] / 9;
		int col = Zeros[n] % 9;

		int min = 1000;
		int p;

		for (int i = n + 1; i < N; i++)
			Arr[Zeros[i]] = 0;
		
		for (int i = 0; i < 9; i++)
		{
			if (Zeros[n] >= pivot[i])
				if ((Zeros[n] - pivot[i]) < min && (pivot[i] % 9) <= col && (pivot[i] / 9) <= row)
				{
					min = Zeros[n] - pivot[i];
					p = i;
				}
		}
		
		for (int i = pivot[p]; i < pivot[p] + 3; i++)
		{

			if (i != Zeros[n] && Arr[i] == Arr[Zeros[n]])
			{
				//	cout << "1펄스";
				//	cout << " 처음꺼 " << Arr[i] << " 두번째 것 " << Arr[Zeros[n]] << endl;
				return false;
			}
		}

		for (int i = pivot[p] + 9; i < pivot[p] + 12; i++)
		{
			if (i != Zeros[n] && Arr[i] == Arr[Zeros[n]])
			{
				//	cout << "2펄스";
				//	cout << " 처음꺼 " << Arr[i] << " 두번째 것 " << Arr[Zeros[n]] << endl;
				return false;
			}
		}

		for (int i = pivot[p] + 18; i < pivot[p] + 21; i++)
		{
			if (i != Zeros[n] && Arr[i] == Arr[Zeros[n]])
			{
				//	cout << "3펄스";
				//	cout << " 처음꺼 " << Arr[i] << " 두번째 것 " << Arr[Zeros[n]] << endl;
				return false;
			}
		}

		for (int i = col; i < (72 + col); i += 9)		//열검사
		{
			if (i != Zeros[n] && Arr[i] == Arr[Zeros[n]])
			{
				return false;
			}

		}

		for (int j = row * 9; j <= row * 9 + 8; j++)  //행검사
		{
			if (j != Zeros[n] && Arr[j] == Arr[Zeros[n]])
			{
				return false;
			}
		}

		return true;
	}
	return false;
}

void Sdoku(int n)
{
	if (!clear)
	{//cout << endl << "**********************" << n << "층**********************" << endl;
		if (Promising(n))
		{
			if (n == N - 1)
			{
				clear = true;
				cout << endl;
				int k = 0;
				for (int i = 0; i < 81; i++)
				{

					cout << Arr[i] << " ";

					k++;
					if (k == 9)
					{
						cout << endl;
						k = 0;
					}
				}

			}
			else {
				for (int i = 1; i <= 9; i++)
				{
					Arr[Zeros[n + 1]] = i;
					Sdoku(n + 1);
				}
			}
		}
	}
}

int main()
{
	int dex = 0;

	for (int i = 0; i < 81; i++)
	{
		cin >> Arr[i];
		if (Arr[i] == 0)
			Zeros[dex++] = i;

	}
	N = dex;               //dex개의 0가 있다.
	//cout << N << "ZZ" << endl;
	Sdoku(-1);
	system("pause");
	return 1;
}
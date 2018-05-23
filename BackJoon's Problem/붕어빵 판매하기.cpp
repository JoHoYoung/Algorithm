#include<iostream>
using namespace std;

int main()
{
	int F[10000];
	int n;
	int max = INT_MIN;
	F[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> F[i];

	for (int k = 2; k <= n; k++)
	{
		for (int i = 0;i<=k; i++)
		{
			if (max < F[k - i] + F[i])
			{
				max = F[k - i] + F[i];
			}
		}
		F[k] = max;
	}
	cout << F[n];
	system("pause");
}
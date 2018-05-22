#include<iostream>
using namespace std;

int main()
{
	int test;
	int MAXNUM = 0;
	int INDEX = 0;
	cin >> test;
	int *arr = new int[test];
	
	for (int i = 0; i < test; i++)
	{
		cin >> arr[i];
		if (arr[i] > MAXNUM)
			MAXNUM = arr[i];
	}
	int *COUNT = new int[MAXNUM+1];
	for (int i = 0; i < MAXNUM+1; i++)
		COUNT[i] = -1;

	for (int i = 0; i < test; i++)
	{
		COUNT[arr[i]]++;
	}
	for (int i = 0; i <= MAXNUM; i++)
	{
		for (int j = COUNT[i]; j >= 0; j--)
			arr[INDEX++] = i;
	}
	for (int i = 0; i < test; i++)
		cout << arr[i] <<endl;

	system("pause");
}
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int MaxDex(int *arr, int n)
{
	int temp = -10000;
	int tempdex;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			tempdex = i;
		}
	}
	return tempdex;
}

void ResetArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;

}

int main()
{
	int Count[25];
	int HD = 0;

	int N, M;
	cin >> N >> M;
	
	char **arr;
	arr = new char*[N];
	
	char *result = new char[M];
	result[M] = NULL;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		cin >> arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ResetArr(Count, 26);
		
		for (int j = 0; j < N; j++)
		{
			Count[(int)(arr[j][i] - 'A')]++;
		}
		result[i] = (char)(MaxDex(Count, 26) + 'A');
		HD +=N- Count[MaxDex(Count, 26)];
	}
	cout << result << endl << HD;
	system("pause");
	return 0;
}
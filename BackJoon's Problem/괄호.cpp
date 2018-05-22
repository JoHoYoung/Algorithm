#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

int Pairnum = 0;
int main()
{
	int num;
	cin >> num;
	char **arr;
	arr = new char*[num];
	for (int i = 0; i < num; i++)
		arr[i] = new char[50];

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; arr[i][j] != NULL; j++)
		{
			if (arr[i][j] == '(')
				Pairnum++;
			else if (arr[i][j] == ')')
				Pairnum--;

		}
		if (Pairnum == 0)
			cout << "YES"<<endl;
		else cout << "NO" << endl;

		Pairnum = 0;

	}

	return 0;
	system("pause");

}
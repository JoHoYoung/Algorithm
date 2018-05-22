#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;

int main()
{
	int head, rear;
	int sum = 0;
	int min = INT_MAX;
	bool tt = false;

	cin >> head >> rear;


	for (int i = head; i <= rear; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if ((i%j) == 0)
			{
				tt = true;
				break;
			}
		}
		if (tt == false)
			cout << i<<endl;
		else tt = false;
	}

	system("pause");
	return 0;
}
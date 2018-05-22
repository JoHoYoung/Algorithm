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

	cin >> head;
	cin >> rear;


	for (int i = head; i <= rear; i++)
	{
		if (i == 1)
			tt = true;

		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				tt = true;
				break;
			}
		}
		if (tt == false)
		{
			sum += i;

			if (i < min)
				min = i;
		}
		tt = false;
		
	}
	if (sum == 0)
		cout << "-1";
	else cout << sum << endl << min << endl;
	system("pause");
	return 0;
}
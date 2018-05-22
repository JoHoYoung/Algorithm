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
		for (int j = 2; j < i; j++)
		{
			if (i % j) == 0)
			{	
				tt = true;
					break;
			}
		}

		if (tt == true)
		{
			tt = false;
			break;
		}
		sum += temp[i];

		if (temp[i] < min)
			min = temp[i];
	}
	
	cout << sum << endl << min;
	cout << "½Ã¹ß";
	system("pause");
	return 0;
}
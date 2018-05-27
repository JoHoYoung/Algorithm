//문제 1929
//M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

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
	cout << "시발";
	system("pause");
	return 0;
}
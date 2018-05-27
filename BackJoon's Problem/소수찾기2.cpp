//문제 2581
//
//자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인
//것을 모두 골라 이들 소수의 합과 최소값을 찾는 프로그램을 작성하시오.
//
//예를 들어 M = 60, N = 100인 경우 60이상 100이하의 자연수
//중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이
//들 소수의 합은 620이고, 최소값은 61이 된다.

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
//문제 9095번
//정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//2 + 1 + 1
//2 + 2
//1 + 3
//3 + 1
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include<algorithm>
using namespace std;

int fact(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	return n * fact(n - 1);
}

int main()
{
	int CaseNum;
	int Testnum[100];
	cin >> CaseNum;
	for (int i = 0; i < CaseNum; i++)
		cin >> Testnum[i];

	
	for (int i = 0; i < CaseNum; i++)
	{
		int count = 0;
		int count1 = -1;
		int count2 = -1;
		int count3 = -1;

		int P = Testnum[i];

		for (int n1 = P; n1 >= 0; n1 = n1 - 3)
		{
			count3++;
			count2 = -1;
			for (int n2 = n1; n2 >= 0; n2 = n2 - 2)
			{
				count2++;
				count1 = P - 3 * count3 - 2 * count2;
				count += fact(count3+count2+count1)/(fact(count3)*fact(count2)*fact(count1));
			}
		}
		cout << count << endl;
		
	}
	
	system("pause");
	return 0;

}
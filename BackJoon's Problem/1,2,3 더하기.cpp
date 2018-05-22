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
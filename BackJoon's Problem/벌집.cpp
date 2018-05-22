#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	if (num == 1)
		cout << 1;
	if(num>1)
	{
		for (int i = 1; i < 10000000; i++)
		{
			if (3 * i*(i - 1) + 1 < num&&num <= 3 * i*(i + 1) + 1)
			{
				cout << i + 1;
				break;
			}
		}
	system("pause");
}
#include<iostream>
using namespace std;

int spacefact(int n)
{
	int k = n / 2;
	k += 1;

	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	else {
		return spacefact(n - 2) + spacefact(n - 1);
	}
}

int main()
{
	int num1;
	int num2;
	int interval;
    cin >> num1;
	cin >> num2;
	interval = num2 - num1;
	for (int i = 3; i < 100; i++)
	{
		if (spacefact(i) < interval&&interval <= spacefact(i + 1))
		{
			cout << "½Ã¹ß" << endl;
			cout << i+1;
			break;
		}
	}
	system("pause");
}
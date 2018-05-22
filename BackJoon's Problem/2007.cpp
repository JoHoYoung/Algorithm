#include<iostream>
#include<string>
using namespace std;

int main()
{
	int Month, Day;
	int	 SumofDays = 0;
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	cin >> Month >> Day;

	SumofDays += Day;
	for (int i = 1; i<Month; i++)
	{
		SumofDays += arr[i];
	}
	SumofDays= SumofDays % 7;
	switch (SumofDays)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	}
	system("pause");
}
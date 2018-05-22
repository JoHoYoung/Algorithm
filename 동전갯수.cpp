#include <iostream>
using namespace std;

int main()
{
	int  NumofCoin;
	int Price;
	int Coin[10];
	int count = 0;
	cin >> NumofCoin >> Price;
	
	for (int i = 0; i < NumofCoin; i++)
		cin >> Coin[i];

	for (int n = NumofCoin - 1; n >= 0; n--)
	{
		if (Price >=Coin[n])
		{
			count += (Price / Coin[n]);
			Price = Price % Coin[n];
		}
	}
	cout << count;
	return 0;

}
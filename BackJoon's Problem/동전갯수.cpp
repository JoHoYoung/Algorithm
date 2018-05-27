//문제 11047
//준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
//
//동전을 적절히 사용해서 그 가치의 합을 K로 만드려고 한다.
//이 때 필요한 동전 개수의 최소값을 구하는 프로그램을 작성하시오.

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
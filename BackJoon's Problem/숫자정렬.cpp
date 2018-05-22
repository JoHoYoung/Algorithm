#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int buffer[10];
	int dex = 0;
	while (1)
	{
		buffer[dex++] = num % 10;
		num = num / 10;
		if (num == 0)
			break;

	}
	sort(buffer, buffer + dex);

	for (int i = dex-1; i >= 0; i--)
		cout << buffer[i];

	return 0;

}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	char Input[100000];
	cin >> Input;
	int leng = strlen(Input);

	int sum = 0;
	bool has0 = false;
	
	for (int i = 0; i < leng; i++)
	{
		if (Input[i] - '0' == 0)
			has0 = true;

		sum += Input[i] - '0';
	
	}

	if (sum % 3 == 0 && has0)
	{
		sort(Input, Input + leng, desc);
	
		for (int i = 0; i < leng; i++)
			cout << Input[i];
	}
	else cout << -1;

	system("pause");
}
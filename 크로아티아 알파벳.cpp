#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char input[100];
	int count = 0;
	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		switch (input[i])
		{
		case 'c':
			if (input[i + 1] == '=')
			{
				count += 1;
				i += 1;
			}
			else if (input[i + 1] == '-') {
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		case 'd':
			if (input[i + 1] == 'z')
			{
				if (input[i + 2] == '=')
				{
					count += 1;
					i += 2;
				}
			}
			else if (input[i + 1] == '-')
			{
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		case 'l':
			if (input[i + 1] == 'j')
			{
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		case 'n':
			if (input[i + 1] == 'j')
			{
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		case 's':
			if (input[i + 1] == '=')
			{
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		case 'z':
			if (input[i + 1] == '=')
			{
				count += 1;
				i += 1;
			}
			else count += 1;
			break;
		default: count += 1;
			break;
		}

	}
	cout << count;
	system("pause");
}
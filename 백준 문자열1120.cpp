#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	char Input1[50];
	char Input2[50];
	cin >> Input1;
	cin >> Input2;
	int leng1 = strlen(Input1);
	int leng2 = strlen(Input2);
	
	int count = leng2 - leng1;
	int result = INT_MAX;
	
	int redex, tempredex;
	int tempresult;
	for (int i = 0; i <= count; i++)
	{
		int samecount = 0;

		for (int j = 0; j < leng1; j++)
		{
			if (Input2[j + i] == Input1[j])
			{
				samecount++;
			}
			tempredex = j;
		}
		tempresult = leng1 - samecount;
		
		if (result > tempresult)
		{
			result = tempresult;
			redex = tempredex;
		}
	}
	char temparr[50];

	for (int i = 0; i < leng2; i++)
	{
		temparr[i] = Input2[i];
	}

	for (int j = redex, i = 0; i < leng1; j++, i++)
	{
		temparr[j] = Input1[i];
	}
	for (int i = 0; i < leng2; i++)
	{
		Input1[i] = temparr[i];
	}
	
	cout << result;
	system("pause");
	return 0;
}
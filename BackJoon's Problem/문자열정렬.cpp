#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
using namespace std;

int Apower(int a, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else if (n % 2)
		return Apower(a*a, n / 2)*a;
	else
		return Apower(a*a, n / 2);
}


class Hostring
{
public: string str;
public: int length;
public: int info = 0;
public: void operator =(char* temp)
{
	int len = strlen(temp);
	str = new char[len];
	length = len;
	for (int i = 0; i < len; i++)
		str[i] = temp[i];

	str[len] = NULL;
	
}

public: void Print()
{
	if (str != "-1")
	cout << str.c_str() << endl;
}
};

void HoSort(Hostring *arr, int num)
{
	string temp;
	int MaxLength;
	int MaxDex;
	for (int i = num - 1; i >= 0; i--)
	{
		MaxLength = -1;
		for (int j = 0; j <= i; j++)
		{
			if (arr[j].length>MaxLength)
			{
				MaxLength = arr[j].length;
				MaxDex = j;
			}
			else if (MaxLength == arr[j].length)
			{
				if (arr[MaxDex].str < arr[j].str)
					MaxDex = j;
			}
		}
		temp = arr[i].str;
		arr[i].str = arr[MaxDex].str;
		arr[MaxDex].str = temp;
		int templen = arr[i].length;
		arr[i].length = arr[MaxDex].length;
		arr[MaxDex].length = templen;

		
	}
	int pivotdex = 0;
	for (int i = 1; i < num; i++)
	{
		//cout << "���Ұ� : " << arr[pivotdex].str.c_str() << " " << "�񱳴��Ұ� : " << arr[i].str.c_str() << endl;

		if (arr[pivotdex].str.compare(0,arr[pivotdex].length,arr[i].str,0,arr[i].length) == 0)
		{
			arr[i].str = "-1";
		}
		else pivotdex = i;
		
	}
}

int main()
{
	int num;
	cin >> num;
	Hostring *ho = new Hostring[num];
	for (int i = 0; i < num; i++)
	{
	   char temp[100];
	   cin >> temp;
	   ho[i] = temp;
	}
	HoSort(ho, num);
	for (int i = 0; i < num; i++)
	   ho[i].Print();

	system("pause");
	return 0;
}
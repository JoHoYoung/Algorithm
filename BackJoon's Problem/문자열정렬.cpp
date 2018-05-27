//문제 1120번
//
//길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의
//차이는 X[i] != Y[i]인 i의 개수이다.예를 들어, X = ”jimin”, Y = ”minji”이면, 
//둘의 차이는 4이다.
//
//두 문자열 A와 B가 주어진다.이 때, A의 길이는 B의 길이보다 
//작거나 같다.자 이제 A의 길이가 B의 길이가 같아질 때 까지 
//다음과 같은 연산을 할 수 있다.
//
//A의 앞에 아무 알파벳이나 추가한다.
//A의 뒤에 아무 알파벳이나 추가한다.
//이 때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

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
		//cout << "비교할거 : " << arr[pivotdex].str.c_str() << " " << "비교당할거 : " << arr[i].str.c_str() << endl;

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
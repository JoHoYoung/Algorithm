//문제 1541
//세준이는 양수와 + , -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다.
//그리고 나서 세준이는 괄호를 모두 지웠다.
//
//그리고 나서 세준이는 괄호를 적절히 쳐서 
//이 식의 값을 최소로 만드려고 한다.
//
//괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

int Pairnum = 0;
int main()
{
	int num;
	cin >> num;
	char **arr;
	arr = new char*[num];
	for (int i = 0; i < num; i++)
		arr[i] = new char[50];

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; arr[i][j] != NULL; j++)
		{
			if (arr[i][j] == '(')
				Pairnum++;
			else if (arr[i][j] == ')')
				Pairnum--;

		}
		if (Pairnum == 0)
			cout << "YES"<<endl;
		else cout << "NO" << endl;

		Pairnum = 0;

	}

	return 0;
	system("pause");

}
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

int Stack[10000];
int StackDex = 0;

void push(int n)
{
	Stack[StackDex++] = n;
}

int pop()
{
	if (StackDex == 0)
		return -1;
	return Stack[--StackDex];
}

int size()
{
	return StackDex;
}

int empty()
{
	if (StackDex == 0)
		return 1;
	else return 0;
}

int top()
{
	if (StackDex == 0)
	return -1;
	else
	return Stack[StackDex - 1];
}
int result[10000];
int resultdex = 0;
int main()
{
	int casenum;
	int num;
	char str[10];
	cin >> casenum;
		
	for (int i = 0; i < casenum; i++)
	{cin >> str;
		if (!strcmp(str, "push"))
		{
			cin >> num;
			push(num);

		}
		else if (!strcmp(str, "top"))
			result[resultdex++]= top();
		else if (!strcmp(str, "size"))
			result[resultdex++] = size();
		else if (!strcmp(str, "empty"))
			result[resultdex++] = empty();
		else if (!strcmp(str,"pop"))
			result[resultdex++] = pop() ;
	}

	for (int i = 0; i < resultdex; i++)
		cout << result[i] << endl;
	system("pause");
}
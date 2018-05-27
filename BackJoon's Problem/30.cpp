//문제 10610번
//어느날, 미르코는 우연히 길거리에서 양수 N을 보았다.
//미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 
//포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
//미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라. (그 수가 존재한다면)

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
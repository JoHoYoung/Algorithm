//문제 1193번
//이와 같이 나열된 분수들을 1
/// 1 -> 1 / 2 -> 2 / 1 -> 3 / 1 -> 2 / 2->… 과 같은 순서로 
//차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
//
//X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.


#include<iostream>
using namesapce std;

int spacefact(int n)
{
	int k = n / 2;
	k += 1;
	
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	else {
		return spacefact(n - 2) + spacefact(n - 1);
	}
}

int main()
{
	int num1;
	int num2;
	int interval;

	cin >> num1;
	cin >> num2;
	interval = num1 - num2;

	for (int i = 0; i < 100; i++)
	{
		if (spacefact(i) < interval&&spacefact(i + 1) <= interval)
			cout << i;
    }
	system("pause");
}
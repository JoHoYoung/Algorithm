//문제 1463번
//정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
//
//X가 3으로 나누어 떨어지면, 3으로 나눈다.
//X가 2로 나누어 떨어지면, 2로 나눈다.
//1을 뺀다.
//정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 
//사용해서 1을 만들려고 한다.연산을 사용하는 횟수의 최소값을 출력하시오.

#include <iostream>
using namespace std;

int F[1000000];

int min(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	else return n2;
}

int main()
{
	int n; cin >> n;
	F[1] = 0;
	for (int i = 2; i <= n; i++) {
		F[i] = i;
		if (i % 3 == 0) {
			F[i] = min(F[i], F[i / 3] + 1);
		}
		if (i % 2 == 0) {
			F[i] = min(F[i], F[i / 2] + 1);
		}
		F[i] = min(F[i], F[i - 1] + 1);
	}
	cout << F[n];
	system("pause");
	return 0;

}
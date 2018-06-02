//문제 1309
//이 동물원에는 사자들이 살고 있는데 사자들을 우리에 가둘 때, 가로로도 세로로도 붙어 있게
//배치할 수는 없다.이 동물원 조련사는 사자들의 배치 문제 때문에 골머리를 앓고 있다.
//
//동물원 조련사의 머리가 아프지 않도록 우리가 2 * N 배열에 사자를 배치하는 경우의 수가 
//몇 가지인지를 알아내는 프로그램을 작성해 주도록 하자.사자를 한 마리도 배치하지 않는 경우도
//하나의 경우의 수로 친다고 가정한다.

#include<iostream>
using namespace std;

int DP[100003][3];

int Lion(int Space, int num)
{
	if (Space == 0)
	{
		DP[Space][num] = 1;
		return DP[Space][num];
	}
	if (DP[Space][num] != 0)
		return DP[Space][num];
	else {
		if (num == 0)
		DP[Space][num] = (Lion(Space-1,0) + Lion(Space-1,1)+ Lion(Space - 1, 2))%9901;
		else if (num == 1)
		DP[Space][num] = (Lion(Space - 1, 0) + Lion(Space - 1, 2))%9901;
		else if (num == 2)
		DP[Space][num] =( Lion(Space - 1, 0) + Lion(Space - 1, 1))%9901;
		}

	return DP[Space][num];
}

int main()
{
	int N;
	cin >> N;
	int result;
	memset(DP, 0, sizeof(DP));
	result = Lion(N-1, 0) + Lion(N-1, 1) + Lion(N-1, 2);
	cout << result%9901;

	system("pause");
	return 0;
}
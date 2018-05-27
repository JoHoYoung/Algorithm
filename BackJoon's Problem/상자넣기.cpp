//문제 1965번
//정육면체 모양의 상자들이 일렬로 늘어서 있다.상자들마다 크기가 주어져 있는데, 앞에 있는 상자의 크기가 뒤에 있는 
//상자의 크기보다 작으면, 앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수가 있다.
//예를 들어 앞에서부터 순서대로 크기가(1, 5, 2, 3, 7)인 5개의 상자가 있다면, 
//크기 1인 상자를 크기 5인 상자에 넣고, 다시 이 상자들을 크기 7인 상자 안에 넣을 수 있다.
//하지만 이렇게 상자를 넣을 수 있는 방법은 여러 가지가 있을 수 있다.
//앞의 예에서 차례대로 크기가 1, 2, 3, 7인 상자들을 선택하면 총 4개의 상자가 한 개의 상자에 들어가게 된다.
//상자들의 크기가 주어질 때, 한 번에 넣을 수 있는 최대의 상자 개수를 출력하는 프로그램을 작성하시오.

#include<iostream>
using namespace std;

int main()
{
	int Num;
	cin >> Num;
	
	int *arr,*P;
	arr = new int[Num];
	P = new int[Num];
	P[Num - 1] = 0;

	int count = 0;
	int tempmax = -10000;

	for (int i = 0; i < Num; i++)
		cin >> arr[i];
	
	for (int i = Num - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < Num; j++)
		{
			if (arr[j] > arr[i] && P[j] > tempmax)
			{
				tempmax = P[j];

			}
		}
		if (tempmax != -10000)
			P[i] = tempmax + 1;
		else P[i] = 0;

		tempmax = -10000;

	}
	for (int i = 0; i < Num; i++)
	{
		if (tempmax < P[i])
			tempmax = P[i];

	}
	cout << tempmax + 1;
	system("pause");
	return 0;
}
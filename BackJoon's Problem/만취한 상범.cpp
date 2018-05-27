// 문제 6359
//서강대학교 곤자가 기숙사의 지하에는 n개의 방이 일렬로 늘어선 감옥이 있다.
//각 방에는 벌점을 많이 받은 학생들이 구금되어있다.
//
//그러던 어느날, 감옥 간수인 상범이는 지루한 나머지 정신나간 게임을 하기로 결정했다
//.게임의 첫 번째 라운드에서 상범이는 위스키를 한 잔 들이키고, 
//달려가며 감옥을 한 개씩 모두 연다.그 다음 라운드에서는 2, 4, 6, ... 번 방을 
//다시 잠그고, 세 번째 라운드에서는 3, 6, 9, ... 번 방이 열려있으면 잠그고, 
//잠겨있다면 연다.같은 방식으로 n번의 라운드를 진행한 이후, 
//상범이는 위스키의 마지막 병을 마시고 쓰러져 잠든다.
//
//구금되어있는 몇 명(어쩌면 0명)의 학생들은 자신의 방을 잠그지 않은 
//채 상범이가 쓰러져버렸단 것을 깨닫고 즉시 도망친다.
//
//방의 개수가 주어졌을 때, 몇 명의 학생들이 도주할 수 있는지 알아보자.

#include<iostream>
using namespace std;

int main()
{
	int Num;
	cin >> Num;
	
	
	int *Case,*result;

	Case = new int[Num];
	result = new int[Num];

	for (int i = 0; i < Num; i++)
	{
		cin >> Case[i];
		result[i] = 0;
	}

	for (int k = 0; k < Num; k++)
	{
		int res[101];
		for (int i = 0; i < 101; i++)
			res[i] = 0;

		for (int i = 1; i <= Case[k]; i++)
		{
			for (int j = 1; i*j <= Case[k]; j++)
				res[i*j]++;
		}
		
		for (int i = 0; i <= Case[k]; i++)
			if (res[i] % 2 != 0)
				result[k]++;

	}
	for (int i = 0; i < Num; i++)
		cout << result[i] << endl;

	system("pause");
	return 0;
}
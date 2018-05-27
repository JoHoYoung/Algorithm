//문제 2262
//월드시에서는 매년 n명의 사람들이 모여 월드 크래프트라는 게임의 토너먼트 대회를 치른다.
//이 게임은 특성상 실력만이 승패를 좌우하기 때문에, 아무리 실력이 엇비슷한 사람이 시합을
//치러도 랭킹이 높은 사람이 반드시 이기게 된다.따라서 월드시에서는 게임을 흥미진진하게 
//만들기 위해서, 부전승을 여러 번 만들더라도 각 시합에 임하는 선수들의 랭킹 차이를 비슷하게
//만들려고 한다.
//
//토너먼트를 만들 때에는 이미 추첨이 된 순서대로 선수들을 배치하고, 왼쪽에서 오른쪽의
//순서가 어긋나지 않도록 시합을 정한다.물론 부전승을 임의로 만들 수 있지만, 토너먼트가 
//꼬여서는 안 된다.또한, 각 시합에 임하는 두 선수의 랭킹의 차이의 합이 최소가 되도록 하려 한다.
//
//예를 들어 추첨 결과가 차례로 랭킹 1, 6, 2, 5, 3, 4위의 선수들이었을 때의 토너먼트 세 개가 위에 있다.
//<A>의 경우는 각 시합이(1 6), (2 5), (3 4), (1 2), (1 3)으로 랭킹 차이의 합이 5 + 3 + 1 + 1 + 2 = 12
//가 된다.반면에 <B>는 11이, <C>는 10이 된다.
//
//토너먼트 추첨 결과가 주어졌을 때, 각 시합에 임하는 
//두 선수의 랭킹 차이의 총 합의 최소값을 구하는 프로그램을 작성하시오.

#include<iostream>
using namespace std;
#define abs(a,b) (a>b ? (a-b):(b-a))
#define min(a,b) (a>b ? b:a)
int w[500][500];
int save[500][500];

int HF(int head, int rear, int *arr)
{
	int result = 1000000;

	if (save[head][rear] && save[head][rear] != -1)
	{
		return save[head][rear];
	}

	if (head == rear)
	{
		save[head][rear] = 0;
		return 0;
	}

	if (head == rear - 1)
	{
		save[head][rear] = abs(arr[head], arr[rear]);
		return abs(arr[head], arr[rear]);
	}

	for (int i = 0; head + i < rear; i++)
	{
		result = min(result, abs(w[head][head + i], w[head + i + 1][rear]) + HF(head, head + i, arr) + HF(head + i + 1, rear, arr));
	}

	save[head][rear] = result;
	return save[head][rear];
}

int main()
{
	int Num;
	cin >> Num;
	int **D;
	int *arr;
	arr = new int[Num];

	for (int i = 0; i <= Num; i++)
		for (int j = 0; j <= Num; j++)
			save[i][j] = -1;

	for (int i = 0; i < Num; i++)
		cin >> arr[i];

	///////////////////////////////////////// 입력부분 끝 , 알고리즘 부분/////////////////////////////////////////////////
	for (int i = 0; i < Num; i++)
	{
		w[i][i] = arr[i];
		for (int j = i + 1; j < Num; j++)
		{
			w[i][j] = min(w[i][j - 1], arr[j]);

		}
	}

	cout << HF(0, Num - 1, arr);
	system("pause");
	return 0;
}
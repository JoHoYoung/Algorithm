//문제 2828
//상근이는 오락실에서 바구니를 옮기는 오래된 게임을 한다.
//스크린은 N칸으로 나누어져 있다.스크린의 아래쪽에는 M칸을
//차지하는 바구니가 있다. (M<N) 플레이어는 게임을 하는 중에
//	바구니를 왼쪽이나 오른쪽으로 이동할 수 있다.하지만, 바구
//	니는 스크린의 경계를 넘어가면 안된다.가장 처음에 바구니는
//	왼쪽 M칸을 차지하고 있다.
//
//스크린의 위에서 사과 여러 개가 떨어진다.각 사과는 N칸중 한 
//칸의 상단에서 떨어지기 시작하며, 스크린의 바닥에 닿을때까지 
//직선으로 떨어진다.한 사과가 바닥에 닿는 즉시, 다른 사과가 떨어지기 시작한다.
//
//바구니가 사과가 떨어지는 칸을 차지하고 있다면, 바구니는 그 
//사과가 바닥에 닿을 때, 사과를 담을 수 있다.상근이는 사과를 
//모두 담으려고 한다.이 때, 바구니의 이동 거리의 최솟값을 구하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

struct Bucket
{
	int head;
	int rear;
};

int main()
{
	int N, M;
	cin >> N;
	cin >> M;

	int result=0;

	Bucket Buck;
	Buck.head = 1;
	Buck.rear = M;

	int Apple;
	cin >> Apple;

	int *seq = new int[Apple];

	for (int i = 0; i < Apple; i++)
		cin >> seq[i];

	for (int i = 0; i < Apple; i++)
	{
		if (seq[i] > Buck.rear)
		{
			int temp = seq[i] - Buck.rear;
			result += seq[i] - Buck.rear;
			Buck.rear += temp;
			Buck.head += temp;
			if (Buck.rear > N)
			{
				result -= Buck.rear - N;
				Buck.head = N-M+1;
				Buck.rear = N;
			}
		}
		else if (seq[i] < Buck.head)
		{
			int temp = Buck.head - seq[i];
			result += Buck.head - seq[i];
			Buck.rear -= temp;
			Buck.head -= temp;

			if (Buck.head < 1)
			{
				result -= 1 - Buck.head;
				Buck.head = 1;
				Buck.rear = M;
			}
		}

	}
	cout << result;
	
	system("pause");
	return 0;
}
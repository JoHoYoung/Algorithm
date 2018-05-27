//문제11722
//수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 
//프로그램을 작성하시오.
//
//예를 들어, 수열 A = { 10, 30, 10, 20, 20, 10 } 인 경우에 가장
//긴 감소하는 부분 수열은 A = { 10, 30, 10, 20, 20, 10 }  이고, 길이는 3이다.

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int *arr, *count;
	arr = new int[N];
	count = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];												// 입력배열 받는 부분
		count[i] = 0;												// count배열 초기화 하는부분
	}
	
	int tempsum = 0;
	
	for (int i = N - 1; i >= 0; i--)
	{	
		int tempcount = -10000;								// 제일 큰 count를 추출하기위해 초기화

		for (int j = i+1; j < N; j++)							// 기준 i 부터 뒤에거 비교
		{
			if (arr[j] < arr[i]&&count[j]>tempcount)		// 뒤에거가 기준보다 작고, count보다 크면 
			{
				tempsum = count[j];							// 일시적으로 제일큰거 추출 // 루프 끝나면 제일 큰게 추출됨
				tempcount = count[j];							// 제일 큰 count 추출하기 위해 비교대상(temp카운트 초기화)
			}
		}
		if (tempcount != -10000)								// -10000이 아니라는건 비교대상보다 작은게 하나라도 있다는 의미
		count[i] += tempsum+1;								//	더하기 1		// 10000이면 처음에 초기화했던 0이 들어가는데
	}																					// 비교대상 i보다 작은게 하나도 없으니까 0이 들어가는게 맞음
	int max = -10000;
	for (int i = 0; i < N; i++)									// 만들어진 count들 중에 제일큰것 추출하기위함
	{
		if (count[i] > max)
			max = count[i];
	}
	cout << max+1;											//본인을 포함하니까 +1 해서 출력
	system("pause");
	return 0;
}
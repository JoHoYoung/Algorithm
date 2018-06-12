//문제 2212
//한국도로공사는 고속도로의 유비쿼터스화를 위해 고속도로 위에 N개의 센서를
//설치하였다.문제는 이 센서들이 수집한 자료들을 모으고 분석할 몇 개의 
//집중국을 세우는 일인데, 예산상의 문제로, 고속도로 위에 최대 K개의 집중국을 
//세울 수 있다고 한다.
//
//각 집중국은 센서의 수신 가능 영역을 조절할 수 있다.집중국의 수신 가능 
//영역은 고속도로 상에서 연결된 구간으로 나타나게 된다.N개의 센서가 적어
//도 하나의 집중국과는 통신이 가능해야 하며, 집중국의 유지비 문제로 인해 각
//집중국의 수신 가능 영역의 길이의 합을 최소화해야 한다.
//
//편의를 위해 고속도로는 평면상의 직선이라고 가정하고, 센서들은 이 직
//선 위의 한 기점인 원점으로부터의 정수 거리의 위치에 놓여 있다고 하자.따
//라서, 각 센서의 좌표는 정수 하나로 표현된다.이 상황에서 각 집중국의 수신 
//가능영역의 거리의 합의 최소값을 구하는 프로그램을 작성하시오.단, 집중국의
//수신 가능영역의 길이는 0 이상이며 모든 센서의 좌표가 다를 필요는 없다.

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{	
	int N, K;
	cin >> N >> K;

	int *arr = new int[N];
	int *interval = new int[N - 1];
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	for (int i = 1; i < N; i++)
		interval[i - 1] = arr[i] - arr[i - 1];

	sort(interval, interval + N - 1);

	for (int j = 0; j < N - K; j++)
		result += interval[j];

	cout << result;
	system("pause");
	return 0;
}
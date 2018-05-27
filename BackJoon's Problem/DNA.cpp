//문제 1969
//DNA란 어떤 유전물질을 구성하는 분자이다.이 DNA는 서로 다른 4가지의
//뉴클레오티드로 이루어져 있다(Adenine, Thymine, Guanine, Cytosine).우리
//는 어떤 DNA의 물질을 표현할 때, 이 DNA를 이루는 뉴클레오티드의 첫글
//자를 따서 표현한다.만약에 
//Thymine - Adenine - Adenine - Cytosine - Thymine - Guanine - Cytosine - Cytosine 
//- Guanine - Adenine - Thymine로 이루어진 DNA가 있다고 하면, 
//“TAACTGCCGAT”로 표현할 수 있다.그리고 Hamming Distance란 길이가 같은 
//두 DNA가 있을 때, 두 DNA의 차이를 표현하는 것이다.만약에 “AGCAT"와
//”GGAAT"는 첫 번째 글자와 세 번째 글자가 다르므로 Hamming Distance는 2이다.
//
//우리가 할 일은 다음과 같다.n개의 길이가 같은 DNA가 주어져 있을 때(
//이 DNA를 a1a2a3a4...이라고 하자) Hamming Distance의 합이 가장
//작은 DNA s를 구하는 것이다.즉, s와 a1의 Hamming Distance + 
//s와 a2의 Hamming Distance + s와 a3의 Hamming Distance ..
//. 의 합이 최소가 된다는 의미이다.

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int MaxDex(int *arr, int n)
{
	int temp = -10000;
	int tempdex;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			tempdex = i;
		}
	}
	return tempdex;
}

void ResetArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;

}

int main()
{
	int Count[25];
	int HD = 0;

	int N, M;
	cin >> N >> M;
	
	char **arr;
	arr = new char*[N];
	
	char *result = new char[M];
	result[M] = NULL;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		cin >> arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ResetArr(Count, 26);
		
		for (int j = 0; j < N; j++)
		{
			Count[(int)(arr[j][i] - 'A')]++;
		}
		result[i] = (char)(MaxDex(Count, 26) + 'A');
		HD +=N- Count[MaxDex(Count, 26)];
	}
	cout << result << endl << HD;
	system("pause");
	return 0;
}
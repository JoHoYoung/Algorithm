//문제 2108
//
//수를 처리하는 것은 통계학에서 상당히 중요한 일이다.통계학에서 
//N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다.
//단, N은 홀수라고 가정하자.
//
//산술평균 : N개의 수들의 합을 N으로 나눈 값
//	중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
//	최빈값 : N개의 수들 중 가장 많이 나타나는 값
//	범위 : N개의 수들 중 최대값과 최소값의 차이
//	N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.


#include<iostream>
#include<cmath>
using namespace std;

void Swap(int &a, int &b)
{
	int temp;
	temp = b;
	b = a;
	a = temp;
}

int Partition(int *arr, int head, int rear)                      // Function for Partition 
{
	int pivot = arr[head];
	int temppivotdex = head;
	for (int i = head + 1; i <= rear; i++)
	{
		if (arr[i] <= pivot)
		{
			Swap(arr[++temppivotdex], arr[i]);
		}
	}
	Swap(arr[head], arr[temppivotdex]);
	return temppivotdex;
}

void QuickSort(int *arr, int head, int rear)     // QuickSort using partition
{
	int pivotdex;
	if (head < rear)
	{
		pivotdex = Partition(arr, head, rear);
		QuickSort(arr, head, pivotdex - 1);
		QuickSort(arr, pivotdex + 1, rear);
	}
}

int average(int *arr,int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	sum = sum / n;

	return floor(sum + 0.5);
}

int center(int *arr,int n)
{
	QuickSort(arr, 0, n - 1);
	return arr[n / 2];
}

int Lowfrequency(int *arr, int n, int MAXNUM, int MINNUM)
{
	int Mincount = -200000;
	int INDEX = 0;
	int *MINDEX=new int[n];
	int *COUNT = new int[MAXNUM + 1];


	int *KMINDEX = new int[n];
	int KINDEX = 0;
	int KMincount = -200000;
	if (MAXNUM > 0)
	{
		for (int i = 0; i < MAXNUM + 1; i++)
			COUNT[i] = -1;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= 0)
				COUNT[arr[i]]++;
		}
		for (int i = 0; i < MAXNUM + 1; i++)
			if (COUNT[i] > Mincount&&COUNT[i] >= 0)
			{
				Mincount = COUNT[i];
			}
		for (int i = 0; i < MAXNUM + 1; i++)
		{
			if (COUNT[i] == Mincount)
				MINDEX[INDEX++] = i;
		}                                                      //0보다 큰 부분에 최빈값 알아냄.
	}
	if (MINNUM < 0)                                  //0보다 작은 부분
	{
		
		int *KCOUNT = new int[-MINNUM + 1];
		
		for (int i = 0; i < -MINNUM + 1; i++)
			KCOUNT[i] = -1;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0)
				KCOUNT[-arr[i]]++;
		}
		for (int i = 0; i < -MINNUM + 1; i++)
			if (KCOUNT[i] > KMincount&&KCOUNT[i]>=0)
			{
				KMincount = KCOUNT[i];
			}
		for (int i = 0; i < -MINNUM + 1; i++)
		{
			if (KCOUNT[i] == KMincount)
			{
				KMINDEX[KINDEX++] = -i;
			}
		}                                                  //0보다 작은 부분에 최빈값 알아냄.
	}

	int *FinalArr = new int[INDEX + KINDEX];
	int dex = 0;
	if (Mincount == KMincount)
	{
		for (int j = KINDEX - 1; j >= 0; j--)
		{
			FinalArr[dex++] = KMINDEX[j];
		}
		for (int j = 0; j < INDEX; j++)
			FinalArr[dex++] = MINDEX[j];
	}
	else if (KMincount > Mincount)
	{
		for (int j = KINDEX - 1; j >= 0; j--)
		{
			FinalArr[dex++] = KMINDEX[j];
		}

	}
	else {
		for (int j = 0; j < INDEX; j++)
			FinalArr[dex++] = MINDEX[j];
	}

		if (dex > 1)
			return FinalArr[1];
		else return FinalArr[0];
}

int Range(int MAX, int MIN)
{
	return MAX - MIN;
}
int main()
{
	int test;
	cin >> test;
	int *arr = new int[test];
	int MAXNUM = -200000;
	int MINNUM = 200000;
	for (int i = 0; i < test; i++)
	{
		cin >> arr[i];
		if (arr[i] > MAXNUM)
			MAXNUM = arr[i];
		if (arr[i] < MINNUM)
			MINNUM = arr[i];
	}
	cout<<average(arr, test)<<endl;
	cout<<center(arr, test)<<endl;
	cout<<Lowfrequency(arr, test, MAXNUM, MINNUM)<<endl;
	cout << Range(MAXNUM, MINNUM) << endl;
	system("pause");
}
#include<iostream>
using namespace std;

int Arr[100001][2];
int Data[100001];
int nowdex = 0;
int UpperEnd;

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

}

bool StartCan(int sTime)		//시작시간 i가 포함될 수 있는지 판단
{
	for (int i = 0; i < nowdex; i++)
	{	
		if (Arr[Data[i]][0]<= sTime&& sTime<Arr[Data[i]][1] )
			return false;
	}
	return true;
}

bool EndCan(int sTime)     // 끝나는 시간 i가 포함될 수 있는지 판단
{
	for (int i = 0; i < nowdex; i++)
	{
		if (Arr[Data[i]][1] >= sTime)
		{	
			UpperEnd = i;
			return true;
		}
	}
	return false;
}

int main()
{
	int num;
	cin >> num;
	
	// 입력하는 부분
	for (int i = 0; i < num; i++)
	{
		cin >> Arr[i][0];
		cin >> Arr[i][1];
	}		// 입력하는 부분
	// 정렬하는 부분
	for (int i = num - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (Arr[j][0] > Arr[j + 1][0])
			{
				Swap(Arr[j][0], Arr[j + 1][0]);
				Swap(Arr[j][1], Arr[j + 1][1]);
			}
		}
	}


	//Arr[i][0]은 시작시간, Arr[i][1]은 종료시간.
	int pivot = Arr[0][0];
	Data[nowdex++] = 0;
	for (int i = 1; i < num; i++)
	{
		int tempMin = INT_MAX;
		int tempdex;
		if (StartCan(Arr[i][0]))			//시작 시간 비교하는 부분
		{	
			while(1)
			{
				if (Arr[i][1] < tempMin&&Arr[i][0]==pivot)
				{
					tempMin = Arr[i][1];
					tempdex = i;
				}
				if (Arr[i][0] != pivot)
				{
					Data[nowdex++] = i;
					pivot = Arr[i][0];
					i -= 1;
					break;
				}
				if (i >= num)
					break;
				
				i++;
			}
		}																	//시작시간이 포함가능할때 제일 작은거 포함 완료
		else if(EndCan(Arr[i][1]))										//끝나는 시간이 기존의 끝나는 시간과 같을때
		{
			Data[UpperEnd] = i;
		}
	
	}
	for (int i = 0; i < nowdex; i++)
	{
		cout << Arr[Data[i]][0] << " " << Arr[Data[i]][1] << endl;
	}

	cout << nowdex;
	system("pause");
	return 0;
}
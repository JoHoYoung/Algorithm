#include<iostream>
using namespace std;

int MaxWeight;
int N;
int include[1000];
int result[1000];
float Maxprofit=0.0f;

typedef struct Data
{
	int Weight;
	int Price;
};

Data *Item;

void SwapNode(Data &a1, Data &a2)
{
	Data Temp;
	Temp = a1;
	a1 = a2;
	a2 = Temp;
}

float Ratio(Data a1)
{
	return ((float)a1.Price / (float)a1.Weight);

}

bool Promising(int n, int profit, int weight)		//n은 지금 몇번째 아이템인지, weight는 지금 무게.
{							//profit은 지금 가치.
	if (n == -1)
		return true;
	
	int TotalWeight = weight;
	float bound = profit;
	int k, j;
	if (weight > MaxWeight)
		return false;
	else
	{
		for (k = n + 1; k < N && (TotalWeight + Item[k].Weight) < MaxWeight; k++)
		{	
			TotalWeight += Item[k].Weight;
			bound += Item[k].Price;
		}
	}
	j = k;
	if (j <= N - 1)
		bound += (MaxWeight - TotalWeight)*(Ratio(Item[j]));
	
	if (bound > Maxprofit)
		return true;

	else return false;

}

void Knap(int n, int profit, int weight)
{
	cout << "Knapsack(" << n << "," << profit << "," << weight << ")" << endl;
	int numbest;
	if (weight <= MaxWeight && profit > Maxprofit)
	{
		cout << "N : " << n << endl;
		cout << "무게 : " << weight << endl;
		Maxprofit = profit;
		numbest = n;
		for (int i = 0; i <= n; i++)
		{
			cout <<"인클루드 : " <<include[i] << endl;
			result[i] = include[i];
		}
		for (int i = n + 1; i < N; i++)
			result[i] = 0;
	}

	if (Promising(n, profit, weight))
	{
		include[n + 1] = 1;
		Knap(n + 1, profit + Item[n + 1].Price, weight+ Item[n + 1].Weight);
		include[n + 1] = 0;
		Knap(n + 1, profit, weight);
	}

}


//아이템은 0번부터~ (갯수-1)번 까지.
int main()
{
	cout << "아이템 갯수 입력 ";
	cin >> N;
	cout << "최대무게 입력";
	cin >> MaxWeight;

	Item = new Data[N];

	for (int i = 1; i <= N; i++)
	{
		cout << i<<"번째 아이템의 무게, 값어치 입력";
		cin >> Item[i - 1].Weight >> Item[i - 1].Price;
	}

	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
		{
			if (Ratio(Item[j]) < Ratio(Item[j + 1]))
				SwapNode(Item[j], Item[j + 1]);
		}																// 비율이 큰것부터 소팅.
	Knap(-1, 0, 0);

	for (int i = 0; i < N; i++)
	{
		if (result[i] == 1)
			cout << endl << i+1 << " 번째 아이템 선택." << endl;
	}
	cout << Maxprofit;
	system("pause");
	return 0;
}

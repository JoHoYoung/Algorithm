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

bool Promising(int n, int profit, int weight)		//n�� ���� ���° ����������, weight�� ���� ����.
{							//profit�� ���� ��ġ.
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
		cout << "���� : " << weight << endl;
		Maxprofit = profit;
		numbest = n;
		for (int i = 0; i <= n; i++)
		{
			cout <<"��Ŭ��� : " <<include[i] << endl;
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


//�������� 0������~ (����-1)�� ����.
int main()
{
	cout << "������ ���� �Է� ";
	cin >> N;
	cout << "�ִ빫�� �Է�";
	cin >> MaxWeight;

	Item = new Data[N];

	for (int i = 1; i <= N; i++)
	{
		cout << i<<"��° �������� ����, ����ġ �Է�";
		cin >> Item[i - 1].Weight >> Item[i - 1].Price;
	}

	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
		{
			if (Ratio(Item[j]) < Ratio(Item[j + 1]))
				SwapNode(Item[j], Item[j + 1]);
		}																// ������ ū�ͺ��� ����.
	Knap(-1, 0, 0);

	for (int i = 0; i < N; i++)
	{
		if (result[i] == 1)
			cout << endl << i+1 << " ��° ������ ����." << endl;
	}
	cout << Maxprofit;
	system("pause");
	return 0;
}

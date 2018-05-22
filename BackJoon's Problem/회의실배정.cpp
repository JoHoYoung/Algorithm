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

bool StartCan(int sTime)		//���۽ð� i�� ���Ե� �� �ִ��� �Ǵ�
{
	for (int i = 0; i < nowdex; i++)
	{	
		if (Arr[Data[i]][0]<= sTime&& sTime<Arr[Data[i]][1] )
			return false;
	}
	return true;
}

bool EndCan(int sTime)     // ������ �ð� i�� ���Ե� �� �ִ��� �Ǵ�
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
	
	// �Է��ϴ� �κ�
	for (int i = 0; i < num; i++)
	{
		cin >> Arr[i][0];
		cin >> Arr[i][1];
	}		// �Է��ϴ� �κ�
	// �����ϴ� �κ�
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


	//Arr[i][0]�� ���۽ð�, Arr[i][1]�� ����ð�.
	int pivot = Arr[0][0];
	Data[nowdex++] = 0;
	for (int i = 1; i < num; i++)
	{
		int tempMin = INT_MAX;
		int tempdex;
		if (StartCan(Arr[i][0]))			//���� �ð� ���ϴ� �κ�
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
		}																	//���۽ð��� ���԰����Ҷ� ���� ������ ���� �Ϸ�
		else if(EndCan(Arr[i][1]))										//������ �ð��� ������ ������ �ð��� ������
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
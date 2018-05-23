#include<iostream>
#include<cmath>
using namespace std;

int col[5];

bool Promising(int i)
{
	if (i <= 1)
		return true;

	for (int k = 1; k < i; k++)
		if (col[k] == col[i] || (abs(col[i] - col[k]) == abs(k - i)))
			return false;

	return true;
}

void Queens(int i,int n)
{
	if (Promising(i))
		if (i == n)
		{
			cout << "---- N Queens �ະ Queen �� ��ġ---- " << endl;

			for (int i = 1; i <= n; i++)
			{
				cout << i << " �� : "<< col[i] << endl;
			}	

			cout << endl;
			return;
		}
		else
			for (int j = 1; j <= n; j++)
			{
				col[i + 1] = j;
				Queens(i + 1,n);
			}

}


int main()
{	
	int n;
	cout << "ü���� ���� ���� �Է� ";
	cin >> n;

	Queens(0,n);

	system("pause");
	return 0;
}

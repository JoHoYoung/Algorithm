#include<iostream>
using namespace std;

//W�� ����ε����� 0~7 Vertex����� �ε����� 1~7.
//
int Vertex[9];
static int Ccount = 0;
//Vertex[1....8]���� ���� ���� 1....8��°�� ��� ��带 ������.
bool Promising(int i, int n,int W[][8])		//i��°��� ���°�� �����ߴ���. ���� Ž���� ��尡 ���° ����.
{
	if (i <= 1)
		return true;

	for (int k = 1; k < i; k++)
		if (Vertex[k] == Vertex[i])
			return false;
		
	if (!W[Vertex[i - 1]][Vertex[i]])
		return false;
	
	if (i == n && !W[Vertex[0]][Vertex[i]])
		return false;

	return true;

}

void hamiltonian(int i, int n,int W[][8])		//i�� ���° ��(���) ����. n�� �� ����� ������ �.
{
	if(Promising(i,n,W))
		if (i == n)
		{
			cout << ++Ccount << "��° ���" << endl;
			for (int k = 1; k <= n; k++)
				cout << Vertex[k] <<"------>";

			cout <<Vertex[1] <<endl<<endl;
		}
		else
			for (int k = 0; k < n; k++)
			{
				Vertex[i + 1] = k;
				hamiltonian(i + 1, n,W);
			}

}

int main()
{
	int	W[8][8] = { {0, 1, 1, 0, 0, 0, 0, 1} ,
						{1, 0, 1, 0, 0, 0, 1, 1},
						{ 1, 1, 0, 1, 0, 1, 0, 0 },
						{ 0, 0, 1, 0, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 0, 1, 0, 0 },
						{ 0, 0, 1, 0, 1, 0, 1, 0 },
						{ 0, 1, 0, 0, 0, 1, 0, 1 },
						{ 1, 1, 0, 0, 0, 0, 1, 0 } };
	hamiltonian(0, 8,W);
	system("pause");
	return 0;
}
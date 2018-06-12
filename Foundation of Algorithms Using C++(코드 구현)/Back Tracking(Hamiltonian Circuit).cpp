#include<iostream>
using namespace std;

//W의 노드인덱스는 0~7 Vertex행렬의 인덱스는 1~7.
//
int Vertex[9];
static int Ccount = 0;
//Vertex[1....8]까지 들어가는 것은 1....8번째로 몇번 노드를 갔는지.
bool Promising(int i, int n,int W[][8])		//i라는것은 몇번째로 선택했는지. 지금 탐색할 노드가 몇번째 인지.
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

void hamiltonian(int i, int n,int W[][8])		//i는 몇번째 길(노드) 인지. n은 총 노드의 갯수는 몇개.
{
	if(Promising(i,n,W))
		if (i == n)
		{
			cout << ++Ccount << "번째 경로" << endl;
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
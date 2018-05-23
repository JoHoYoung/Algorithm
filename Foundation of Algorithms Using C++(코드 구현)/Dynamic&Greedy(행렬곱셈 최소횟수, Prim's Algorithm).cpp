#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;
#define NoRoute 10000

int MinMultime(int *d, int n)						// d�� ��ĵ��� ���, ���� ���ʴ�� �Է��� �迭 n�� ����� ����
{
	int num = n + 1;
	int idx = 0;
	int *D = new int[num];
	D[0] = d[0];
	for (int i = 1; i <= n * 2 - 1; i += 2)
		D[++idx] = d[i];


	int **M;
	M = new int*[n];
	for (int i = 0; i < n; i++)
		M[i] = new int[n];

	for (int i = 0; i < n; i++)
		M[i][i] = 0;

	for (int k = 1; k < n; k++)
	{

		for (int i = 0; i < n - k; i++)
		{
			if (k == 1)
				M[i][i + k] = D[i] * D[i + 1] * D[i + 2];
			else
			{
				M[i][i + k] = 10000;
				for (int j = 1; j <= k; j++)
					if (M[i][i + k] >(M[i][i + k - j] + M[i + k - j + 1][i + k] + D[i] * D[i + k - j + 1] * D[i + k + 1]))
						M[i][i + k] = (M[i][i + k - j] + M[i + k - j + 1][i + k] + D[i] * D[i + k - j + 1] * D[i + k + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] < 0)
				cout << -1 << " ";
			else
				cout << M[i][j] << " ";
		}
		cout << endl;
	}

	return M[0][n - 1];
}

typedef struct Edges {
	int Point1;
	int Point2;
	int cost;
};
class Matrix
{
		public : int **W;
		public : int num;
		public: int *MSTf;
		public: int Findex = 0;
		public: int Eindex = 0;
		public: int *nearest;
		public: int *distance;
		public: Edges * F;
		public: int TotalCost = 0;
		public: Matrix(int n, int** arr)
		{
			num = n;
			W = arr;
			MSTf = new int[num];
			nearest = new int[num];
			distance = new int[num];
			F = new Edges[num - 1]; //������ ������ ����� �������� �ϳ� ���� ������.
		}
		public : void prim()
		{	
			for (int i = 1; i < num; i++)
			{
				nearest[i] = 1;
				distance[i] = W[0][i];
			}
	
			MSTf[Findex++] = 0;  // ��ó�� �������� 0�����Ѵ�.

			for (int i = 0; i < num-1; i++)
			{
				int min = INT_MAX;
				int vnear;
				for (int i = 1; i < num; i++)
				{
					if (0 < distance[i]&& distance[i] < min)
					{
						min = distance[i];
						vnear = i;
					}
				}
				MSTf[Findex++] = i;
				F[Eindex].Point1 = nearest[vnear];
				F[Eindex].Point2 = vnear;
				F[Eindex].cost = distance[vnear];
				TotalCost += distance[vnear];
				distance[vnear] = -1;
		//���� 0�̾ƴ� ���ο� vnear�� �߰������Ƿ� ���Ͽ� �� ����.
				for (int i = 1; i < num;i++)
				{
					if(distance[i]>W[i][vnear])
					{ 
						distance[i] = W[i][vnear];
						nearest[i] = vnear;
					}
				}
			}
		}

};



void main()
{

	int arr[12] = { 5,2,2,3,3,4,4,6,6,7,7,8 };
	int M;
	cout<<endl<<"����� �ּ� �� Ƚ�� : "<<MinMultime(arr, 6)<<endl;
	
	int **W;
	W = new int*[5];
	for (int i = 0; i < 5; i++)
		W[i] = new int[5];
	
	int Arr1[5] = { 0,1,3,NoRoute,NoRoute };
	int Arr2[5] = { 1,0,3,6,NoRoute };
	int Arr3[5] = { 3,3,0,4,2 };
	int Arr4[5] = { NoRoute ,6,4,0,5 };
	int Arr5[5] = { NoRoute ,NoRoute ,2,5,0 };
	W[0] = Arr1;
	W[1] = Arr2;
	W[2] = Arr3;
	W[3] = Arr4;
	W[4] = Arr5;

	int n = 5;
	
	Matrix PrimMatrix(n, W);
	PrimMatrix.prim();
	cout << "MST Edge���� Cost �� : " << PrimMatrix.TotalCost << endl;
	system("pause");
}
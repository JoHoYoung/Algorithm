#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;
#define NoRoute 10000
int Min(int a, int b)
{
	if (a >= b)
		return b;
	else return a;
}
class Graph
{
public: int **W;
		 int **D;
		 int **Path;
		 int NodeNum;
			 Graph(int NumodNode);
			 void InitW(int* arr);
			 void InitDwithFloyd();
			 void InitDwithFloydPath();
			 void printW();
			 void printD();
			 void PrintPath(int s,int d);
};

void Graph::printW()
{
	for (int i = 0; i < NodeNum; i++)
	{
		for (int j = 0; j < NodeNum; j++)
		{	
			if (W[i][j] == NoRoute)
			{
				cout << "X" << " ";
			}
			else
			cout << W[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::printD()
{
	for (int i = 0; i < NodeNum; i++)
	{
		for (int j = 0; j < NodeNum; j++)
			cout << D[i][j] << " ";

		cout << endl;
	}

}

Graph::Graph(int NumofNode)
{
	NodeNum = NumofNode;
	W = new int*[NodeNum];
	D = new int*[NodeNum];
	Path = new int*[NodeNum];
	for (int i = 0; i < NodeNum; i++)
	{
		Path[i] = new int[NodeNum];
		W[i] = new int[NodeNum];
		D[i] = new int[NodeNum];
	}
}

void Graph::InitW(int *arr)
{
	int idx = 0;

	for (int i = 0; i < NodeNum; i++)
		for (int j = 0; j < NodeNum; j++)
		{
			W[i][j] = arr[idx++];
			Path[i][j] = NULL;
		}
}

void Graph::InitDwithFloyd()
{
	for (int i = 0; i < NodeNum; i++)
		for (int j = 0; j < NodeNum; j++)
			D[i][j] = W[i][j];
	
	for (int k = 0; k < NodeNum; k++)
		for (int i = 0; i < NodeNum; i++)
			for (int j = 0; j < NodeNum; j++)
					D[i][j] = Min(D[i][j], D[i][k] + D[k][j]);
			
}

void Graph::InitDwithFloydPath()
{
	for (int i = 0; i < NodeNum; i++)
		for (int j = 0; j < NodeNum; j++)
			D[i][j] = W[i][j];

	for (int k = 0; k < NodeNum; k++)
		for (int i = 0; i < NodeNum; i++)
			for (int j = 0; j < NodeNum; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					Path[i][j] = k;
				}
			}

}

void Graph::PrintPath(int s,int d)
{
	if (Path[s][d] != NULL)
	{	
		PrintPath(s, Path[s][d]);
		cout << "V" << PrintPath[s][d];
		PrintPath(Path[s][d], d);
	}

}

int Recursionbin(int n, int k)
{
	if (k == 0 || k == n||n==0)
		return 1;
	else
		return Recursionbin(n - 1, k - 1) + Recursionbin(n - 1, k);
}

int Dynamicbin(int n, int k)
{
	int **arr;
	 arr = new int*[n+1];
	for (int i= 0; i <= n; i++)
		arr[i] = new int[k+1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k && j <= i; j++)
			if (i == j || i == 0 || j == 0)
				arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	
	return arr[n][k];
}

int MinSpaceCompbin(int n, int k)
{
	int *arr=new int[k];
	int temp = 1;
	int temp2 = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k && j <= i; j++)
		{
			if (i == j || i == 0 || j == 0)
				arr[j] = 1;
			else {
				temp = arr[j];
				arr[j] += temp2 ;
				}
			temp2 = temp;
		}
	return arr[k];
}

int MinMultime(int *d, int n)						// d는 행렬들의 행수, 열수 차례대로 입력한 배열 n은 행렬의 갯수
{
	int num = n + 1;
	int idx = 0;
	int *D = new int[num];
	D[0] = d[0];
	for (int i = 1; i <= n*2-1; i += 2)
		D[++idx] = d[i];

	for (int i = 0; i < num; i++)
		cout <<endl<< D[i]<<endl;

	int **M;
	M = new int*[n];
	for (int i = 0; i < n; i++)
		M[i] = new int[n];

	for (int i = 0; i < n; i++)
		M[i][i] = 0;

	for (int k = 1; k < n; k++)
	{

		for (int i = 0; i < n-k; i++)
		{
			if (k == 1)
				M[i][i + k] = D[i] * D[i + 1] * D[i + 2];
			else
			{
				for (int j = 1; j < k; j++)
				{
					M[i][i + k] = 10000;
					if (M[i][i + k] > (M[i][i + k - j] + M[i + k - j+1][i + k] + D[i] * D[i + k - j+1] * D[i + k+1]))
					{
						M[i][i + k] = (M[i][i + k - j] + M[i + k - j+1][i + k] + D[i] * D[i + k - j+1] * D[i + k+1]);
					}
				}
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

	return M[0][n-1];
}

void main()
{
	/*time_t time0 = clock();
	cout <<"동적 프로그래밍 : "<< Dynamicbin(27, 14) << endl;
	time_t time1 = clock();
	cout <<"재귀적 방법 : "<< Recursionbin(27, 14) << endl;
	time_t time2 = clock();
	cout << "동적 프로그래밍 소요시간 : " << (float)(time1 - time0) / (float)(CLOCKS_PER_SEC) << endl;
	cout << "재귀방법 소요시간 : " << (float)(time2 - time1) / (float)CLOCKS_PER_SEC << endl;
	*/
	Graph G(5);
	int info[25] = { 0,1,NoRoute ,1,5,9,0,3,2,NoRoute ,NoRoute ,NoRoute ,0,4,NoRoute ,NoRoute ,NoRoute ,2,0,3,3,NoRoute ,NoRoute ,NoRoute ,0 };
	G.InitW(info);
	G.printW();
	cout << endl;
	G.InitDwithFloydPath();
	G.printD();
	G.PrintPath(0, 4);
	
	int arr[12] = { 5,2,2,3,3,4,4,6,6,7,7,8};
	int M; 
	M= MinMultime(arr, 6);
	cout << M;
	system("pause");
}
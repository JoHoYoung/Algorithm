#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;
#define NoRoute 10000


typedef struct Edges {
	int Point1;
	int Point2;
	int cost;
};
void SwapEdge(Edges& a1, Edges& a2)
{
	Edges temp;
	temp = a1;
	a1 = a2;
	a2 = temp;

}

bool isCycle(Edges* F, Edges E, int dex)
{
	if (dex == 0)
		return false;
	int arr[10000];
	int arr2[10000];
	int adex = 0;
	int a2dex = 0;

	for (int i = 0; i < dex; i++)
		if (F[i].Point1 == E.Point1)
			arr[adex++] = F[i].Point2;
		else if (F[i].Point2 == E.Point1)
			arr[adex++] = F[i].Point1;

	for (int i = 0; i < dex; i++)
		if (F[i].Point1 == E.Point2)
			arr2[a2dex++] = F[i].Point2;
		else if (F[i].Point2 == E.Point2)
			arr2[a2dex++] = F[i].Point1;

	for (int i = 0; i < a2dex; i++)
		for (int j = 0; j < adex; j++)
			if (arr2[i] == arr[j])
				return true;

	return false;
}

void KruskalWithEdges(int n, int m, Edges* E, Edges* F)	// n : 정점의 수 , m : 엣지의 수
{
	for (int i = m - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
		{
			if (E[j].cost > E[j + 1].cost)
				SwapEdge(E[j], E[j + 1]);
		}

	int Findex = 0;

	for (int i = 0; i < m; i++)
	{
		if (!isCycle(F, E[i], Findex))
			F[Findex++] = E[i];
	}
	cout << endl << "Edge기반 Kruskal로 찾은 엣지들의 정보 " << endl;
	for (int i = 0; i<n - 1; i++)
	{
		cout << " 노드 1 : " << F[i].Point1 << endl;
		cout << " 노드 2 : " << F[i].Point2 << endl;
		cout << " Cost : " << F[i].cost << endl;
	}
}

int parent[5];

int find(int i)
{
	while (parent[i]) i = parent[i];
	return i;
}

int uni(int i, int j)
{
	if (i != j)
	{
		parent[j] = i;
		cout << i << " <-----" << j << endl;
		return 1;
	}
	return 0;
}

void Kruskal(int n, int m, int W[5][5], Edges* F)
{
	int u, v, p, q;
	int Findex = 0;
	for (int k = 0; k < n; k++) // 모두 찾을때 까지.
	{	
		int min = INT_MAX;
		for (int i = 0; i < n; i++)		// 제일 작은 Edge를 찾아내는 부분.
		{
			for (int j = 0; j < n; j++)
				if (W[i][j] != 0 && W[i][j] < min)
				{
					min = W[i][j];
					 u = i;
					 v = j;
				}
		}

		p = find(u);
		q = find(v);

		if (p != q)		// 부모가 다르면 즉, Cycle을 형성하지 않는다면
			uni(p, q);     // 연결해 준다.
		// Edge정보 저장
		F[Findex].Point1 = u;
		F[Findex].Point2 = v;
		F[Findex++].cost = W[u][v];
		W[u][v] = 999;
		W[v][u] = 999;
	}
}

void Dijkstra(int n, int W[5][5], Edges F[5])
{
	int Findex = 0;
	int dex = 0;
	int i, vnear;
	int *touch;
	int *length;
	int *D;
	touch = new int[n];
	length = new int[n];
	D = new int[n];

	for (int i = 1; i < n; i++)
	{
		touch[n] = 0;
		length[i] = W[0][i];
		D[i] = W[0][i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int min = INT_MAX;
		for (int j = 1; j < n; j++)
		{
			if (length[j] > 0 && length[j] < min)
			{
				min = length[j];
				vnear = j;
			}
		}
			F[Findex].Point1 = touch[vnear];
			F[Findex].Point2 = vnear;
			F[Findex].cost = length[vnear];

			for (int k = 1; k < n; k++)
			{
				if (length[vnear] + W[vnear][k] < length[k])
				{
					length[k] = length[vnear] + W[vnear][k];
					D[k] = length[k];
					touch[k] = vnear;
				}
			}
			length[vnear] = -1;
	}
	
	cout << endl << "Dijkstra 로 찾아낸 0번 노드부터 다른 노드까지의 거리 " << endl;
	for (int i = 1; i < n; i++)
		cout << i << "번 노드까지의 거리 : " << D[i] << endl;

}

void main()
{
	Edges E[7];
	E[0].Point1 = 0;
	E[0].Point2 = 2;
	E[0].cost = 3;
	E[1].Point1 = 0;
	E[1].Point2 = 1;
	E[1].cost = 1;
	E[2].Point1 = 1;
	E[2].Point2 = 2;
	E[2].cost = 3;
	E[3].Point1 = 1;
	E[3].Point2 = 3;
	E[3].cost = 6;
	E[4].Point1 = 2;
	E[4].Point2 = 3;
	E[4].cost = 4;
	E[5].Point1 = 2;
	E[5].Point2 = 4;
	E[5].cost = 2;
	E[6].Point1 = 3;
	E[6].Point2 = 4;
	E[6].cost = 5;
	Edges F[5];

	KruskalWithEdges(5, 7, E, F);

	cout << " Kruskal " << endl;
	Edges V[5]; // Kruskal로 찾아낸 Edge정보들을 저장할 Edges 구조체 배열
	
	int Q[5][5] = { {0,1,3,NoRoute,NoRoute},{1,0,3,6,5},{3,3,0,4,2},{ NoRoute,6,4,0,5},{ NoRoute,NoRoute,2,5,0 }};
	
	Kruskal(5, 7, Q ,V);
	
	int D[5][5] = { { 0,7,4,6,1 },{ NoRoute,0,NoRoute,NoRoute,NoRoute },{ NoRoute,2,0,5,NoRoute },
	{ NoRoute,3,NoRoute,0,NoRoute },{ NoRoute,NoRoute,NoRoute,1,0 } };
	Edges K[5];  //Dijkstra로 찾아낸 Edge 정보들을 저장할 Edges 구조체 배열
	Dijkstra(5, D, K);

	system("pause");
}


int parent[200];
int ranking[200];

int getParent(int idx){
    if(parent[idx]==idx) return idx;
    return parent[idx] = getParent(parent[idx]);
}


void unionParent(int i, int j){
    int a = getParent(i);
    int b = getParent(j);
    
    if(a!=b){
        if(ranking[a] >ranking[b])
            swap(a,b);
    
        parent[a]=b;
        
        if(ranki)
    }
}

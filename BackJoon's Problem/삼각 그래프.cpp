//문제 4883 삼각 그래프
//이 문제는 삼각 그래프의 가장 위쪽 가운데 정점에서 가장
// 아래쪽 가운데 정점으로 가는 최단 경로를 찾는 문제이다.
//
//삼각 그래프는 사이클이 없는 그래프로 N ≥ 2 개의 행과 3
// 열로 이루어져 있다. 삼각 그래프는 보통 그래프와 다르게 간선이 아
// 닌 정점에 비용이 있다. 어떤 경로의 비용은 그 경로에서 지나간 정점의 비용의 합이다.
//
//오른쪽 그림은 N = 4인 삼각 그래프이고, 가장 위쪽 가운데 정점에서
// 가장 아래쪽 가운데 정점으로 경로 중 아래로만 가는 경로의 비용은 7+13+
// 3+6 = 29가 된다. 삼각 그래프의 간선은 항상 오른쪽 그림과 같은 형태로 연결되어 있다.

// 넘어가지 않도록 아래 한칸, 또는 같은층 오른쪽. 내려간다.
// 맨 아래 가운데 칸
// 케이스 분리. 지금 위치 1행, 2행, 3행.
// n열의 1행으로 오는 경우 :  n-1열의 1행, 2행 // n열의 2행 : n-1열의 1행,2행,3행 n열의 3행: n-1열의 2행,3행
// DP[n][0]= Min(DP[n-1][0],DP[n-1][1]) DP[n][1]
#include<iostream>
#include<memory.h>
using namespace std;

int DP[100005][4];
int Map[100005][4];

int n;

int Min(int a,int b)
{
    if(a<b)
        return a;
    else return b;
}

int main()
{
    int result[100005];
    int dex=0;

    do {

        memset(Map,0,sizeof(Map));
        memset(DP,0,sizeof(DP));

        cin>>n;

        if(!n)
        {
            break;
        }

        for (int q = 0; q < n; q++)
            for (int m = 0; m < 3; m++) {
                cin >> Map[q][m];
            }

        DP[0][0] = 500000000;
        DP[0][1] = Map[0][1];
        DP[0][2] = DP[0][1] + Map[0][2];

        for (int q = 1; q < n; q++) {
            DP[q][0] = Min(DP[q - 1][0], DP[q - 1][1]) + Map[q][0];
            DP[q][1] = Min(DP[q][0], Min(DP[q - 1][0], Min(DP[q - 1][1], DP[q - 1][2]))) + Map[q][1];
            DP[q][2] = Min(DP[q][1], Min(DP[q - 1][1], DP[q - 1][2])) + Map[q][2];
        }

        cout<<++dex<<". "<<DP[n-1][1]<<endl;

    }while(n);


    return 0;
}
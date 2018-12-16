//문제 1937 욕심쟁이 판
// n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 그리고 그 곳의 대나무를 다
// 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 그런데 단 조건이 있다.
// 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다.
// 만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)
//
//이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 이
// 동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다.
// n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.

#include<iostream>
using namespace std;

int N;
int map[501][501] = {0};
int DP[501][501] = {0};

int vectX[4] = {0,1,0,-1};
int vectY[4] = {1,0,-1,0};

int Max = 0;
void search(int a, int b) {

    if (a < 0 || b < 0 || a >= N || b >= N)
        return;


    int max = -100;

    for(int i=0;i<4;i++) {
        int X = a + vectX[i];
        int Y = b + vectY[i];

        if (X < 0 || Y < 0 || X >= N || Y >= N)
            continue;

        int pivot = -1000;
        if (map[X][Y] < map[a][b]) {
            if (DP[X][Y] == 0)
                search(X, Y);

            pivot = DP[X][Y];

        }

        if (pivot > max)
            max = pivot;
    }

    if(max != -100)
        DP[a][b] = max + 1;
    else DP[a][b] =1;

    if(Max<DP[a][b])
        Max=DP[a][b];

}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }


    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
            if (DP[i][j] == 0)
                search(i, j);
        }
    }

    cout<<Max;
    return 0;
}
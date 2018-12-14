//문제 11048 이동하기
//준규는 N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다. 미로의 가장 왼쪽 윗
// 방은 (1, 1)이고, 가장 오른쪽 아랫 방은 (N, M)이다.
//
//준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 준규가 (r, c)에 있으면,
// (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다.
// 또, 미로 밖으로 나갈 수는 없다.
//
//준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}
long DP[1000][1000];
int maze[1000][1000];
int main()
{
    int N,M;
    cin>>N;
    cin>>M;

    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) {
                DP[0][0] = maze[0][0];
            } else if (i == 0) {
                DP[i][j] = DP[i][j - 1] + maze[i][j];
            } else if (j == 0) {
                DP[i][j] = DP[i - 1][j] + maze[i][j];
            } else {
                DP[i][j] = max(DP[i - 1][j - 1], max(DP[i - 1][j], DP[i][j - 1])) + maze[i][j];
            }

        }

    }

    cout<<DP[N-1][M-1];

    return 0;
}
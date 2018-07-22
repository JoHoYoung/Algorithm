//문제 2169
//NASA에서는 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다. 실제 화성의 모습은 굉장히 복잡하지만,
//로봇의 메모리가 얼마 안 되기 때문에 지형을 N×M 배열로 단순화 하여 생각하기로 한다.
//
//지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만
//, 위쪽으로는 이동할 수 없다. 또한 한 번 탐사한 지역(배열에서 하나의 칸)은 탐사하지 않기로 한다.
//
//각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래
//        (N, M)으로 보내려고 한다. 이 때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의
//합이 최대가 되도록 하는 프로그램을 작성하시오.

#include<iostream>
using namespace std;
int N;
int M;
int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int LBig[1003];
int RBig[1003];
int DP[1003][1003];

int main()
{
    cin>>N;
    cin>>M;

    bool visited[N][M];
    int **W;
    W=new int*[N+1];

    for(int i=0;i<=N;i++)
        W[i]=new int[M+1];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> W[i][j];

    DP[1][1]=W[1][1];

    LBig[0]=-100000;
    RBig[M+1]=-100000;

    for(int j=2;j<=M;j++)
        DP[1][j]=DP[1][j-1]+W[1][j];

    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
            LBig[j] = Max(DP[i-1][j],LBig[j-1])+W[i][j];
        for(int j=M;j>=1;j--)
            RBig[j] = Max(DP[i-1][j],RBig[j+1])+W[i][j];
        for(int j=1;j<=M;j++)
            DP[i][j]=Max(LBig[j],RBig[j]);

    }

    cout<<DP[N][M];
        return 0;

}
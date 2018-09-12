//문제 1932 정수 삼각
//위 그림은 크기가 5인 정수 삼각형의 한 모습이다.
//
//맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이
// 제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에
// 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
//
//삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
#include<iostream>
#include<algorithm>
using namespace std;

//traingle [0][0]....N층에는 [N-1][N-1]까지
// 바텀 업 방식으로 풀면 될듯.

long DP[500][500];
int triangle[500][500];

int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}

int main() {

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
            cin>>triangle[i][j];
    }

    for(int i=N-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(i==N-1)
            {DP[i][j]=triangle[i][j];}
            else
            {
                DP[i][j]=triangle[i][j]+Max(DP[i+1][j],DP[i+1][j+1]);

            }
        }
    }
    cout<<DP[0][0];

    return 0;
}
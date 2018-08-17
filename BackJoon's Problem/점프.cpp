//문제 1890 점프
//N×N 게임판에 수가 적혀져 있다. 이 게임의 목표는 가장 왼쪽 위 칸에서 가장
//오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.
//
//각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다. 반드시
//        오른쪽이나 아래쪽으로만 이동해야 한다. 0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다. 한 번 점프를 할 때, 방향을 바꾸면 안된다. 즉, 한 칸에서 오른쪽으로 점프를 하거나, 아래로 점프를 하는 두 경우만 존재한다.
//
//가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있
//        는 경로의 개수를 구하는 프로그램을 작성하시오.
#include<iostream>

using namespace std;
int main()
{
    int N;
    cin>>N;

    long **Arr;
    Arr=new long*[N];
    for(int i=0;i<N;i++)
        Arr[i]=new long[N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>Arr[i][j];

    long result[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            result[i][j]=0;


    result[0][0]=1;
    for(int i=0;i<=N-1;i++)
        for(int j=0;j<=N-1;j++)
        {
            if(!(i==N-1&&j==N-1))
            {if(result[i][j]!=0&&((i+Arr[i][j])<N))
                    result[i+Arr[i][j]][j]+=result[i][j];
                if(result[i][j]!=0&&((j+Arr[i][j])<N))
                    result[i][j+Arr[i][j]]+=result[i][j];
            }
        }

    cout<<result[N-1][N-1];

    return 0;

}
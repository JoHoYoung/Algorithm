//문제 10844 쉬운 계단
//45656이란 수를 보자.
//이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
//세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
//N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다)

#include<iostream>
using namespace std;

long long DP[101][10];
long long r=1000000000;

int main()
{
    DP[1][0]=0;
    for(int i=1;i<=9;i++)
        DP[1][i]=1;
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)
        for(int j=0;j<=9;j++) {
        if(j==9)
            DP[i][j]=DP[i-1][j-1];
        else if(j==0)
            DP[i][j] = DP[i - 1][j+1];
        else DP[i][j]=(DP[i-1][j-1]+DP[i-1][j+1])%r;
        }

    long long result=0;

    for(int i=0;i<=9;i++)
    {result+=DP[N][i];
    result%=r;
    }

    cout<<result%r<<endl;
    return 0;

}
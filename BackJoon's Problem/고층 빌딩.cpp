//문제 1328 고층 빌
//상근이가 살고있는 동네에는 빌딩 N개가 한 줄로 세워져 있다. 모든 빌딩의 높이는 1보다 크거나 같고, N보다 작거나 같으
// 며, 같은 높이를 가지는 빌딩은 없다. 상근이는 학교 가는 길에 가장 왼쪽에 서서 빌딩을 몇 개 볼 수 있는
// 지 보았고, 집에 돌아오는 길에는 가장 오른쪽에 서서 빌딩을 몇 개 볼 수 있는지 보았다.
//
//상근이는 가장 왼쪽과 오른쪽에서만 빌딩을 봤기 때문에, 빌딩이 어떤 순서로 위치해있는지는 알 수가 없다.
//
//빌딩의 개수 N과 가장 왼쪽에서 봤을 때 보이는 빌딩의 수 L, 가장 오른쪽에서 봤을 때 보이는 빌
// 딩의 수 R이 주어졌을 때, 가능한 빌딩 순서의 경우의 수를 구하는 프로그램을 작성하시오.
//
//예를 들어, N = 5, L = 3, R = 2인 경우에 가능한 빌딩의 배치 중 하나는 1 3 5 2 4이다.

// 입력받는것... 빌딩은 N개, 크기는 1~N 오른쪽에서 보이는거 R, 왼쪽 L
// 제일큰거를 기준으로... N,R중에 큰숫자가 제일큰 빌딩의 제일작은 높이? 값이 4로 둘중 큰것이면 제일큰 빌딩의
// 최소높이는 4인것. 왼쪽경우의 수 곱하기 오른쪽 경우의 수가 답이다.
// DP[n][m]에서 n은 제일큰 빌딩의 높이, m은 보이는 빌딩 수.
// DP[n][m] 에서 m<=n이다.
// 처음받는 N은 빌딩의 최대높이, 총 빌딩의 갯수이다.
// 빌딩의 최대높이 즉 DP[n][m]에서 n은 MAX(L,R)~N 까지이다.
// 가릴수 있는 빌딩의 갯수..를 하자.
// L+R은 N+1보다 작거나 같다.
// DP[n][m]에서 음.. DP[n][m]은 n이 최대높이일때 m-1개를 가릴수 있는 경우의 수라고 치자. 총m개를 놓는것이지.
// DP[n][m]= DP[n][m-1]+DP[n-1][m-1]+DP[n-2][m-1]......

#include<iostream>
using namespace std;

int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
long DP[103][103];

int main()
{
    int N,L,R;

    cin>>N;
    cin>>L;
    cin>>R;

    int pivot=Max(L,R); //pivot은 제일큰 빌딩의 최소높이.

    for(int i=1;i<=N;i++)
    {
        for(int k=1;k<=100;k++) {
            if(i==1||k==1) {
                DP[i][k] = 1;
            }else if(i==k)
            {
                DP[i][k]=1;
            }
            else if(i!=k){
            DP[i][k] = (DP[i-1][k-1]%1000000007+ DP[i - 1][k]%1000000007)%1000000007;
            DP[i][k]%=1000000007;
        }else if(k>i)
            {
                DP[i][k]=0;
            }
        }

    }
    long result=0;

    int temp=N-(L+R)+1;
    for(int i=pivot;i<=N;i++)
    {
        for(int j=0;j<=temp;j++)
        {result+=((DP[i-1][L-1+j]%1000000007)*(DP[i-1][R-1+temp-j]%1000000007))%1000000007;
        result%=1000000007;}
    }
    //DP[n][m]에서 최대높이가 n, 갯수가 m일때 경우의수 다 구함.
            cout<<(result%1000000007);
    return 0;
}
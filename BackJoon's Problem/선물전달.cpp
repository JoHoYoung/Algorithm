//문제 1256 선물전달
//이번 ACM-ICPC 대회에 참가한 모든 사람들은 선물을 하나씩 준비했다.
//
//대회가 끝나고 난 후에 각자 선물을 전달하려고 할 때, 선물을 나누는 경우의 수를 구하는 프로그램을 작성하시오.
//
//모든 사람은 선물은 하나씩 받으며, 자기의 선물을 자기가 받는 경우는 없다.
// 화살표를 받고, 주기


// 어떤 두사람이 주고받고 하던대로 하는경우 - > DP[N-2]
// 1번 선물을 누가 받고 나머지는 하던대로


#include<iostream>
using namespace std;

long DP[1000003];
int mod=1000000000;

int main() {

    int N;
    cin>>N;


    DP[1]=0;
    DP[2]=1;

    for(int i=3;i<=N;i++)
    {
        DP[i]=(i-1)*(DP[i-1]%mod+DP[i-2]%mod)%mod;
        DP[i]%=mod;
    }

    cout<<DP[N]%mod;
    return 0;
}
#include<iostream>
using namespace std;

int DP[1001];
int main(){

    int N;
    cin>>N;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;

    for(int i=4;i<=N;i++){
        DP[i] = DP[i-1] + DP[i-2];
    }
    cout<<DP[N]%10007;
    return 0;
}
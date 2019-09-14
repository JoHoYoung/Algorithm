#include<iostream>

using namespace std;

long DP[91][2];

// 0으로 끝나는, 1로끝나는 N자리 이친수.
int main() {
    int N;
    cin>>N;
    DP[1][0] = 0;
    DP[1][1] = 1;

    for(int i=2;i<=N;i++){
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }
    if(N <=1){
        cout<<1;
        return 0;
    }
    cout<<DP[N][0] + DP[N][1];
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

int DP[2][300];

// [0] : 전계단 밟고 N계단 밟은경우.
// [1] : 전계단 뛰어넘고 N계단 밟은경우.
int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int N;
    cin>>N;
    int *stairs = new int[N];

    for(int i=0;i<N;i++){
        cin>>stairs[i];
    }

    DP[0][0] = stairs[0];
    DP[1][0] = stairs[0];

    DP[0][1] = DP[0][0] + stairs[1];
    DP[1][1] = stairs[1];

    for(int i=2;i<N;i++){
        DP[0][i] = DP[1][i-1]+stairs[i];
        DP[1][i] = max(DP[0][i-2],DP[1][i-2]) + stairs[i];
    }
    cout<<max(DP[0][N-1],DP[1][N-1]);
}
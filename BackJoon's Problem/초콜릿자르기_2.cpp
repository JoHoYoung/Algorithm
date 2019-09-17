#include<iostream>

using namespace std;

int DP[301][301];

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main() {

    int N,M;
    cin>>N;
    cin>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            DP[i][j] =100000000;
            if(i ==1){
                DP[i][j] = j-1;
                continue;
            }
            if(j==1){
                DP[i][j] = i-1;
                continue;
            }
            for(int k=1;k<=j/2;k++){
                DP[i][j] = min(DP[i][j],DP[i][j-k]+DP[i][k]+1);
            }
        }
    }
    cout<<DP[N][M];
    return 0;
}
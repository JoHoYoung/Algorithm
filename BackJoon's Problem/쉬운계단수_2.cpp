#include<iostream>

using namespace std;

long DP[101][10];
int PIVOT = 1000000000;

int main() {
    int N;
    cin>>N;

    for(int i=0;i<10;i++){
        DP[1][i] = 1;
    }

    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            if(j == 0){
                DP[i][j] = DP[i-1][1]%PIVOT;
                continue;
            }

            if(j == 9){
                DP[i][j] = DP[i-1][8]%PIVOT;
                continue;
            }

            DP[i][j] = (DP[i-1][j-1]%PIVOT + DP[i-1][j+1]%PIVOT)%PIVOT;
        }
    }
    int result = 0;
    for(int i=1;i<10;i++){
        result += DP[N][i]%PIVOT;
        result %= PIVOT;
    }
    cout<<result%PIVOT;
    return 0;
}
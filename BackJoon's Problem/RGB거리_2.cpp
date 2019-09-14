#include<iostream>
using namespace std;

//
int DP[1001][3];

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main(){

    int N;
    cin>>N;
    int** arr = new int*[N];
    for(int i=0;i<N;i++){
        arr[i] = new int[3];
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    DP[0][0] = arr[0][0];
    DP[0][1] = arr[0][1];
    DP[0][2] = arr[0][2];

    for(int i=1;i<N;i++){
        DP[i][0] = min(DP[i-1][1],DP[i-1][2]) + arr[i][0];
        DP[i][1] = min(DP[i-1][0],DP[i-1][2]) + arr[i][1];
        DP[i][2] = min(DP[i-1][0],DP[i-1][1]) + arr[i][2];
    }
    cout<<min(DP[N-1][0],min(DP[N-1][1],DP[N-1][2]));
    return 0;
}
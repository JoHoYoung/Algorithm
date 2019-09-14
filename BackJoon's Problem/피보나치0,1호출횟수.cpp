#include<iostream>
#include<cmath>
using namespace std;

int DP[2][41];

int main(){
    DP[0][0] = 1;
    DP[1][0] = 0;

    DP[0][1] = 0;
    DP[1][1] = 1;

    int N;
    cin>>N;

    int *arr = new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int t=0;t<N;t++){
        int Num = arr[t];
        for(int i=2;i<=Num;i++){
            DP[0][i] = DP[0][i-1] + DP[0][i-2];
            DP[1][i] = DP[1][i-1] + DP[1][i-2];
        }
        cout<<DP[0][Num]<<" "<<DP[1][Num]<<endl;
    }
    return 0;
}
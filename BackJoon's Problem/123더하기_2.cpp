#include<iostream>
#include<cmath>
using namespace std;

int DP[100];
int main(){
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    int T;
    cin>>T;
    int *result = new int[3];
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        for(int k=4;k<=N;k++){
            DP[k] = DP[k-1] + DP[k-2] + DP[k-3];
        }
        cout<<DP[N];
    }
}
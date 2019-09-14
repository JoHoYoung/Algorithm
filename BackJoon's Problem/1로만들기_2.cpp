#include<iostream>

using namespace std;
int DP[1000000];

int Min(int a,int b){
    if(a > b){
        return b;
    }
    return a;
}

int main(){

    int N;
    cin>>N;
    fill_n(DP,1000000,100000);
    DP[N] = 0;
    for(int i=N;i>=1;i--){
        if(i%2 == 0){
            DP[i/2] = Min(DP[i] + 1,DP[i/2]);
        }
        if(i%3 == 0){
            DP[i/3] = Min(DP[i] + 1,DP[i/3]);
        }
        DP[i-1] = Min(DP[i] + 1,DP[i-1]);
    }
    cout<<DP[1];
    return 0;
}
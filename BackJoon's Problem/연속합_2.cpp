#include<iostream>

using namespace std;
int DP[100001];

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main() {
    int N;
    cin>>N;
    auto arr = new int[N];

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    DP[0] = arr[0];
    int MAX = arr[0];
    for(int i=1;i<N;i++){
        if(DP[i-1]<0){
            DP[i] = arr[i];
        }else{
            DP[i] = DP[i-1]+arr[i];
        }
        MAX = max(DP[i],MAX);
    }

    cout<<MAX;
    return 0;
}
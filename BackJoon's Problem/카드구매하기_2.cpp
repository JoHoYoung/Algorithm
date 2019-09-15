#include<iostream>

using namespace std;
int DP[10001];
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int main() {

    int N;
    cin>>N;

    auto arr = new int[N+1];
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        DP[i] = arr[i];
    }

    DP[0] = 0;

    for(int i=2;i<=N;i++){
        for(int k=0;k<=i/2;k++){
            DP[i] = max(DP[i],DP[i-k] + DP[k]);
        }
    }

//    cout<<endl;
//    for(int i=0;i<=N;i++){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<=N;i++){
//        cout<<DP[i]<<" ";
//    }
//    cout<<endl;
    cout<<DP[N];
    return 0;
}
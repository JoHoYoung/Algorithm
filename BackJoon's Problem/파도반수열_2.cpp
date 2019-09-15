#include<iostream>

using namespace std;
long DP[101];

int main() {

    int T;
    cin>>T;

    auto arr = new int[T];
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for(int i=0;i<T;i++){
        cin>>arr[i];
    }

    for(int i=0;i<T;i++){

        auto N = arr[i];
        for(int i=4;i<=N;i++){
            DP[i] = DP[i-2] + DP[i-3];
        }
        cout<<DP[N]<<endl;
    }
    return 0;
}
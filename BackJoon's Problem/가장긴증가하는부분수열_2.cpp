#include<iostream>

using namespace std;

int DP[1000];
int max(int a, int b){
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

    fill_n(DP,N,1);

    int MAX = 0;
    for(int i=0;i<N;i++){
        int pivot = arr[i];
        bool find = false;
        for(int j=i-1;j>=0;j--){
            if(arr[j] < pivot && DP[j]>=DP[i]){
                DP[i] = DP[j];
                find =true;
            }
        }
        if(find){
            DP[i] += 1;
        }
        MAX = max(MAX,DP[i]);
    }

//    cout<<endl;
//    for(int i=0;i<N;i++){
//        cout<<DP[i]<<" ";
//    }
    cout<<MAX;
    return 0;
}
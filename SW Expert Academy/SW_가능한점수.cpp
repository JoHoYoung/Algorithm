#include<iostream>
#include<set>
#include<vector>

using namespace std;

bool DP[10001] = {false};
int main(){
    int T;
    cin>>T;

    for(int t=0;t<T;t++){
        int N;
        cin>>N;
        auto arr = new int[N];
        int max = 0;

        for(int i =0;i<N;i++){
            int t;
            cin>>t;
            max+=t;
            arr[i] = t;
        }
        DP[0] = 0;
        for(int i=0;i <N;i++){
            for(int j = max;j>=0;j--){
                if(DP[j]){
                    DP[j + arr[i]] = true;
                }
            }
        }

    }
    return 0;
}
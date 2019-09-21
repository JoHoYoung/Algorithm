#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

const int NUM = 1000000007;
long long DP[1001];
int main(){
    int T;
    cin>>T;

    for(int t=0;t<T;t++){
        int N;
        cin>>N;
        DP[0] = 0;
        DP[1] = 0;
        DP[2] = 1;
        long long temp = 1;
        for(int i=3;i<=N;i++){
            temp = temp%NUM;
            temp *= (i-1);
           // cout<<"In i : "<<i<<"float "<<static_cast<int>(floor(i/2))<<" factorial : "<<temp<<endl;
            temp = temp%NUM;
            DP[i] = (((DP[i-1]%NUM)*i)%NUM + (temp * static_cast<int>(floor(i/2)))%NUM)%NUM;
        }
        cout<<"#"<<t+1<<" "<<DP[N]<<endl;
    }
    return 0;
}
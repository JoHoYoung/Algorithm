#include <iostream>
using namespace std;

int DP[1001][1001];
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main() {

    string A;
    string B;
    cin>>A;
    cin>>B;

    auto *Ar = new char[A.size()];
    auto *Br = new char[B.size()];

    for(int i=0;i<A.size();i++){
        char a = A[i];
        for(int j=0;j<B.size();j++){
            char b = B[j];
            if(a==b){
                if(i==0 || j==0){
                    DP[i][j] = 1;
                    continue;
                }
                DP[i][j] = DP[i-1][j-1]+1;
            }else{
                if(i==0&&j==0){
                    DP[i][j] = 0;
                    continue;
                }

                if(i==0){
                    DP[i][j] = DP[i][j-1];
                    continue;
                }
                if(j==0){
                    DP[i][j] = DP[i-1][j];
                    continue;
                }

                DP[i][j] = max(DP[i-1][j],max(DP[i][j-1],DP[i-1][j-1]));
            }
        }
    }
    cout<<DP[A.size()-1][B.size()-1];
}
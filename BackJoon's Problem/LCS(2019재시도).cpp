// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int DP[1000][1000] = {0};

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int main() {

    string A;
    string B;

    cin>>A;
    cin>>B;

    long lenA = A.length();
    long lenB = B.length();

    for(int i=0; i<lenA;i++){
        for(int j=0;j<lenB;j++){
            char chA = A.at(i);
            char chB = B.at(j);
            if(chA == chB){
                if(i==0 || j== 0) {
                    DP[i][j] = 1;
                    continue;
                }
                DP[i][j] = max(DP[i][j-1],DP[i-1][j-1]+1);
            }else{

                if(i==0 && j==0)
                    continue;

                if(i == 0) {
                    DP[i][j] = DP[i][j - 1];
                    continue;
                }

                if(j == 0){
                    DP[i][j] = DP[i-1][j];
                    continue;
                }

                DP[i][j] = max(DP[i-1][j],max(DP[i][j-1],DP[i-1][j-1]));
            }
        }
    }

//    cout<<endl;
//    for(int i=0; i<lenA;i++){
//        for(int j=0;j<lenB;j++){
//
//            cout<<DP[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    cout<<DP[lenA-1][lenB-1];

}

#include <iostream>
using namespace std;

int main() {

    int *DP;
    int N;
    cin>>N;
    DP=new int[N+1];

    DP[0]=1;
    DP[1]=0;
    DP[2]=3;

    for(int i=3;i<=N;i++) {

        if (i % 2 != 0)
            DP[i] = 0;
        else {
            DP[i]=0;
            DP[i] += 3*DP[i-2];
            for(int j=2;i>=2*j;j++)
            DP[i] += 2*DP[i-2*j];
        }
    }
    cout << DP[N];
    return 0;
}
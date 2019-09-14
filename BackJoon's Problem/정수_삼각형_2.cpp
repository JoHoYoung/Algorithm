#include<iostream>

using namespace std;

int map[500][500];

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

// 0으로 끝나는, 1로끝나는 N자리 이친수.
int main() {
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<i+1;j++){
            cin>>map[i][j];
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            map[i][j] += max(map[i+1][j], map[i+1][j+1]);
        }
    }

    cout<<map[0][0];
    return 0;
}
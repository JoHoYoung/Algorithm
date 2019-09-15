#include<iostream>

using namespace std;

int DP[10001][3];

// 0 : �տ��žȸ԰�
// 1 : �տ��� �԰�
// 2 : �ش�ܰ���� ��¶�� �ִ밪.

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

// 0���� ������, 1�γ����� N�ڸ� ��ģ��.
int main() {

    int N;
    cin>>N;

    auto* arr = new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    DP[0][0] = arr[0];
    DP[0][1] = arr[0];
    DP[0][2] = arr[0];

    DP[1][0] = arr[1];
    DP[1][1] = arr[0]+arr[1];
    DP[1][2] = max(DP[1-1][2],max(DP[1][1], DP[1][0]));

    for(int i=2;i<N;i++){
        DP[i][0]= DP[i-2][2] + arr[i];
        DP[i][1]= DP[i-1][0] + arr[i];
        DP[i][2]= max(DP[i-1][2],max(DP[i][1], DP[i][0]));
    }
    cout<<DP[N-1][2];
    return 0;
}
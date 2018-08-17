//문제 2688 줄어들지 않아.

//어떤 숫자가 줄어들지 않는다는 것은 그 숫자의 각 자리 수보다 그 왼쪽 자리 수가 작거나 같을 때 이다.
//
//예를 들어, 1234는 줄어들지 않는다.
//
//줄어들지 않는 4자리 수를 예를 들어 보면 0011, 1111, 1112, 1122, 2223이 있다. 줄어들지 않는 4자리수는 총 715개가 있다.
//
//이 문제에서는 숫자의 앞에 0(leading zero)이 있어도 된다. 0000, 0001, 0002는 올바른 줄어들지 않는 4자리수이다.
//
//n이 주어졌을 때, 줄어들지 않는 n자리 수의 개수를 구하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

long DP[1001][10];

int main()
{
    int N;
    cin>>N;
    int *Arr;
    Arr=new int[N];

    for(int i=0;i<N;i++)
        cin>>Arr[i];

    for(int i=0;i<10;i++)
        DP[0][i]=1;

    for(int q=0;q<N;q++) {
        for (int i = 1; i <= Arr[q]; i++)
            for (int j = 0; j <= 9; j++) {
                DP[i][j] = 0;
                for (int k = j; k <= 9; k++) {
                    DP[i][j] += DP[i - 1][k];
                }
            }
            cout<<DP[Arr[q]][0]<<endl;
    }
    return 0;

}
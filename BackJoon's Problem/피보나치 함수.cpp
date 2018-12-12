//문제 1003 피보나치 함수
// fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.
//
//fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
//fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
//두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
//fibonacci(0)은 0을 출력하고, 0을 리턴한다.
//fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
//첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
//fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
//1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오

#include <iostream>
using namespace std;

long DP[50][2];

//DP[i][0] -> i번째까지 0이 몇번 호출되는지.
//DP[i][1] -> i번째까지 1이 몇번 호출되는지.

// DP[i][1] = DP[i-1][1] + DP[i-2][1];
// DP[i][0] = DP[i-1][0] + DP[i-2][0];
int main()
{

    int N;
    cin>>N;

    int Max= -1;
    int *arr = new int[N];

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];

        if(Max<arr[i])
            Max = arr[i];
    }

    DP[0][0] = 1;
    DP[0][1] = 0;

    DP[1][1] = 1;
    DP[1][0] = 0;

    for(int i=2;i<=Max;i++)
    {
        DP[i][0] = DP[i-1][0] + DP[i-2][0];
        DP[i][1] = DP[i-1][1] + DP[i-2][1];
    }

    for(int i=0;i<N;i++)
    cout<<DP[arr[i]][0]<<" "<<DP[arr[i]][1]<<endl;

    return 0;

}

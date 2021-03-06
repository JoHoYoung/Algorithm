//문제 2579
//계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다.
// <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.
// 예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째, 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다

//계단 오르는 데는 다음과 같은 규칙이 있다.
//
//계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
//연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
//마지막 도착 계단은 반드시 밟아야 한다.
//따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나,
// 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.
//
//각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오
#include <iostream>
using namespace std;
//1층에는 1개, 2층에는 2개 3층에는 4개.. n층에는 2의 n승개의 노드가 있다.
// i층의 n번 노드가 유망하면  i+1층의 2n,2n+1 노드 푸쉬. 0번부터 할거니까 2(n)+1, 2n+2이다 자식은.

// 마지막 계단을 꼭 밟아야 한다.
// 특정 i번째 계단을 밟는경우
// DP[i][?]
// DP[i][0] -> 앞에 계단을 안밟고 i번째를 밟는 경우
// DP[i][1] -> 앞에 계단을 밟고 i번째를 밟는 경우
// DP[i][2] -> i번째 계단을 안밟는경우 -> 앞에거를 밟아야함.
// 연속된 3개의 계단을 밟아서는 안되므로 DP[i][1]의 경우는 DP[i-1][1]의 경우를 제외해야 한다.
// DP[i][0] = Max(DP[i-2][0], DP[i-2][1]) + stairs[i]  -> i-1번째 계단을 밟지 않고 i번째 계단을 밟는 경우 i
// DP[i][1] = DP[i-1][0] + stairs[i]                        -> i-1번째 계단을 밟고 i번째 계단을 밟는 경우 이때 DP[i-1][1]은 고려하지 않는다.

// DP[i][2] =

long Max(long a, long b)
{
    if(a>b)
        return a;
    else return b;
}

long DP[400][3];
int main()
{
    int N;
    cin>>N;

    int *stairs = new int[N];

    for(int i=0;i<N;i++)
    {
        cin>>stairs[i];
    }

    DP[0][0] = stairs[0];
    DP[0][1] = stairs[0];
    DP[0][2] = 0;

    DP[1][0] = stairs[1];
    DP[1][1] = DP[0][0] + stairs[1];
    DP[1][2] = stairs[0];
    for(int i=2;i<N;i++)
    {
        DP[i][0] = Max(DP[i-2][0], DP[i-2][1]) + stairs[i];
        DP[i][1] = DP[i-1][0] + stairs[i];
        DP[1][2] = Max(DP[i-1][0], DP[i-1][1]);
    }

    cout<<Max(DP[N-1][0],DP[N-1][1]);
    return 0;

}

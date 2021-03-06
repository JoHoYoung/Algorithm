//문제 11727 2*N 타일링2
//2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
//
//아래 그림은 2×17 직사각형을 채운 한가지 예이다.
//
//아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
//첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
// 1. 맨앞에 세로짜리 하나인경우
// 2. 맨앞에 가로짜리 두개 인 경우
// 3. 맨앞에 2*2가 있는 경우

// 4칸을 채우는 경우 안에 모든것이 들어있다.  네칸을 기준으로 나누는ㄷ게 맞다
#include <iostream>
using namespace std;

long DP[1005];

int main()
{
    int N;
    cin>>N;

    DP[1] = 1;
    DP[2] = 3;

    for(int i=3;i<=N;i++)
    {
        DP[i] = (DP[i-2]*2 + DP[i-1])%10007;
    }
    cout<<DP[N];
    return 0;
}
//문제 11053 가장 긴 증가하는 부분수
//
//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//
//예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

// 4칸을 채우는 경우 안에 모든것이 들어있다.  네칸을 기준으로 나누는ㄷ게 맞다
#include <iostream>
using namespace std;

long DP[1001];

int main()
{

    int N;
    cin>>N;

    int *arr = new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    DP[0] = 1;

    for(int i = 1 ; i<N;i++)
    {
        int max = -10000;

        for(int j=0;j<i;j++)
        {

            if(arr[j]<arr[i])
                if(DP[j]>max)
                    max = DP[j];

        }

        if(max != -10000) {
            DP[i] = max + 1;
        }else {
            DP[i] = 1;
        }
    }

    int result = -100;

    for(int i=0;i<N;i++)
        if(result<DP[i])
            result = DP[i];

    cout<<result;


}
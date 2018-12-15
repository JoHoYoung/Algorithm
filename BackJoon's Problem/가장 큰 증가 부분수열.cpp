//문제 11055 가장 큰 증가하는 부분수
//수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
//
//예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

#include<iostream>
#include <algorithm>
using namespace std;

int DP[1001];

int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}

int main()
{

    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    DP[0] = arr[0];

    for(int i=1;i<N;i++)
    {
        int Max = 0;
        DP[i] = 0;
        for(int j=i;j>=0;j--)
        {
         if(arr[j]<arr[i]&&DP[j]>Max)
         {
             Max = DP[j];
         }

        }
        DP[i] = Max + arr[i];
      //  cout<<DP[i]<<endl;
    }

    int Max = 0;
    for(int i=0;i<N;i++)
    {
        if(DP[i]>Max)
            Max = DP[i];
    }

    cout<<Max;
    return 0;
}
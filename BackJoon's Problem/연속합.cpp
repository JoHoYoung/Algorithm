//문제 1912 연속합
//n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서
// 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.
//
//예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
// 여기서 정답은 12+21인 33이 정답이 된다.

#include<iostream>
#include<algorithm>
using namespace std;

// 수열에서 i번째 까지 최대 합.. = DP[i]
// DP[i] = DP[i-1]+Arr[i]

int Arr[100000];
long DP[100000];
int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>Arr[i];

    DP[0]=Arr[0];

    for(int i=1;i<n;i++)
    {
        if(DP[i-1]>0)
            DP[i]=DP[i-1]+Arr[i];
        else DP[i]=Arr[i];

    }

    int max=-100000;

    for(int i=0;i<n;i++) {

     //   cout<<DP[i]<<" ";
        if (max < DP[i])
            max = DP[i];
    }
    cout<<endl;
    cout<<max;
    return 0;
}
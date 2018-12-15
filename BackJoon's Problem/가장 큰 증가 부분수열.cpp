//���� 11055 ���� ū �����ϴ� �κм�
//���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

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
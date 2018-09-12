//���� 1912 ������
//n���� ������ �̷���� ������ ������ �־�����. �츮�� �� �� ���ӵ� �� ���� ���� �����ؼ�
// ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. ��, ���� �� �� �̻� �����ؾ� �Ѵ�.
//
//���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����.
// ���⼭ ������ 12+21�� 33�� ������ �ȴ�.

#include<iostream>
#include<algorithm>
using namespace std;

// �������� i��° ���� �ִ� ��.. = DP[i]
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
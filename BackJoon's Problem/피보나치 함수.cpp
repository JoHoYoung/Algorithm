//���� 1003 �Ǻ���ġ �Լ�
// fibonacci(3)�� ȣ���ϸ� ������ ���� ���� �Ͼ��.
//
//fibonacci(3)�� fibonacci(2)�� fibonacci(1) (ù ��° ȣ��)�� ȣ���Ѵ�.
//fibonacci(2)�� fibonacci(1) (�� ��° ȣ��)�� fibonacci(0)�� ȣ���Ѵ�.
//�� ��° ȣ���� fibonacci(1)�� 1�� ����ϰ� 1�� �����Ѵ�.
//fibonacci(0)�� 0�� ����ϰ�, 0�� �����Ѵ�.
//fibonacci(2)�� fibonacci(1)�� fibonacci(0)�� ����� ���, 1�� �����Ѵ�.
//ù ��° ȣ���� fibonacci(1)�� 1�� ����ϰ�, 1�� �����Ѵ�.
//fibonacci(3)�� fibonacci(2)�� fibonacci(1)�� ����� ���, 2�� �����Ѵ�.
//1�� 2�� ��µǰ�, 0�� 1�� ��µȴ�. N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�

#include <iostream>
using namespace std;

long DP[50][2];

//DP[i][0] -> i��°���� 0�� ��� ȣ��Ǵ���.
//DP[i][1] -> i��°���� 1�� ��� ȣ��Ǵ���.

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

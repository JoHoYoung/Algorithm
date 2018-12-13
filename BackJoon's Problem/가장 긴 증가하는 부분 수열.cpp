//���� 11053 ���� �� �����ϴ� �κм�
//
//���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

// 4ĭ�� ä��� ��� �ȿ� ������ ����ִ�.  ��ĭ�� �������� �����¤��� �´�
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
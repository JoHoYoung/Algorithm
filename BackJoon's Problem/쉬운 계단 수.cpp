//���� 10844 ���� ���
//45656�̶� ���� ����.
//�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.
//�����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.
//N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����)

#include<iostream>
using namespace std;

long long DP[101][10];
long long r=1000000000;

int main()
{
    DP[1][0]=0;
    for(int i=1;i<=9;i++)
        DP[1][i]=1;
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)
        for(int j=0;j<=9;j++) {
        if(j==9)
            DP[i][j]=DP[i-1][j-1];
        else if(j==0)
            DP[i][j] = DP[i - 1][j+1];
        else DP[i][j]=(DP[i-1][j-1]+DP[i-1][j+1])%r;
        }

    long long result=0;

    for(int i=0;i<=9;i++)
    {result+=DP[N][i];
    result%=r;
    }

    cout<<result%r<<endl;
    return 0;

}
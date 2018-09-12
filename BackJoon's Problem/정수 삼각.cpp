//���� 1932 ���� �ﰢ
//�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.
//
//�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, ��
// ������ ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. �Ʒ�����
// �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.
//
//�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.
#include<iostream>
#include<algorithm>
using namespace std;

//traingle [0][0]....N������ [N-1][N-1]����
// ���� �� ������� Ǯ�� �ɵ�.

long DP[500][500];
int triangle[500][500];

int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}

int main() {

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
            cin>>triangle[i][j];
    }

    for(int i=N-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(i==N-1)
            {DP[i][j]=triangle[i][j];}
            else
            {
                DP[i][j]=triangle[i][j]+Max(DP[i+1][j],DP[i+1][j+1]);

            }
        }
    }
    cout<<DP[0][0];

    return 0;
}
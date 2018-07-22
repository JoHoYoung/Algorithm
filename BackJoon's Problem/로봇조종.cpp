//���� 2169
//NASA������ ȭ�� Ž�縦 ���� ȭ���� ���� ���� �κ��� ���´�. ���� ȭ���� ����� ������ ����������,
//�κ��� �޸𸮰� �� �� �Ǳ� ������ ������ N��M �迭�� �ܼ�ȭ �Ͽ� �����ϱ�� �Ѵ�.
//
//������ �������� Ư����, �κ��� ������ �� �迭���� ����, ������, �Ʒ������� �̵��� �� ������
//, �������δ� �̵��� �� ����. ���� �� �� Ž���� ����(�迭���� �ϳ��� ĭ)�� Ž������ �ʱ�� �Ѵ�.
//
//������ ������ Ž�� ��ġ�� �ִµ�, �κ��� �迭�� ���� �� (1, 1)���� ��߽��� ������ �Ʒ�
//        (N, M)���� �������� �Ѵ�. �� ��, ���� ������ �����ϸ鼭, Ž���� �������� ��ġ��
//���� �ִ밡 �ǵ��� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include<iostream>
using namespace std;
int N;
int M;
int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int LBig[1003];
int RBig[1003];
int DP[1003][1003];

int main()
{
    cin>>N;
    cin>>M;

    bool visited[N][M];
    int **W;
    W=new int*[N+1];

    for(int i=0;i<=N;i++)
        W[i]=new int[M+1];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> W[i][j];

    DP[1][1]=W[1][1];

    LBig[0]=-100000;
    RBig[M+1]=-100000;

    for(int j=2;j<=M;j++)
        DP[1][j]=DP[1][j-1]+W[1][j];

    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
            LBig[j] = Max(DP[i-1][j],LBig[j-1])+W[i][j];
        for(int j=M;j>=1;j--)
            RBig[j] = Max(DP[i-1][j],RBig[j+1])+W[i][j];
        for(int j=1;j<=M;j++)
            DP[i][j]=Max(LBig[j],RBig[j]);

    }

    cout<<DP[N][M];
        return 0;

}
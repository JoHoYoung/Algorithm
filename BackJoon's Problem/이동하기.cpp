//���� 11048 �̵��ϱ�
//�رԴ� N��M ũ���� �̷ο� �����ִ�. �̷δ� 1��1ũ���� ������ �������� �ְ�, �� �濡�� ������ ������ �ִ�. �̷��� ���� ���� ��
// ���� (1, 1)�̰�, ���� ������ �Ʒ� ���� (N, M)�̴�.
//
//�رԴ� ���� (1, 1)�� �ְ�, (N, M)���� �̵��Ϸ��� �Ѵ�. �ر԰� (r, c)�� ������,
// (r+1, c), (r, c+1), (r+1, c+1)�� �̵��� �� �ְ�, �� ���� �湮�� ������ �濡 �������ִ� ������ ��� ������ �� �ִ�.
// ��, �̷� ������ ���� ���� ����.
//
//�ر԰� (N, M)���� �̵��� ��, ������ �� �ִ� ���� ������ �ִ��� ���Ͻÿ�.
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}
long DP[1000][1000];
int maze[1000][1000];
int main()
{
    int N,M;
    cin>>N;
    cin>>M;

    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) {
                DP[0][0] = maze[0][0];
            } else if (i == 0) {
                DP[i][j] = DP[i][j - 1] + maze[i][j];
            } else if (j == 0) {
                DP[i][j] = DP[i - 1][j] + maze[i][j];
            } else {
                DP[i][j] = max(DP[i - 1][j - 1], max(DP[i - 1][j], DP[i][j - 1])) + maze[i][j];
            }

        }

    }

    cout<<DP[N-1][M-1];

    return 0;
}
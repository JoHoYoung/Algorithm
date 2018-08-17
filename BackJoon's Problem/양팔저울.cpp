////���� 2629
//���� ����� �� ���� �߰� �־����� ��, �̸� �̿��Ͽ� �Է����� �־��� ������ ���Ը� Ȯ����
//�� �ִ����� �����Ϸ��� �Ѵ�.
//
//���԰� ���� 1g�� 4g�� �� ���� �߰� ���� ���, �־��� ������ 1g �� �ϳ��� ����
//������ ���ʿ� ���� �÷����� ������ �̷�� ������ ���Դ� 1g�̴�. �� �ٸ� ������ 4g������ Ȯ���Ϸ���
//1g �� ��� 4g �߸� �÷������� �ȴ�.
//
//������ 3g�� ��� �Ʒ� <�׸� 1>�� ���� ������ �߸� �÷������� ���� ������ ������ �̷�� �ȴ�.
//���� ���� 1g�� 4g�� �߰� �ϳ��� ���� ��� �־��� ������ 3g������ Ȯ���� �� �� �ִ�.

#include<iostream>
#include<math.h>

using namespace std;
int DP[35][15000];

int BeadNum;
int CaseNum;

int *Beads;
int *Case;


int main()
{

    cin>>BeadNum;

    Beads=new int[BeadNum];

    for(int i=0;i<BeadNum;i++)
        cin>>Beads[i];

    cin>>CaseNum;

    Case=new int[CaseNum];

    for(int i=0;i<CaseNum;i++)
        cin>>Case[i];

    DP[0][0]=1;
    DP[0][Beads[0]]=true;
    for(int i=1;i<BeadNum;i++)
    for(int j=0;j<=15000;j++)
    {
        if(DP[i-1][j]==1)
        {
            DP[i][j]=true;
            DP[i][j+Beads[i]]=true;

            DP[i][abs(j-Beads[i])]=true;

        }

    }

    for(int i=0;i<CaseNum;i++)
    {

        if(DP[BeadNum-1][Case[i]]==true)
            cout<<"Y"<<" ";
        else cout<<"N"<<" ";
    }


    return 0;

}
////문제 2629
//양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할
//수 있는지를 결정하려고 한다.
//
//무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를 양팔
//저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다. 또 다른 구슬이 4g인지를 확인하려면
//1g 추 대신 4g 추를 올려놓으면 된다.
//
//구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 수평을 이루게 된다.
//따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.

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
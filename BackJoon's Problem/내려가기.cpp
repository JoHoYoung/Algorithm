//문제 2096
//N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데
// , 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.
//
//먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고
// 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다.
// 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할
// 수 있다는 것이다. 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.
//
//별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수
// 있는 위치이며, 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 숫자표가 주
// 어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오.
// 점수는 원룡이가 위치한 곳의 수의 합이다.

#include<iostream>
using namespace std;

int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;

}

int Min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}

int Map[100000][3];
int MaxMap[3];
int MinMap[3];

int main() {

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>Map[i][0];
        cin>>Map[i][1];
        cin>>Map[i][2];
    }

    MaxMap[0]=Map[0][0];
    MaxMap[1]=Map[0][1];
    MaxMap[2]=Map[0][2];

    MinMap[0]=Map[0][0];
    MinMap[1]=Map[0][1];
    MinMap[2]=Map[0][2];

    for(int i=1;i<N;i++)
    {
        int temp1,temp2,temp3,temp4,temp5,temp6;

        temp1=MaxMap[0];
        temp2=MaxMap[1];
        temp3=MaxMap[2];
        MaxMap[0]=Max(MaxMap[0],MaxMap[1])+Map[i][0];
        MaxMap[1]=Max(temp1,Max(temp2,temp3))+Map[i][1];
        MaxMap[2]=Max(temp2,temp3)+Map[i][2];

        temp4=MinMap[0];
        temp5=MinMap[1];
        temp6=MinMap[2];

        MinMap[0]=Min(MinMap[0],MinMap[1])+Map[i][0];
        MinMap[1]=Min(temp4,Min(temp5,temp6))+Map[i][1];
        MinMap[2]=Min(temp5,temp6)+Map[i][2];

    }

    cout<<Max(MaxMap[0],Max(MaxMap[1],MaxMap[2]))<<" "<<Min(MinMap[0],Min(MinMap[1],MinMap[2]));

    return 0;
}
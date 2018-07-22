//문제 14501
//상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
//
//오늘부터 N+1일째 되는날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
//
//백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.
//
//각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
//
//N = 7인 경우에 다음과 같은 상담 일정표를 보자.
//
//1일에 잡혀있는 상담은 총 3일이 걸리며, 상담했을 때 받을 수 있는 금액은 10이다. 5일에 잡혀있는 상담은 총 2일이 걸리며, 받을 수 있는 금액은 15이다.
//
//상담을 하는데 필요한 기간은 1일보다 클 수 있기 때문에, 모든 상담을 할 수는 없다. 예를 들어서 1일에 상담을 하게 되면, 2일, 3일에 있는 상담은 할 수 없게 된다.
//2일에 있는 상담을 하게 되면, 3, 4, 5, 6일에 잡혀있는 상담은 할 수 없다.
//
//또한, N+1일 째에는 회사에 없기 때문에, 6, 7일에 있는 상담을 할 수 없다.
//
//퇴사 전에 할 수 있는 상담의 최대 이익은 1일, 4일, 5일에 있는 상담을 하는 것이며, 이 때의 이익은 10+20+15=45이다.
//
//상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;


int N;
int maxprofit = 0;
int max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
//1일차는 인덱스 0번부터
int knap(int i,int capacity,int *T,int *P,int *W)
{
    //cout<<"capacity : "<<capacity<<endl;
    if(i==-1)
        return 0;

    if(T[i]<=capacity)
    {
        W[i]=max(P[i]+knap(i-1,1,T,P,W),knap(i-1,capacity+1,T,P,W));
    }
    else W[i]=knap(i-1,capacity+1,T,P,W);

    return W[i];
}

int main()
{

    cin>>N;

    int *T=new int[N];
    int *P=new int[N];
    int *W=new int[N];
    for(int i=0;i<N;i++)
        W[i]=0;
    int world[N][N];
    for(int i=0;i<N;i++)
    {
        cin>>T[i];
        cin>>P[i];
    }
    cout<<knap(N-1,1,T,P,W);

    return 1;
}
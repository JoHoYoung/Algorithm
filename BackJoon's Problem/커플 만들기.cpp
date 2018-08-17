//문제 2688 커플 만들기.
//여자친구가 없는 남자 n명과 남자친구가 없는 여자 m명을 불러 모아서 이성 친구를 만들어 주기로 하였다.
// 하지만 아무렇게나 해줄 수는 없고, 최대한 비슷한 성격의 사람들을 짝 지어 주기로 하였다.
//
//당신은 뭔가 알 수 없는 방법으로 각 사람의 성격을 수치화 하는데 성공하였다. 따라서 각 사람의
// 성격은 어떤 정수로 표현된다. 이와 같은 성격의 수치가 주어졌을 때, 우선 최대한 많은 커플을 만들고,
// 각 커플을 이루는 두 사람의 성격의 차이의 합이 최소가 되도록 하려 한다. 남자-여자 커플만 허용된다.
#include<iostream>
#include<algorithm>
#include<cmath>
long DP[1000][1000];
using namespace std;

int Min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}

int dif(int a,int b)
{
    return abs(a-b);
}

int main()
{
    int N;
    int M;
    cin>>N;
    cin>>M;

    int *male;
    int *female;
    male=new int[N];
    female=new int[M];

    for(int i=0;i<N;i++)
        cin>>male[i];

    for(int i=0;i<M;i++)
        cin>>female[i];

    sort(male,male+N);
    sort(female,female+M);

    int smaller;
    int bigger;

    int *small;
    int *big;

    if(N>=M)
    {
        smaller=M;
        bigger=N;

        small=new int[M];
        for(int i=0;i<M;i++)
            small[i]=female[i];

        big=new int[N];
        for(int i=0;i<N;i++)
            big[i]=male[i];

    }else{

        smaller=N;
        bigger=M;

        small=new int[N];
        for(int i=0;i<N;i++)
            small[i]=male[i];

        big=new int[M];
        for(int i=0;i<M;i++)
            big[i]=female[i];

    }

    DP[smaller-1][bigger-1]=abs(big[bigger-1]-small[smaller-1]);
    //DP[i][j] 에서 i는 작은배열 j는 큰 배열//
    int step=-1;
    for(int j=smaller-1;j>=0;j--) {
        step++;

        for (int i = bigger - 1-step; i >= j; i--)
        {   if(j==smaller-1)
            {if(i==bigger-1-step)
                DP[j][i]=dif(big[i],small[j]);
            else
                    DP[j][i] = Min(dif(big[i], small[j]), DP[j][i + 1]);
                }else{
                if(i==bigger-1-step)
                    DP[j][i]=dif(big[i],small[j])+DP[j+1][i+1];
                else{
                    DP[j][i] = Min(dif(big[i], small[j]),DP[j][i+1]);
                    if(i==j)
                        DP[j][i]+=DP[j+1][i+1];

                }
            }
        }
    }
    cout<<DP[0][0];

    return 0;
}
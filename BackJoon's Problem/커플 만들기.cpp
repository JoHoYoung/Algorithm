//���� 2688 Ŀ�� �����.
//����ģ���� ���� ���� n��� ����ģ���� ���� ���� m���� �ҷ� ��Ƽ� �̼� ģ���� ����� �ֱ�� �Ͽ���.
// ������ �ƹ����Գ� ���� ���� ����, �ִ��� ����� ������ ������� ¦ ���� �ֱ�� �Ͽ���.
//
//����� ���� �� �� ���� ������� �� ����� ������ ��ġȭ �ϴµ� �����Ͽ���. ���� �� �����
// ������ � ������ ǥ���ȴ�. �̿� ���� ������ ��ġ�� �־����� ��, �켱 �ִ��� ���� Ŀ���� �����,
// �� Ŀ���� �̷�� �� ����� ������ ������ ���� �ּҰ� �ǵ��� �Ϸ� �Ѵ�. ����-���� Ŀ�ø� ���ȴ�.
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
    //DP[i][j] ���� i�� �����迭 j�� ū �迭//
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
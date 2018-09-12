//���� 2294
//n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. �� �������� ������ ����ؼ�,
// �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�.
// (������ ������ ��� ����� �� �ִ�.)

#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
long DP[10001];
//������� ��� ���� or ��� �������� ��� ����?

int Min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}

int main() {

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>coin[i];

    sort(coin+1,coin+n+1);


    DP[0]=0;
    for(int i=1;i<=k;i++)  //i��. 0������.. k������
    {
        DP[i]=1000000000;
        for(int j=1;j<=n;j++) //1��° ��������.. n��° ��������.
        {

            if(i>=coin[j]&&DP[i-coin[j]]!=1000000000)
            {
                DP[i]=Min(DP[i],DP[i-coin[j]]+1);
          //      cout<<"DP["<<i<<"] : "<<DP[i];
            }

        }


    }
    if(DP[k]==1000000000)
        cout<<-1;
    else cout<<DP[k];

    return 0;
}
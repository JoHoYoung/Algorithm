//문제 2294
//n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서,
// 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다.
// (각각의 동전은 몇개라도 사용할 수 있다.)

#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
long DP[10001];
//몇원까지 몇개의 동전 or 몇개의 동전으로 몇원 까지?

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
    for(int i=1;i<=k;i++)  //i원. 0원부터.. k원까지
    {
        DP[i]=1000000000;
        for(int j=1;j<=n;j++) //1번째 동전부터.. n번째 동전까지.
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
//문제 2294
//n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서,
// 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다.
// (각각의 동전은 몇개라도 사용할 수 있다.)

#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
long DP[101][10001];
//몇원까지 몇개의 동전 or 몇개의 동전으로 몇원 까지?

int Min(int a,int b)
{
    if(a==0)
        return b;

    if(b==0)
        return a;

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

//    for(int i=1;i<=n;i++)
//        cout<<coin[i]<<endl;
//
   // cout<<"AAAA"<<5%1<<endl;
    for(int i=1;i<=n;i++)//동전
    {
        for(int j=1;j<=k;j++)//가격
        {
            //DP[i][j] - > i번째 동전까지 고려, j원을 채우는 경우
            /////////초기값 설정, 은 i번째 코인으로 최대한 채우는 것///////////////////
           // cout<<"J : "<<j<<endl;
           if(j<coin[i])// 현재 계산할 가격이 현재 고려할 동전의 가격보다 크면
           {
       //        cout<<"그냥 채택 은 이걸 더함 : DP["<<i-1<<"]["<<j<<"] : "<<DP[i-1][j]<<endl;
               DP[i][j] = DP[i - 1][j]; //이전 동전까지 고려한 것의 값을 대입

           }
           else{
         //      cout<<"나눠 지는거 : "<<j<<", 나눌 거 : "<<coin[i]<<", 값 : "<<j%coin[i]<<endl;
               if((j%coin[i])==0)
               {
                   ///cout<<" I : "<<i<<endl;
                   DP[i][j]=j/coin[i];
            //       cout<<j<<" "<<DP[i][j]<<endl;
               }
               else if(DP[i-1][j%coin[i]]!=0)//지금 코인으로 다 채우고 남은것을 채울 수 있는경우에는..
               {
           //        cout<<"이거실행! 더해지는 값 : "<<DP[i-1][j%coin[i]]<<" ";
                   DP[i][j]=j/coin[i]+DP[i-1][j%coin[i]];
          //         cout<<j<<" "<<DP[i][j]<<endl;
               }
               else{
                   DP[i][j]=DP[i-1][j];  //아닌 경우에는 그 이전코인으로 채운 값을 대입.
        //           cout<<j<<" "<<DP[i][j]<<endl;
               }

               }
               //초기값 설정 후 계산과정.//////////////////////////////////////////
            if(i!=1){
             for(int q=1;q<=j;q++)
             {
                //i번째 동전으로 다 채운 경우와 i-k번째 동전까지 다 채운 경우를 ..비교..
                 if((((j-q)%coin[i])==0)&&(DP[i-1][q]!=0)){
                            //if((DP[i][j]==0)||(DP[i][j]> (DP[i - 1][q] + (j - q) / coin[i]))
                             //   cout<<"이거 임? "<<DP[i-1][q]<<" + "<<j-q<<" 나누기 "<<coin[i];
                            DP[i][j] = Min(DP[i][j], DP[i - 1][q] + (j - q) / coin[i]);
                        }
             }}

       //      cout<<"처리 값 : "<<DP[i][j]<<endl;
        }

    }

    cout<<DP[n][k];



    return 0;
}
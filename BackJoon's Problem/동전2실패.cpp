//���� 2294
//n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. �� �������� ������ ����ؼ�,
// �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�.
// (������ ������ ��� ����� �� �ִ�.)

#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
long DP[101][10001];
//������� ��� ���� or ��� �������� ��� ����?

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
    for(int i=1;i<=n;i++)//����
    {
        for(int j=1;j<=k;j++)//����
        {
            //DP[i][j] - > i��° �������� ���, j���� ä��� ���
            /////////�ʱⰪ ����, �� i��° �������� �ִ��� ä��� ��///////////////////
           // cout<<"J : "<<j<<endl;
           if(j<coin[i])// ���� ����� ������ ���� ����� ������ ���ݺ��� ũ��
           {
       //        cout<<"�׳� ä�� �� �̰� ���� : DP["<<i-1<<"]["<<j<<"] : "<<DP[i-1][j]<<endl;
               DP[i][j] = DP[i - 1][j]; //���� �������� ����� ���� ���� ����

           }
           else{
         //      cout<<"���� ���°� : "<<j<<", ���� �� : "<<coin[i]<<", �� : "<<j%coin[i]<<endl;
               if((j%coin[i])==0)
               {
                   ///cout<<" I : "<<i<<endl;
                   DP[i][j]=j/coin[i];
            //       cout<<j<<" "<<DP[i][j]<<endl;
               }
               else if(DP[i-1][j%coin[i]]!=0)//���� �������� �� ä��� �������� ä�� �� �ִ°�쿡��..
               {
           //        cout<<"�̰Ž���! �������� �� : "<<DP[i-1][j%coin[i]]<<" ";
                   DP[i][j]=j/coin[i]+DP[i-1][j%coin[i]];
          //         cout<<j<<" "<<DP[i][j]<<endl;
               }
               else{
                   DP[i][j]=DP[i-1][j];  //�ƴ� ��쿡�� �� ������������ ä�� ���� ����.
        //           cout<<j<<" "<<DP[i][j]<<endl;
               }

               }
               //�ʱⰪ ���� �� ������.//////////////////////////////////////////
            if(i!=1){
             for(int q=1;q<=j;q++)
             {
                //i��° �������� �� ä�� ���� i-k��° �������� �� ä�� ��츦 ..��..
                 if((((j-q)%coin[i])==0)&&(DP[i-1][q]!=0)){
                            //if((DP[i][j]==0)||(DP[i][j]> (DP[i - 1][q] + (j - q) / coin[i]))
                             //   cout<<"�̰� ��? "<<DP[i-1][q]<<" + "<<j-q<<" ������ "<<coin[i];
                            DP[i][j] = Min(DP[i][j], DP[i - 1][q] + (j - q) / coin[i]);
                        }
             }}

       //      cout<<"ó�� �� : "<<DP[i][j]<<endl;
        }

    }

    cout<<DP[n][k];



    return 0;
}
//문제 2662 기업투자
//어떤 투자가가 여러 기업들에게 돈을 투자해서 최대의 이익을 얻고자 한다.
// 단, 투자는 만원 단위로 할 수 있으며 각 기업은 많이 투자할수록 많은
// 이익을 투자가에게 돌려준다. 돈을 투자하지 않은 경우는 당연히 얻게
// 되는 이익도 없다. 예를 들어서, 한 투자가가 4만원을 갖고 두 개의
// 기업들에 각각 만원 단위로 투자했을 경우 얻을 수 있는 이익은 다음과 같다.

//위의 경우 만일, 기업 A에 1만원, 기업 B에 3만원을 투자하는 경우 투자가가 얻는
// 이익은 14만원(5만원+9만원)이다. 4만원을 투자해서 가장 많은 이익을 얻을 경우
// 기업 B에만 4만원을 투자하는 경우로서 이때의 이익은 15만원이다. 여기서 투자가는 한
// 기업에 돈을 나누어 투자할 수는 없다.
//
//투자액이 정해져 있고, 기업의 개수와 각 기업에 투자했을 경우에 얻게 되는 이익이 주
// 어졌을 때 가장 많은 이익을 얻을 수 있는 투자방식과 이때의 이익금을 구하는 프로그램을 작성하라.

//가방 채우기랑 비슷한 문제.
//DP[i][j]는 가방용량이 i고 j번째 기업까지 고려했을때.


#include<iostream>
#include<algorithm>
using namespace std;

long chart[301][21];
long DP[301][21];

long check[301][21][21];
// check[N][M] = 투자금액이 N원일때 M번째 기업에게는 얼마를


int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}

int main() {

    int buffer;

    int N,M;
    cin>>N>>M;

////////입력 부분/////////////////////////
    for(int i=1;i<=N;i++)
    {cin>>buffer;
        for(int j=1;j<=M;j++)
        {

            cin>>chart[i][j];
        }
    }
/////////////////////////////////


    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            //cout<<"총금액이 "<<i<<"이고 "<<j<<"번째 기업까지 고려한 경우"<<endl;
            if(j==1) {

                DP[i][j]=chart[i][j];
                for(int q=1;q<=M;q++)
                    check[i][q][j]=0;

                check[i][1][1]=i;

            }else {

                if(chart[i][j]>DP[i][j-1])
                {
                 //   cout<<"j : "<<j<<" 일때 ";
                    for(int q=1;q<=M;q++)
                        check[i][q][j]=0;

               //     cout<<"체크 초기값 설정"<<endl;
                    check[i][j][j]=i;
                }
                else {
                    for(int q=1;q<=M;q++)
                        check[i][q][j]=check[i][q][j-1];

                }

                DP[i][j] = Max(DP[i][j - 1], chart[i][j]);
            }

            for(int k=1;k<i;k++)
            {

                if(j!=1)
                {if((DP[k][j-1]+chart[i-k][j])>DP[i][j]) {

  //                  cout<<"총금액이 "<<i<<"이고 "<<j<<"번째 기업까지 고려한 경우"<<endl;
//                    cout<<"총 금액이 "<<k<<"이고 "<<j-1<<"번째 고려를 채택"<<endl<<"그때의 체크는"<<endl;

//                        for(int q=1;q<=M;q++)
//                            cout<<check[k][q][j-1];
//
//                        cout<<endl;

                    for(int q=1;q<=M;q++)
                        check[i][q][j]=check[k][q][j-1];

                    check[i][j][j] = i - k; //총 투자금이 i일때 j번째 회사에는 얼마
                }

                DP[i][j]=Max(DP[i][j],DP[k][j-1]+chart[i-k][j]);
            }
            }

        }
//        for(int i=1;i<=M;i++) {
//            for (int j = 1; j <= N; j++)
//                cout << DP[j][i] << endl;
//
//            cout<<endl;
//        }

    cout<<DP[N][M]<<endl;
    for(int i=1;i<=M;i++) {

        cout << check[N][i][M];
        if(i!=M)
            cout<<" ";
    }
    cout<<endl;


    return 0;
}
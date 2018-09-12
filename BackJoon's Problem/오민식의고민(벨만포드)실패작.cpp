//문제 1219 오민식의 고민
//오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.
//
//오민식은 고민에 빠졌다.
//
//어떻게 하면 최대 이윤을 낼 수 있을까
//
//이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다.
// 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.
//
//오민식이 이용할 수 있는 교통수단은 여러 가지가 있다. 오민식은 모든 교통수단의
// 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다. 게다가, 오민식은 각각의
// 도시를 방문할 때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 다르며, 액수는
// 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.
//
//오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이
// 최댓값을 구하는 프로그램을 작성하시오.
//
//오민식이 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가
// 음수가 될 수도 있다. 또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다
// 돈을 벌게 된다. 모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러번 이용할 수도 있다.

#include <iostream>

using namespace std;

int city[100];
int traffic[100][3];

int Root[100][100];

int DP[105][105];
//DP[N][M] N번도시에 도착 M번 경유해서.
//DP[0][1] 0번도시에 서있다. 교통수단 한번만 타고.
//DP[0][2] 0번도시에 서있다. 교통수단 두번만 타고.
//DP[4][3] 4번도시에 서있다. 교통수단 두번만 타고.

#define INF 3000000

int Max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
//traffic [0] : 출발, [1] : 도착, [2] : 교통비
//교통비가 작은 것..만 타는게 좋고 도시돈을 많이 주는 곳을 가야함.
//도착도시의 가격... 도착도시에서 주는돈 - 교통비를 그 루트를 선택했을때의 비용(+,-)
int main(void)
{
    bool Gee=false;

    int N,S,E,M;
    cin>>N>>S>>E>>M;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            Root[i][j]=INF;
        }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>traffic[i][j];

        }
        if(Root[traffic[i][0]][traffic[i][1]]>(traffic[i][2]))
        {Root[traffic[i][0]][traffic[i][1]]=traffic[i][2];}

    }

    for(int i=0;i<N;i++)
        cin>>city[i];

    ////////입력//////////////

    //출발지는 S,
    //Root[S][x]...?

    //도착지는 E, 돈의 액수의 최댓값.
    //Root[x][E] ..?
    for(int i=0;i<=M;i++)
        for(int j=0;j<=M;j++)
            DP[i][j]=INF;

    DP[S][0]=city[S];

    for(int i=0;i<N;i++) {

        cout<<" i : "<<i<<endl;
        for (int j = 1; j <= M+5; j++) {
            cout<<"j : "<<j<<endl;
            //i번도시에 서있다. 교통수단 j번 이용해서.
                   for(int k = 0;k<N;k++)
                   {
                       if((DP[k][j-1]!=INF)&&(Root[k][i]!=INF)) {

                           if(DP[i][j]!=INF)
                               DP[i][j]=Max(DP[i][j],DP[j][j-1]-Root[k][i]+city[i]);
                           else
                           DP[i][j] = DP[k][j - 1] - Root[k][i] + city[i];

                           cout<<"갱신 : "<<DP[k][j-1]<<" - "<<Root[k][i]<<" = "<<DP[i][j]<<endl;

                           if(k==i)
                           {
                               cout<<"켜~";
                               Gee=true;}
                       }
                   }


        }
    }
    //cout<<"키키 : "<<DP[4][3]<<endl;

    int max=-INF;

    //cout<<"검사";

//    for(int i=0;i<N;i++)
//    {
//        if((DP[i][M+1]!=INF)&&(DP[i][M+1]>0))
//        {
//            Gee=true;
//        break;
//    }}

    if(Gee)
    {cout<<"Gee";}
    else {
        for (int i = 0; i < M; i++)
        {
      //      cout<<DP[E][i]<<endl;
            if((max<DP[E][i])&&(DP[E][i]!=INF))
               max=DP[E][i];}
               if(max==-INF)
                   cout<<"gg";
        else cout<<max;

    }
    return 0;
}
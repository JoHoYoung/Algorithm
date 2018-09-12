//���� 1219 ���ν��� ���
//���ν��� ��������̴�. ���ν��� ȸ�� ������� ���νĿ��� ������ �ִ��� ���� �ȾƼ� �ִ� ������ ������ �ߴ�.
//
//���ν��� ��ο� ������.
//
//��� �ϸ� �ִ� ������ �� �� ������
//
//�� ���󿡴� N���� ���ð� �ִ�. ���ô� 0������ N-1������ ��ȣ �Ű��� �ִ�.
// ���ν��� ������ A���ÿ��� �����ؼ� B���ÿ��� ������.
//
//���ν��� �̿��� �� �ִ� ��������� ���� ������ �ִ�. ���ν��� ��� ���������
// ��� ���ÿ� ���� ���ø� �˰� �ְ�, ��뵵 �˰� �ִ�. �Դٰ�, ���ν��� ������
// ���ø� �湮�� ������ �� �� �ִ� ���� �˰��ִ�. �� ���� ���ø��� �ٸ���, �׼���
// �����Ǿ��ִ�. ��, ���ø� �湮�� ������ �� ���� ���� �ȴ�.
//
//���ν��� ���� ���ÿ� ������ ��, ������ �ִ� ���� �׼��� �ִ�� �Ϸ��� �Ѵ�. ��
// �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//���ν��� ���� ������ ���� ���� ���ٸ�, ���� ���ÿ� ������ �� ������ �ִ� ���� �׼���
// ������ �� ���� �ִ�. ��, ���� ���ø� ���� �� �湮�� �� ������, �� ���ø� �湮�� ������
// ���� ���� �ȴ�. ��� ���� ������ �Է����� �־��� �������θ� �̿��� �� ������, ������ �̿��� ���� �ִ�.

#include <iostream>

using namespace std;

int city[100];
int visited[100];
int traffic[100][3];

int Root[100][100];
int cost[100][100];
int D[100][100];

int DP[105][105];
//DP[N][M] N�����ÿ� ���� M�� �����ؼ�.
//DP[0][1] 0�����ÿ� ���ִ�. ������� �ѹ��� Ÿ��.
//DP[0][2] 0�����ÿ� ���ִ�. ������� �ι��� Ÿ��.
//DP[4][3] 4�����ÿ� ���ִ�. ������� �ι��� Ÿ��.

#define INF 3000000

int Max(int a,int b)
{
    if(a==INF)
        return b;

    if(b==INF)
        return a;

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
//traffic [0] : ���, [1] : ����, [2] : �����
//����� ���� ��..�� Ÿ�°� ���� ���õ��� ���� �ִ� ���� ������.
//���������� ����... �������ÿ��� �ִµ� - ����� �� ��Ʈ�� ������������ ���(+,-)
int main(void)
{
    bool Gee=false;

    int N,S,E,M;
    cin>>N>>S>>E>>M;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            cost[i][j]=0;
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

    ////////�Է�//////////////

    //������� S,
    //Root[S][x]...?

    //�������� E, ���� �׼��� �ִ�.
    //Root[x][E] ..?
    for(int i=0;i<=M;i++)
        for(int j=0;j<=M;j++)
            DP[i][j]=INF;

    DP[S][0]=city[S];

    for(int j=1;j<=M;j++) {

     //   cout<<" �̵�Ƚ�� : "<<j<<endl;
        for (int i = 0; i < N; i++) {
        //    cout<<"���ù�ȣ : "<<i<<endl;
            //i�����ÿ� ���ִ�. ������� j�� �̿��ؼ�.
                   for(int k = 0;k<N;k++)
                   {
                       if((DP[k][j-1]!=INF)&&(Root[k][i]!=INF)) {

                           if(DP[i][j]!=INF)
                               DP[i][j]=Max(DP[i][j],DP[k][j-1]-Root[k][i]+city[i]);
                           else
                           DP[i][j] = DP[k][j - 1] - Root[k][i] + city[i];

                 //          cout<<"���� : "<<DP[k][j-1]<<" - "<<Root[k][i]<<" + "<<city[i]<<" = "<<DP[i][j]<<endl;

                          // cout<<"K : "<<k<<", I :"<<i<<endl;
                           //cost[k][i]+=(city[i]-Root[k][i]);
                         //  if(visited[k]==1&&(-Root[k][i]+city[i])>0)
                          // {
                            //   cout<<"��~";
                              // Gee=true;}
                       }
                     //  visited[i]=1;
                   }


        }
    }
    //���� ����Ŭ �˻�..................���� ����Ŭ....���� ����Ŭ�� �ִ��� �˻����� Root[i][j]�� i����
            //����Ͽ� j�� �����ϴ� ����ġ �϶�.....
    //

            //Floyd�� ���� ����Ŭ �˻�.
            for(int i=0;i<N;i++)//N-1�� ������ N-1���ϱ� �ݺ�.
                for(int j=0;j<N;j++)
                {
                    if(Root[i][j]!=INF)
                    D[i][j]=(-Root[i][j]+city[j]);
                    else D[i][j]=INF;

                    //cout<<D[i][j]<<endl;
                }

            for(int k=0;k<N;k++)
                for(int i=0;i<N;i++)
                {

                    for(int j=0;j<N;j++) {
                        if(D[i][k]!=INF&&D[k][j]!=INF) {
                       //     cout<<k<<" �� ���ļ� "<<i<<" ���� "<<j<<"�� ���� ��"<<endl;
                            if(D[i][j]==INF)
                                D[i][j]=D[i][k]+D[k][j];

                            D[i][j] = D[i][k]+D[i][j];
                        }
                    }
                }
               // -3,+3,-2,+3
                for(int i=0;i<N;i++)
                {
              //      cout<<"i : "<<i<<" "<<endl;
               //     cout<<D[i][i]<<endl;
                    if((D[i][i]>0)&&DP[i][i]!=INF)
                        Gee=true;
                }



    int max=-INF;

    //cout<<"�˻�";

//    for(int i=0;i<N;i++)
//    {
//        if((DP[i][M+1]!=INF)&&(DP[i][M+1]>0))
//        {
//            Gee=true;
//        break;
//    }}

    for (int i = 0; i < M; i++)
    {
        //      cout<<DP[E][i]<<endl;
        if((max<DP[E][i])&&(DP[E][i]!=INF))
            max=DP[E][i];}
    if(max==-INF) {
        cout << "gg";
        return 0;
    }

    if(Gee)
    {cout<<"Gee";}
    else {
        for (int i = 0; i < M; i++)
        {
      //      cout<<DP[E][i]<<endl;
            if((max<DP[E][i])&&(DP[E][i]!=INF))
               max=DP[E][i];}
         cout<<max;
    }
    return 0;
}
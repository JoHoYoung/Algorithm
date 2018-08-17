//���� 9465 ���� ū ���簢��
//n��m�� 0, 1�� �� �迭�� �ִ�. �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include<iostream>
using namespace std;

int DP[1003][1003];
//���簢�� ���ϱ�.. �� �� �Ʒ�.. �簢�� �ȿ��� ���� 1�̾�� �Ѵ�.
// ���� 1.. �� ���� pivot���� ����, �Ʒ� ���ӵ� 1�� ������ ��� ���Ѵ�?
// ������ ���� ���������� ���� �� 1���� , �Ʒ��� ���� �� 1������ ����
// ��� ���� ������, �Ʒ��� ������ 1�� ���� ����.
// ���������� ���鼭 ������ ���� ���� �� ������ ����.... 4��üũ, 9��üũ, �ð����⵵ n^2�̴�...
// ���ο���, ���ο��� ���س��´�. ���鼭 ���ο���, ���ο��� ũ�� ������Ʈ.
// ���������� ���鼭 ���ο��� üũ depth�� i�̸� ���������� ���鼭 ���ο����� i���� �Ѵ�. ���� ū�� ��
// pivot�� ����. pivot�� ���� �Ǻ��� ������. �������� ��ù��°... -> ���� depth �� i�̸� ���ο��ӵ�
// i�̻� �̾���Ѵ�.

int N;
int M;

int **Arr;

int getColcount(int rowidx,int colidx)
{
    if(Arr[rowidx][colidx]==0)
        return 0;
    if(colidx>=M-1)
        return 1;

    int colcount=0;
    while(Arr[rowidx][colidx]!=0&&(colidx<M)) {
        colidx++;
        colcount++;
        if(colidx>=M)
            break;
    }
    return colcount;
}

int getRowcount(int rowidx,int colidx)
{
    if(Arr[rowidx][colidx]==0)
        return 0;

    if(rowidx>=N-1)
        return 1;

    int rowcount=0;
    while(Arr[rowidx][colidx]!=0&&(rowidx<N)) {
        rowidx++;
        rowcount++;
        if(rowidx>=N)
            break;
    }
    return rowcount;
}

int Min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}

int main()
{
    cin>>N;
    cin>>M;
    Arr=new int*[N];
    for(int i=0;i<N;i++)
        Arr[i]=new int[M];

    string num[N];
        for(int j=0;j<N;j++)
            cin>>num[j];

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) {
                Arr[i][j] = num[i].at(j)-48;
              //  cout<<"����"<<Arr[i][j];
            }
    int count=0;
    int rowcount=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            int row=i;
            int col=j;
            if(Arr[i][j]!=0)
            {
                count = Min(getRowcount(i,j),getColcount(i,j));
                DP[i][j]=count;

                if(count!=0){
                int idx=1;
                while(idx<=count-1)
                    if(DP[i][j] <= idx + 1)
                    {    DP[i][j] = Min(DP[i][j], getColcount(i + (idx++), j));
                }else break;
                }
            }
            else DP[i][j]=0;
        }

        int max=-100000;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(DP[i][j]>max)
                max=DP[i][j];

    cout<<max*max;

    return 0;

}
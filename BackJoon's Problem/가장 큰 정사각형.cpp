//문제 9465 가장 큰 정사각형
//n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int DP[1003][1003];
//정사각형 구하기.. 음 위 아래.. 사각형 안에가 전부 1이어야 한다.
// 전부 1.. 한 점을 pivot으로 가로, 아래 연속된 1의 갯수를 모두 구한다?
// 한점을 기준 오른쪽으로 가장 긴 1연속 , 아래로 가장 긴 1연속의 갯수
// 모든 점당 오른쪽, 아랫쪽 연속한 1의 갯수 저장.
// 오른쪽으로 가면서 이전의 점을 포함 할 것인지 결정.... 4개체크, 9개체크, 시간복잡도 n^2이다...
// 가로연속, 세로연속 구해놓는다. 가면서 가로연속, 세로연속 크기 업데이트.
// 오른쪽으로 가면서 세로연속 체크 depth가 i이면 오른쪽으로 가면서 세로연속이 i여야 한다. 제일 큰거 를
// pivot에 저장. pivot은 각각 피봇의 세로줄. 세로줄의 맨첫번째... -> 세로 depth 가 i이면 가로연속도
// i이상 이어야한다.

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
              //  cout<<"개새"<<Arr[i][j];
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
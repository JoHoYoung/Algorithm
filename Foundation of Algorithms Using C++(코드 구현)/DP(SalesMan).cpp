#include<iostream>
#include<string>
using namespace std;

int Mincost=100000; //bound<Mincost;

char *ResetStrDel(char *str,int dexnum,int charnum) //DP�� ���� ���� ����, ���ڿ��� ó���ϱ� ���� ���ڿ��� �籸���ϴ� �Լ�
{
    char *temp=new char[charnum-1];
    int j=0;
    int i=0;
    while(i<charnum-1)
    { if(j!=dexnum)
    {
        temp[i] = str[j++];
        i++;
    }
    else j++;

    }

    return temp;

}

int Min(int a,int b)
{
    if(a<b)
        return a;
    else return b;

}

int DP(int S,char* Set,int charNum,int **W)
{

    int result=100000;

    if(charNum==1)
    {
        return W[S][Set[0]-'0']+W[Set[0]-'0'][0];
    }
    else
        for(int i=0;i<charNum;i++)
        {
            result=Min(result,W[S][Set[i]-'0']+DP(Set[i]-'0',ResetStrDel(Set,i,charNum),charNum-1,W));
        }
    return result;

}

int Travel(int **W,int Num)    //����ȣ�� 0������ Num-1�� ����.
{
    char str[100]="1";
    int dex=1;
    for(int i=2;i<=Num-1;i++)
    {
        str[dex++]=i+'0';

    }
    str[dex]='\0';

    return DP(0,str,Num-1,W);
}



int main()
{

    int N;
    cin << N;
    int **W;
    W=new int*[N];
    for(int i=0;i<5;i++)
        W[i]=new int[N];

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin<<W[i][j]
      }
    }

    cout<<Travel(W,5);
    // system("pause");
    return 0;

}

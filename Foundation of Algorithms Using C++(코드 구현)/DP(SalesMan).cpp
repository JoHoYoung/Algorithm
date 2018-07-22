#include<iostream>
#include<string>
using namespace std;

int Mincost=100000; //bound<Mincost;

char *ResetStrDel(char *str,int dexnum,int charnum) //DP를 위해 빼는 연산, 문자열로 처리하기 위해 문자열을 재구성하는 함수
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

int Travel(int **W,int Num)    //노드번호는 0번부터 Num-1번 까지.
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
    int **W;
    W=new int*[5];
    for(int i=0;i<5;i++)
        W[i]=new int[5];
    
    W[0][0]=0;
    W[0][1]=14;
    W[0][2]=4;
    W[0][3]=10;
    W[0][4]=20;
    
    W[1][0]=14;
    W[1][1]=0;
    W[1][2]=7;
    W[1][3]=8;
    W[1][4]=7;
    
    W[2][0]=4;
    W[2][1]=5;
    W[2][2]=0;
    W[2][3]=7;
    W[2][4]=16;
    
    W[3][0]=11;
    W[3][1]=7;
    W[3][2]=9;
    W[3][3]=0;
    W[3][4]=2;
    
    W[4][0]=18;
    W[4][1]=7;
    W[4][2]=17;
    W[4][3]=4;
    W[4][4]=0;
    
    cout<<Travel(W,5);
    // system("pause");
    return 0;
    
}

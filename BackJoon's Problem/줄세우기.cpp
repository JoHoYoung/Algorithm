#include<iostream>
using namespace std;



int main()
{
    int N;
    cin>>N;

    int Arr[N];
    int TArr[N];
    TArr[N-1]=0;

    for(int i=0;i<N;i++)
    {
        cin>>Arr[N];
    }



    for(int i=N-1;i>=0;i--)
    {
        bool isit=false;
        int tempsum=-10000;

        for(int j=i+1;j<N;j++)
        {if(Arr[j]>Arr[i]&&tempsum<TArr[j])
            {  tempsum=TArr[j];
                isit=true;
             }
        }

        if(isit)
            TArr[i]=tempsum+1;
        else TArr[i]=0;

    }
    int max=-1000;
    for(int i=0;i<N;i++)
    {
        if(TArr[i]>max)
            max=TArr[i];
    }
    cout<<max;
    //답은 N - 가장 긴 부분 수열
    return 1;
}
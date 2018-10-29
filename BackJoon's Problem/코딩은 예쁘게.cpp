//문제 2879
//코딩은 예쁘게
//백준이는 한 작은 회사에 취직했다. 이 회사에서 백준이는 소스 코드의 뒤죽박죽인 인덴트를 고치고 있다.
// 인덴트는 각 줄을 탭 키를 이용해 들여 쓰는 것을 말한다.
//
//다행히 백준이가 사용하는 편집기는 연속된 줄을 그룹으로 선택하고, 여기에서 각 줄의 앞에 탭을 추가하거나, 삭제할 수 있다.
//
//백준이를 도와 코드의 뒤죽박죽인 인덴트를 예쁘게 고치는 방법을 생각해보자.
//
//줄의 개수 N과 각 줄의 앞에 있는 탭의 개수와 올바른 탭의 개수가 주어진다.
//
//이때, 한 번 편집을 할 때, 다음과 같은 명령을 수행할 수 있다.
//
//연속된 줄을 그룹으로 선택한다.
//선택된 줄의 앞에 탭 1개를 추가하거나 삭제한다.
//위의 두 명령은 각각 선택된 줄의 개수와 상관없이 한 번의 편집이다.
//
//만약, 선택한 줄 중에 단 한 줄이라도 탭이 없을 경우에는, 탭을 삭제하는 명령을 수행할 수 없다.
//
//백준이가 몇 번 편집 만에 코드의 인덴트를 올바르게 고칠 수 있는지 구하는 프로그램을 작성하시오.
//이때, 편집 회수의 최솟값을 구해야 한다.

//탭이 없을때는 삭제 불가.
//연속된 줄을 엮어서 삭제 또는 추가
// 연속된 두개가 일단 같아지면 하나 취급.
// 방향이 다른것 끼리 같이 하는것은 제일 적은 이동횟수 만큼 항상 손해다.
// 방향이 같은것 끼리 하는 것은 이득이다.
// 엮었을때 같이 방향 : 그냥 제일 큰 차이
// 엮었을때 다른 방향 : 둘의 차이 +

// 같은 방향이면 묶어서 이동횟수가 제일 큰거. 다른 방향이면 어차피 더하기.
// 다른 방향이면 묶지 않는다.
// 방향이 다르면 따로 움직여야 해. 만약에 0인거 만나?, 가운데 0이 끼어 있으 그것도 따로 처리 하자.
#include<iostream>
#include<cstring>
using namespace std;
int pivot = 0;

int Arr[1003];

int Chart[1002][2];
int isEqualDirectionWithPivot(int n)
{

    if(pivot>0&&Arr[n]>0)
        return 1;
    else if(pivot<0&&Arr[n]<0)
        return 1;
    else return 0;
}

int absMax(int a,int b)
{
    if(abs(a)>abs(b))
        return a;
    else return b;

}

int main()
{
    int N;
    cin>>N;

    int a;
    int b;

    int count = 0;


    for(int i=0;i<N;i++)
    {   cin>>Chart[i][0];

    }

    for(int i=0;i<N;i++)
    {
        cin>>Chart[i][1];
    }

    for(int i=0;i<N;i++)
    {
        Arr[i]=Chart[i][1]-Chart[i][0];
      //  cout<<Arr[i];
    }

    //cout<<endl;
     pivot = Arr[0];
    for(int i=1;i<N;i++)
    {
    //cout<<pivot<<" ";
        if(isEqualDirectionWithPivot(i)==1)
        {
            //같은 부호 이지만 pivot값이 안 바뀌는 경우 -> 뒤에게 차이가 더 작다면 그 뒤에거랑 맞춰주자
            int temp=pivot;
            pivot = absMax(pivot,Arr[i]);

            if(temp==pivot)
            {
                count+=abs(pivot-Arr[i]);
                pivot = Arr[i];

            }
        }
        else
        {
            count += abs(pivot);
            pivot = Arr[i];

        }

    }

    count+=abs(pivot);
    cout<<count;

    return 0;
}
#include <iostream>
using namespace std;
//1층에는 1개, 2층에는 2개 3층에는 4개.. n층에는 2의 n승개의 노드가 있다.
// i층의 n번 노드가 유망하면  i+1층의 2n,2n+1 노드 푸쉬. 0번부터 할거니까 2(n)+1, 2n+2이다 자식은.
int N;
int MaxWeight;
int MaxProfit=0;

typedef struct que
{
    int level;
    int Weight;
    int Price;

};

typedef struct Data
{
    int Price;
    int Weight;

};

Data Item[100];

que Que[100];

int include[100];

int dex=-1;
int head=-1;
int rear=-1;

float Ratio(Data a1)
{
    return ((float)a1.Price / (float)a1.Weight);

}

void SwapNode(Data &a1, Data &a2)
{
    Data Temp;
    Temp = a1;
    a1 = a2;
    a2 = Temp;
}


void enque(int floor,int price,int weight)
{
    Que[++rear].level=floor;
    Que[rear].Price=price;
    Que[rear].Weight=weight;

}

que deque()
{
    que temp;
    temp.level=Que[++head].level;
    temp.Price=Que[head].Price;
    temp.Weight=Que[head].Weight;
    return temp;

}

bool Promising(int n,int profit,int weight)
{
    float bound=profit;
    int TotalWeight=weight;

    int j;
    if(n==-1)
        return true;

    if(weight>MaxWeight)
        return false;
    else
    {
        for(j=n+1;j<N&&(TotalWeight+Item[j].Weight)<=MaxWeight;j++)
        {
          TotalWeight=Item[j].Weight;
          bound+=Item[j].Price;
        }
    }
    if(j<N)
        bound+=(MaxWeight-TotalWeight)*Ratio(Item[j]);

    if(bound>MaxProfit)
        return true;


}

//아이템 번호는 0번부터 생각. 노드는 -1인 것이다.
void BFSKnap(int n,int profit,int weight)//각 n층은 n번째 아이템의 포함 유무.
{
    int TotalWight=weight;
    int bound=profit;

  if(weight<=MaxWeight&&profit>MaxProfit)
  {
      MaxProfit=profit;
  }

  if(Promising(n,profit,weight))
  {
      include[n+1]=1;
      enque(n+1,profit+Item[n+1].Price,weight+Item[n+1].Weight);
      enque(n+1,profit,weight);
  }

  while(head!=rear)
    {
        que temp=deque();
        BFSKnap(temp.level,temp.Price,temp.Weight);

    }

}

void BFSKnap2()
{
    enque(-1,0,0);

    while(head!=rear)
    {

     que temp=deque();
     cout<<"-----------FLOOR : "<<temp.level<<" 실행 결과-----------------"<<endl;

     if(MaxProfit<temp.Price&&temp.Weight<=MaxWeight) {
         MaxProfit = temp.Price;

     }
     if(Promising(temp.level,temp.Price,temp.Weight))
     {
         enque(temp.level+1,temp.Price+Item[temp.level+1].Price,temp.Weight+Item[temp.level+1].Weight);
         enque(temp.level+1,temp.Price,temp.Weight);
     }


    }


}

int main()
{
    cout << "아이템 갯수 입력 ";
    cin >> N;
    cout << "최대무게 입력";
    cin >> MaxWeight;

    for (int i = 1; i <= N; i++)
    {
        cout << i<<"번째 아이템의 무게, 값어치 입력";
        cin >> Item[i - 1].Weight >> Item[i - 1].Price;
    }

    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < i; j++) {
            if (Ratio(Item[j]) < Ratio(Item[j + 1]))
                SwapNode(Item[j], Item[j + 1]);
        }// 비율이 큰것부터 소팅.

    BFSKnap(-1,0,0);

    cout << MaxProfit;
    cout<<"CLEAR";
    system("pause");
    return 0;
}

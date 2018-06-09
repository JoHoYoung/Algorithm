#include <iostream>
using namespace std;
//1������ 1��, 2������ 2�� 3������ 4��.. n������ 2�� n�°��� ��尡 �ִ�.
// i���� n�� ��尡 �����ϸ�  i+1���� 2n,2n+1 ��� Ǫ��. 0������ �ҰŴϱ� 2(n)+1, 2n+2�̴� �ڽ���.
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

//������ ��ȣ�� 0������ ����. ���� -1�� ���̴�.
void BFSKnap(int n,int profit,int weight)//�� n���� n��° �������� ���� ����.
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
     cout<<"-----------FLOOR : "<<temp.level<<" ���� ���-----------------"<<endl;

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
    cout << "������ ���� �Է� ";
    cin >> N;
    cout << "�ִ빫�� �Է�";
    cin >> MaxWeight;

    for (int i = 1; i <= N; i++)
    {
        cout << i<<"��° �������� ����, ����ġ �Է�";
        cin >> Item[i - 1].Weight >> Item[i - 1].Price;
    }

    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < i; j++) {
            if (Ratio(Item[j]) < Ratio(Item[j + 1]))
                SwapNode(Item[j], Item[j + 1]);
        }// ������ ū�ͺ��� ����.

    BFSKnap(-1,0,0);

    cout << MaxProfit;
    cout<<"CLEAR";
    system("pause");
    return 0;
}

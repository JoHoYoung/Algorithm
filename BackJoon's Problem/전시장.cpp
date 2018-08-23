//문제 2515 전시장
//전시장에서 그림을 판매하는 업체에 하나의 전시대가 배정된다. 전시될 그림은 직사각형의 모양을 가지고 있고,
// 그림의 높이는 다를 수 있지만 폭은 모두 동일하다고 가정한다. 각 그림에는 가격이 매겨져 있다.
//
//
//
//업체는 그림들을 관람객에게 보이기 위해 전시대에 배치하는데, 전시대의 폭이 그림의 폭과 동일하여
// 겹쳐서 배치해야만 한다. 예를 들어, 위의 그림은 전시대에 네 개의 그림 A, B, C, D를 C, B, A, D의
// 순서로 겹쳐서 배치한 상황을 보여준다.
//
//위 그림의 오른쪽 부분은 전시된 그림들의 배치를 옆에서 본 모양을 나타내고, 왼쪽 부분은 배치한 그
// 림들을 앞에서 보아서 관람객들이 보게 될 모양을 나타낸다. 그림 A는 앞의 그림 B때문에 가려져서
// 관람객에게 전혀 보이지 않고, 부분적으로라도 보이는 그림은 B, C, D 뿐이다.
//
//보이는 부분의 세로 길이가 특정 정수 S이상인 그림만 관람객이 관심을 보이고 사게 된다고 가정
// 한다. 전시된 그림들 중 보이는 부분의 세로 길이가 S이상인 그림을 판매가능 그림이라고 부른다.
//
//그림의 높이와 가격이 주어질 때, 판매가능 그림들의 가격의 합이 최대가 되도록 그림을 배치할 때
// 그 최대합을 구하는 프로그램을 작성하시오.

// 최대한 많은 그림이 보이는게 아님
// 어떤 그림의 값이 매우크면 나머지 그림은 안보여도 됨.
// 최대한 많은그림을 배치하는 경우 + 최대한 비싼그림을 보이게 하는 경우 크로스
// 큰걸 앞에 배치해버리면 뒤에 있는건 못나오는 구조.
// 어떤 하나를 앞에 배치하면 그것보다 작은것은 그냥 아예 제외됨. 제일 큰것은 어디에 놓을 것인가.
// 제일 큰게 보일 수 있는가? -> 제일큰거보다 작은걸 큰거 뒤에 놓거나 앞에 놓거나
// 제일큰거보다 작은걸 앞에 놓을것인가 ?
// 제일큰거보다 뒤로 가는 것의 기준은 무엇인가? -> 그것이 앞에 놓였을때 다른 cost를 방해하는 경우이다.
// 얘가 다른 커질 수 있는 경우를 방해하면 -> 가려버린다.
// 제일 큰 경우를 방해한다는건 무엇인가
// 제일큰거 뒤에있는것.. 그다음 큰거 뒤에있는것...... 그그다음 큰거 뒤에 있는것...
// 그다음 큰거 뒤에 있는것은 제일큰거 뒤에있는것과 같다.
// 암튼 가려질건 무조건 제일 큰거 뒤에 있다고 보면 된다. -> 안팔리게 되는건 괜히 공간차지하지 말고 제일 뒤로 가버려라.
// 어차피 길이가 안돼서 못파는건 보여질 필요가 없다.
// 못파는걸 솎아내야하나?
// 팔게될것중 제일 작은것
// 팔게될걸 어떻게 정하나
// 기준보다 작은건 팔지 못한다.
// 1. 제일 작은게 팔렸을 경우 -> 모든것의 높이에서 제일작은거 높이를 빼고 시작그다음 작은게 팔렸을 경우
// 3차원 배열을 선언해야되나 DP[1] -> pivot=DP[1].length 모든것의 높이에서 DP[1].length를 빼서 재귀?
//  제일큰거보다 앞에 있는것.
// 제일 작은걸 팔았을경우 그다음 작은걸 팔았을 경우 그다음 작은걸 팔았을 경우 그다음 작은걸 팔았을 경우
// S가 H보다 작다.
// 모든 높이에서 S빼고, 0보다 큰것만 후보.
//

#include<iostream>
using namespace std;

int Max=0;
int N;
int S;

typedef struct
{
int Price=-100;
}CountArr;

CountArr CTN[20000002];

int picture[300010][2];

void showcase(int pivot,int Price,int i,int tr)
{
  if(i+1<tr) {
      if(Price>Max)
          Max=Price;
    showcase(pivot,Price,i+1,tr);
      if((picture[i][0]-pivot)>=S) {
          if(Max<(Price+picture[i][1]))
              Max=Price+picture[i][1];

          showcase(picture[i][0], Price + picture[i][1], i + 1,tr);
      }

    }
}

int main()
{
    cin>>N;
    cin>>S;

    int H;
    int C;
    for(int i=0;i<N;i++)
    {
        cin>>H;
        cin>>C;

        if(CTN[H].Price<C)
          CTN[H].Price=C;

    }
    int dex=0;
    for(int i=1;i<=20000003;i++)
    {
        if(CTN[i].Price>0) {
            picture[dex][0] = i;
            picture[dex++][1] = CTN[i].Price;

        }

    }

    cout<<dex<<endl;
    showcase(0,0,0,dex);

    cout<<Max;


    return 0;
}
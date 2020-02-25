#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N,C;

long long board[200000];

bool find(int dist){

    int i=0;
    int pivot = board[i];
    int cnt = 1;
    for(int j=i;j<N;j++){
      if( (board[j] - pivot) >= dist){
      //  cout<<i<<" "<<j<<endl;
      //  cout<<"dist : "<<dist<<"dif : "<<board[j] - pivot<<endl;
        cnt ++;
        pivot = board[j];
      }
    }
    if(cnt >= C){
  //    cout<<dist<<" "<<cnt<<endl;
      return true;
    }

  return false;
}

int max(int a, int b){
  if(a>b){
    return a;
  }
  return b;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N>>C;

  for(int i=0;i<N;i++){
    cin >> board[i];
  }

  // ���� ª�� �Ÿ�....
  // ���� �� �Ÿ�..........
  sort(board, board+N);
  int result = 0;
  // 1, 2, 4, 8, 9
  // �����Ⱑ C ���� �Ÿ��� C-1���� ���´�
  // �Ÿ��� N���� ������..N���� ũ�ų� ������ C��....
  long long left = 0;
  long long right = 1000000000;
  while(left<=right){
    int dist = (left + right)/2;
    if(find(dist)){
      left = dist + 1;
      result = max(result, dist);
    }else{
      right = dist -1;
    }
  }
  cout<<result;
  return 0;
}
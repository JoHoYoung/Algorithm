#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int board[100000];

int min(int a,int b){
  if(a>b){
    return b;
  }
  return a;
}
bool search(int length){

  int cnt = 1;
  int sum = 0;

  for(int i=0;i<n;i++){
    if(sum  + board[i] > length){
      if(board[i] > length) return false;
    //  cout<<"Bigger Than "<<length<<" ++ At : "<<i<<" and Sum :" <<sum<<endl;
      sum = board[i];
      cnt ++;
    }else{
      sum += board[i];
      //cout<<" += "<<board[i]<<endl;
    }
  }

  //cout<<"CNT : "<<cnt<<" MID : "<<length<<endl;

  // 범위 줄여
  if(cnt <= m) return true;
  //범위늘려
   return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n>>m;

  int result = 1000000;
  int sum = 0;
  for(int i=0;i<n;i++) {
    cin >> board[i];
    sum += board[i];
  }
  int right = 10000000;
  int left = 0;
  int mid = ((left+right) / 2);
  while(left<=right){
   // cout<<left<<" "<<right<<endl;
    mid = ((left+right) / 2);
    if(search(mid)){
      result = min(mid,result);
      right = mid -1;
    }else{
      left = mid +1;
    }
  }
  cout<<result;
  return 0;
}
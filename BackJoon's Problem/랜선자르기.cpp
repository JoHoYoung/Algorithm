#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N,K;
long long board[1000000];

int max(int a, int b){
  if(a>b){
    return a;
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N>>K;

  for(int i=0;i<N;i++){
    cin>>board[i];
  }
  //길이를.. 길이를..

  long long result = 0;
  long long left = 0;
  long long right = 10000000000;
  while(left<=right){
    long long pivot = (left + right)/2;
    long long cnt = 0;
    for(int i=0;i<N;i++){
      cnt += board[i]/pivot;
    }
    if(cnt >= K ){
      left = pivot + 1;
      result = max(result, pivot);
    }else{
      right = pivot -1;
    }
  }
  cout<<result;
  return 0;
}
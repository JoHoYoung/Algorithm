#include <iostream>
#include<cstring>
//#include<algorithm>

using namespace std;

long long max(long long a,long long b){
  if(a>b){
    return a;
  }
  return b;
}
int N,M;
long long board[10000];
long long result = 0;

long long calSum(long long pivot){

  long long cnt = 0;
  long long temp = 0;

  for(int i=0;i<N;i++){
    if(board[i] > pivot){
      temp = max(temp, pivot);
      cnt += pivot;
    }else{
      cnt += board[i];
      temp = max(temp, board[i]);
    }
  }
  if(cnt <= M ){
    result = max(result,temp);
  }
  return cnt;
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N;
  for(int i=0;i<N;i++){
    cin>>board[i];
  }
  cin>>M;

  long long left = 0;
  long long right = 10000000000;

  while(left<=right){
    // pivot씩 배정했을때
    long long pivot = (left + right) /2;
    // 총얼마?
    long long sum = calSum(pivot);
    if(sum <= M && pivot <= M){
      // 범위 늘리기.
      left = pivot+1;
  //    result = max(result, pivot);
    }else{
      right = pivot -1;
    }
  }
  cout<<result;
  return 0;
}
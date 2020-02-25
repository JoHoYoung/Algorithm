#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int N,M;

int board[100000];

long long spendMoney(long long money){
  long long cnt = 1;
  long long remain = money;
  for(int i=0;i<N;i++){
    int target = board[i];
    if(target > money){
      return -1;
    }else{
      if(target > remain){
        remain = money;
        remain -= target;
        cnt ++;
      }else{
        remain -= target;
      }
    }
  }
  return cnt;
}
long long min(long long a,long long b){
  if(a>b){
    return b;
  }
  return a;
}

long long result = 10000000000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>M;

  for(int i=0;i<N;i++){
    cin>>board[i];
  }

  long long left = 0;
  long long right = 10000000000;

  while(left<=right){
    long long mid = (left + right) / 2;
    // temp´Â µ·À» ÀÎÃâÇÑ È½¼ö
    long long temp = spendMoney(mid);
    if(temp <= M && temp != -1){
      result = min(result, mid);
      right = mid -1;
    }else{
      left = mid +1;
    }
  }

  cout<<result;
  return 0;
}

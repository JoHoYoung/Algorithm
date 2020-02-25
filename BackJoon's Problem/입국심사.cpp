#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


int N,M;

int T[100000];

// 더 기다리지 않고
long long howManyPeople(long long sec){

  long long cnt = 0;

  for(int i=0;i<N;i++){

    int target = T[i];

    if(target > sec){
      break;
    }

    cnt += sec/target;
  }
  return cnt;
}

long long min(long long a, long long b){
  if(a>b){
    return b;
  }
  return a;
}
int main() {

  cin>>N>>M;

  // T[i]초.
  for(int i=0;i<N;i++){
    cin>>T[i];
  }
  sort(T, T+N);

  long long left = 0;
  long long right = 1000000000000000000;
  long long result = 1000000000000000000;
  while(left<=right){
    long long mid = (left + right)/2;
    long long temp = howManyPeople(mid);
    if(temp >= M){
      result = min(result, mid);
      right = mid -1;
    }else{
      left = mid +1;
    }
  }
  cout<<result;
  return 0;
}

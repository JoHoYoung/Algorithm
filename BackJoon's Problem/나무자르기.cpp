#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N,M;

int max(int a, int b){
  if(a>b){
    return a;
  }
  return b;
}
int board[1000000];
// 적어도 M미터, 최대값
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N>>M;

  for(int i=0;i<N;i++){
    cin>>board[i];
  }

  long long left = 0;
  int result = 0;
  long long right = 2000000000;
  int pivot;
  while(left<=right){
    pivot = (left + right)/2;
    long long cut = 0;
    for(int i=0;i<N;i++){
      if(board[i] - pivot > 0){
        cut += board[i] - pivot;
      }
    }
 //   cout<<"Pivot "<<pivot<<" Cut "<<cut<<endl;
    if(cut >= M){
   //   cout<<"This? "<<endl;
      left = pivot +1;
      result = max(result, pivot);
    }else{
      right = pivot -1;
    }
  }
  cout<<result;
  return 0;
}
#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int X, Y;

int min(int a,int b){
  if(a>b){
    return b;
  }
  return a;
}
long long result = 1000000000;
int getRatio(long long x,long long y){
 // float temp = (y*100/x);
  return y*100/x;
}
int main() {

  cin>>X>>Y;
  int ratio = getRatio(X,Y);
  //cout<<ratio<<endl;
  int left = 0;
  int right = 1000000000;
  bool find = false;
  while(left<=right){

    int mid = (left + right)/2;

    int newRatio = getRatio(X + mid, Y+mid);
    if( (newRatio - ratio) >=1  ){
      find = true;
      right = mid -1;
      result = min(result, mid);
    }else{
      left = mid + 1;
    }
  }
  if(find){
    cout<<result;
  }else{
    cout<<-1;
  }
  return 0;
}

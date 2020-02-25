#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int N,H;
int board[100000];
int board2[100000];

int result = 1000000;

int term[200000];

int min(int a, int b){
  if(a>b){
    return b;
  }
  return a;
}

int getBoard1LowerBound(int target){
  int left = 0;
  int right = N/2;
  while(left < right){
    int mid = (left + right)/2;
   // cout<<left<<" "<<right<<endl;
    int stone = board[mid];
    if(stone >= target){
      right = mid;
    }else{
      left = mid+1;
    }
  }
 // cout<<"target "<<target<<" "<<right<<endl;
  return right;
}

int getBoard2LowerBound(int target){
  int left = 0;
  int right = N/2;
  while(left < right){
    int mid = (left + right)/2;
    int stone = board2[mid]-1;
    if(stone >= target){
      right = mid;
    }else{
      left = mid+1;
    }
  }
 // cout<<"target "<<target<<" "<<right<<endl;
  return right;
}


int main() {

  cin>>N>>H;

  for(int i=0;i<N/2;i++){
    cin>>board[i];
    cin>>board2[i];
  }

  sort(board, board+N/2);
  sort(board2, board2+N/2);
//  for(int i=0;i<N/2;i++){
//    cout<<board[i]<<" ";
//  }
//  cout<<endl;
//  for(int i=0;i<N/2;i++){
//    cout<<board2[i]<<" ";
//  }
//  cout<<endl;
  for(int i=0;i<N;i++){
    term[i] = 0;
  }

  for(int i=1;i<=H;i++){
    int temp = N/2 - getBoard1LowerBound(i);
    temp += N/2 - getBoard2LowerBound(H - i);
//   cout<< "OWN : "<<N/2 - getBoard1LowerBound(i)<<endl;
//    cout<<"TWO :" << N/2 - getBoard2LowerBound(H - i)<<endl;
//    cout<<"TEMP : "<<temp<<endl;
    term[temp] ++;
    result = min(result, temp);
  }


  cout<<result<<" "<<term[result];
  return 0;
}

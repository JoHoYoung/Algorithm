#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N, M;
int board[300];

int min(int a, int b){
  if(a>b) return b;
  return a;
}

vector<int> resultSet;
vector<int> tempSet;

bool divide(int max){
  int groupOfNumber = 0;
  int tempSum = 0;
  int cnt = 0 ;
  tempSet.clear();
  for(int i=0; i<N;i++){
    cnt++;
    if(board[i] > max){
      return false;
    }
    tempSum += board[i];
    if(tempSum > max){
      groupOfNumber ++ ;
      tempSet.push_back(cnt -1);
      cnt = 1;
      tempSum = board[i];
    }
    if(groupOfNumber > M ){
      return false;
    }
  }

  groupOfNumber ++;
  if(groupOfNumber > M ){
    return false;
  }
  tempSet.push_back(cnt);
  return true;
}

int result = 30000;
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>board[i];
  }

  int left = 0;
  int right = 30000;

  //sort(board, board + N);

  while(left <= right){
    int mid = (left + right)/2;
    if(divide(mid)){
      right = mid -1;
      if(result > mid){
        result = mid;
        resultSet.clear();
        resultSet.assign(tempSet.begin(), tempSet.end());
      }
    }else{
      left = mid + 1;
    }
  }

  cout<<result<<"\n";

  // result를 최대값으로 M개의 그룹으로 나누는 경우
  // 300개를 N개의 그룹;
  // 2 1 1 1
  // 1, 2 0

  int groupSize = resultSet.size();
  int dif = M - groupSize;
  vector<int> final;

  for(int i=0;i<resultSet.size();i++){
    int target = resultSet.at(i);
    if(target == 1){
      final.push_back(target);
    }else{
      if(dif == 0){
        final.push_back(target);
      }else{
        while(target >=1 && dif != 0){
          final.push_back(1);
          dif --;
          target --;
        }
        final.push_back(target);
      }
    }

  }

  for(auto it = final.begin(); it != final.end(); it++){
    cout<<*it<<" ";
  }

  return 0;
}

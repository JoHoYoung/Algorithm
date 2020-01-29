#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

vector<vector<int>> combination;

int board[21][21];
int N;

int abs(int a){
  if(a<0){
    return -a;
  }
  return a;
}

bool visited[21];
void getCombination(int num, int idx,int depth,vector<int> arr){

  if(depth == num){
    vector<int> t;

    t.assign(arr.begin(), arr.end());
    combination.push_back(t);
    return;
  }

  for(int i=idx;i<N;i++){
    if(visited[i] == true) continue;

    visited[i] = true;
    arr.push_back(i);

    getCombination(num, i, depth+1,arr);

    arr.pop_back();
    visited[i] = false;
  }
}

int result = INT_MAX;
int min(int a, int b){
  if(a>b){
    return b;
  }
  return a;
}

bool check[20];

int main() {

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for(int i=1; i<(N+1/2); i++){
    vector<int> arr;
    getCombination(i,0,0,arr);
  }

  for(auto it = combination.begin(); it != combination.end(); it++){
    fill(&check[0],&check[19]+1,false);
    int alpha = 0;
    for(auto member = (*it).begin(); member != (*it).end(); member ++ ){
      check[(*member)] = true;
      for(auto member2 =(*it).begin(); member2 != (*it).end(); member2 ++ ){
        alpha += board[(*member)][(*member2)];
      }
    }

    vector<int> remain;
    for(int i=0;i<N;i++){
      if(!check[i]){
        remain.push_back(i);
      }
    }

    int beta = 0;
    for(auto member = remain.begin(); member != remain.end(); member ++ ){
      for(auto member2 =remain.begin(); member2 != remain.end(); member2 ++ ){
        beta += board[(*member)][(*member2)];
      }
    }

    result = min(result, abs(alpha - beta));

  }
  cout<<result;
  return 0;
}
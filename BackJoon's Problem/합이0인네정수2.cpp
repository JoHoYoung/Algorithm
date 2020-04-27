#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;


int board[4001][4];
int N;

vector<int> A, B;


int lb(vector<int>* a, int target) {

  int l = 0;
  int r = N*N-1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a -> at(mid) >= target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return r;
}

int ub(vector<int>* a, int target) {
  int l = 0;
  int r = N*N-1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a -> at(mid) > target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return a -> at(r) == target ? r + 1 : r;
}

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A.push_back(board[i][0] + board[j][1]);
      B.push_back(board[i][2] + board[j][3]);
    }
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll ans = 0;
  for(int i=0;i<N*N;i++){
    //cout<<"TG "<<A[i]<<endl;
    ans += ub(&B,-A[i]) - lb(&B,-A[i]);
  }
  cout<<ans;
  return 0;
}


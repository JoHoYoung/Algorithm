#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;

int N, M;

char board[100];
char ck[100][100];

bool isTrue(char a, int target) {
  if (a == '0') {
    return target == 0;
  } else if (a == '+') {
    return target > 0;
  } else if (a == '-') {
    return target < 0;
  }
}

// vector에는 구간합을 저장함
// 범위는 부터로 잡고.
// target이 depth에 들어가도 되겠느냐?
bool check(vector<int> &arr, int nNumber) {
  for (int i = 1; i <= nNumber; i++) {
    for (int j = i; j <= nNumber; j++) {
     int t = arr[j] - arr[i-1];
      if(isTrue(ck[i][j],t)) continue;
      return false;
    }
  }
  return true;
}

vector<vector<int>> R;
bool isFind = false;
void DFS(int depth, vector<int>& arr) {

  if(isFind) return;
  if (!check(arr, arr.size()-1) ) return;

  if(depth == N){
    R.push_back(arr);
    isFind = true;
    return;
  }
  for (int i = -10; i <= 10; i++) {
    // 원소가 아닌 구간합을 푸쉬함
    arr.push_back(arr[depth] + i);
    DFS(depth + 1, arr);
    arr.pop_back();
  }
}


// ck[i][j] : i~j까지 합의 부호
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N * (N + 1) / 2; i++) {
    cin >> board[i];
  }
  memset(ck, false, sizeof(ck));
  int idx = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      ck[i][j] = board[idx++];
    }
  }
  vector<int> a;
  a.push_back(0);
  DFS(0,a);
  for(int i=1;i<R[0].size();i++){
    cout<<R[0][i] - R[0][i-1]<<" ";
  }
  return 0;
}
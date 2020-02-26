#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

int min(int a, int b){
  if(a>b) return b;
  return a;
}

int result = 1000000;

int N, K;
// 중간에 멈추는 횟수가 k 이하일때 연로통의 최소 용량

int distTo(int x1, int x2, int y1, int y2) {
  return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

struct pos {
    int i, j;
};
long long dist[1002][1002];

bool visited[1002];

long long limit;
vector<pos> V;

bool isFind = false;

void dfs(int i, int j,int depth, int idx) {
  if(depth > K) return;
  if(isFind) return;

  for (auto it = V.begin(); it != V.end(); it++) {
    pos now = *it;
    int nextI = now.i;
    int nextJ = now.j;
    if ( dist[idx][it - V.begin()]  > limit*10*limit*10 || visited[it - V.begin()]) {
      // cout<<distTo(i, nextI, j, nextJ)<<" "<<limit*limit*10*10<<endl;
      continue;
    }
    visited[it - V.begin()] = true;
    if(nextI == 10000 && nextJ == 10000){
      visited[it - V.begin()] = true;
      isFind = true;
      // cout<<"COMPLETE"<<endl;
      return;
    }
    if(!isFind && depth + 1 <= K){
      dfs(nextI, nextJ, depth +1, it - V.begin());
    }
   // visited[it - V.begin()] = false;
  }
}
bool dfs2(int cur, int cnt) {
  if (dist[cur][N + 1] <= limit*limit*100)return true; // 현재 위치에서 목적지까지 갈수 있으면 종료
  if (cnt > K)return false; // 연료 보충 횟수 초과시 종료
  visited[cur] = true;

  for (int i = 1; i <= N; ++i) {
    // 이미 방문했거나 가는데 연료가 모자랄경우 continue
    if (visited[i])continue;
    if (dist[cur][i] > limit*limit*100)continue;
    // dfs 돌려줌
    if (dfs2(i, cnt + 1))return true;
  }
  return false;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  int i, j;

  V.push_back(pos{0,0});
  for (int tc = 0; tc < N; tc++) {
    cin >> i >> j;
    V.push_back(pos{i, j});
  }
  V.push_back(pos{10000, 10000});

  for (int i = 0; i <= N; ++i) {
    for (int j = i; j <= N + 1; ++j) {
      if (i == j)dist[i][j] = 1e9;
      else dist[i][j] = dist[j][i] = pow(V[i].i - V[j].i,2) + pow(V[i].j - V[j].j, 2);
    }
  }

  //cout<<V.size()<<endl;
  int left = 0;
  int right = 10001;

  //cout<<distTo(5000,7000,5000,7000)/10<<endl;
  while (left <= right) {
    memset(visited, 0, sizeof(visited));
    limit = (left + right) / 2;
    // cout<<"Limit : "<<limit<<endl;
    visited[0] = true;
    isFind = false;
   // dfs(0, 0, 0, 0 );
    if (dfs2(0,0) ) {
      result = min(result, limit);
      right = limit - 1;
    } else {
      left = limit + 1;
    }
  }
  cout<<result;
  return 0;
}

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

vector<vector<int>> gr;

int ans = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

bool visited[4001];

void DFS(int targetIdx, int curIdx, int depth, vector<int>& arr) {

  if(depth == 3 && targetIdx == curIdx){
    int cnt = 0;
    cnt+= gr[arr[0]].size();
    cnt+= gr[arr[1]].size();
    cnt+= gr[arr[2]].size();
    cnt -= 6;
    ans = min(ans, cnt);
    return;
  }

  if(depth == 3 || visited[curIdx]) return;

  visited[curIdx] = true;
  arr.push_back(curIdx);
  for (int v = 0; v < gr[curIdx].size(); v++) {
    int nIdx = gr[curIdx][v];
    //if(visited[nIdx]) continue;
    DFS(targetIdx, nIdx, depth+1, arr);
  }
  arr.pop_back();
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  gr.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  for(int i=1;i<=N;i++){
    vector<int> a;
    memset(visited, false, sizeof(visited));
    DFS(i, i, 0, a);
  }

  if (ans == INF) cout << -1;
  else cout << ans;
  return 0;
}
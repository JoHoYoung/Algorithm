#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 4000001
#define ll long long
#define RED 1
#define BLUE -1

using namespace std;
using P = pair<long, long>;
int tc, N, M;

vector<int> Nodes[20001];
int visited[20001];

queue<int> Q;

bool bfs() {

  while (!Q.empty()) {
    int now = Q.front();
    vector<int> nowNode = Nodes[now];
  //  cout << "node : " << now << " color : " << visited[now] << endl;
    Q.pop();
    for (auto it = nowNode.begin(); it != nowNode.end(); it++) {
    //  cout << "NEXT : " << *it << " color : " << visited[*it] << endl;
      if (visited[*it] == 0) {
        visited[*it] = visited[now] * -1;
   //     cout << "COLOR AT " << *it << " TO " << visited[now] * -1 << endl;
        Q.push(*it);
        continue;
      }
      if (visited[*it] == visited[now]) {
     //   cout << "Return false" << endl;
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  // 0 : 칠하지 않은그래프 | 1,2 : 색깔

  for (int t = 0; t < tc; t++) {

    int V, E;
    cin >> V >> E;
    bool find = true;

    while (!Q.empty()) {
      Q.pop();
    }
    for (int i = 1; i <= V; i++) {
      Nodes[i].clear();
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < E; i++) {
      int s, e;
      cin >> s >> e;
      Nodes[s].push_back(e);
      Nodes[e].push_back(s);
    }

    for (int i = 1; i <= V; i++) {
      if (visited[i] == 0) {
        Q.push(i);
        visited[i] = RED;
        if (!bfs()) {
          find = false;
          break;
        }
      }
    }

    if (find) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }

 //   cout << endl;
  }
  return 0;
}
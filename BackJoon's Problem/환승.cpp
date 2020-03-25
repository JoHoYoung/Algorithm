#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, K, M;

vector<int> tube[1001];
vector<int> adgTube[100001];


int visited[100001];
bool tubeVisited[1001];

void BFS() {

  queue<P> Q;
  Q.push({1, 1});
  visited[1] = 1;

  while (!Q.empty()) {

    P cur = Q.front();
    Q.pop();
    int curNode = cur.first;
    int curCost = cur.second;

    for (int t = 0; t < adgTube[curNode].size(); t++) {
      int tubeN = adgTube[curNode][t];
      if (tubeVisited[tubeN]) continue;
      tubeVisited[tubeN] = true;
      for (int i = 0; i < tube[tubeN].size(); i++) {
        int nextNode = tube[tubeN][i];
        if (visited[nextNode] != -1 && visited[nextNode] <= curCost + 1) continue;
        visited[nextNode] = curCost + 1;
        Q.push({nextNode, curCost + 1});
      }
    }
  }

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K >> M;
  memset(visited, -1, sizeof(visited));
  memset(tubeVisited, false, sizeof(tubeVisited));
  for (int i = 1; i <= M; i++) {
    for (int t = 0; t < K; t++) {
      int tmp;
      cin >> tmp;
      tube[i].push_back(tmp);
      adgTube[tmp].push_back(i);
    }
  }

  BFS();
  cout << visited[N];
  return 0;
}


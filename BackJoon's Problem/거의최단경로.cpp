#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 999999999
using namespace std;
using P = pair<int, int>;
int N, M;
int board[501][501];
bool visited[501][501];
// 시작점으로부터 특정 점까지의 거리저장

vector<int> dst(501, INF);

priority_queue<P> pq;
vector<P> trace[501];

void Dijkstart(int start) {
  pq.push({0, start});
  dst[start] = 0;
  while (!pq.empty()) {
    P now = pq.top();
    int curlVertex = now.second;
    int curlCost = now.first * -1;
   // cout<<"Curl Pos "<<curlVertex<<endl;
    pq.pop();
    for (int nextNode = 0; nextNode < N; nextNode++) {
      if (board[curlVertex][nextNode] == INF) continue;
      int nextDst = curlCost + board[curlVertex][nextNode];
      if (dst[nextNode] > nextDst) {
        dst[nextNode] = nextDst;
        pq.push({-nextDst, nextNode});

        trace[nextNode].clear();
        trace[nextNode].push_back({curlVertex, nextNode});
      } else if (dst[nextNode] == nextDst) {
        trace[nextNode].push_back({now.second, nextNode});
      }
    }
  }
}

void BFS(int destination) {
  queue<int> q;
  q.push(destination);
  while (!q.empty()) {
    int curVertex = q.front();
    q.pop();
    for (int i = 0; i < trace[curVertex].size(); i++) {
      int neighbor = trace[curVertex][i].first;
      if (board[neighbor][curVertex] == INF || curVertex == neighbor) continue;
     // cout<<"DELETE "<<neighbor<<" To "<<curVertex<<endl;
      board[neighbor][curVertex] = INF;
      q.push(neighbor);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int S, D;
  while (1) {
    cin >> N >> M;
    cin >> S >> D;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        board[i][j] = INF;
        if (i == j) board[i][j] = 0;
      }
    }

    if (N == 0 && M == 0) break;
    memset(trace, 0, sizeof(trace));
    dst = vector<int>(501, INF);
    int s, d, p;
    for (int i = 0; i < M; i++) {
      cin >> s >> d >> p;
      board[s][d] = p;
    }

    Dijkstart(S);
   // cout<<"DEL"<<endl;
    BFS(D);
    dst = vector<int>(501, INF);
    Dijkstart(S);
    if (dst[D] == INF) dst[D] = -1;
    cout << dst[D] << "\n";
  }

  return 0;

}

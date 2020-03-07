#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;
int N, M;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool board[101][101];

typedef struct eg {
    int e, cost;
};

vector<eg> gr[10010];
int dst[10010];
priority_queue<P> pq;

void dijkstra() {
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    //  cout<<cur.first<<" "<<cur.second<<endl;
    int curDex = cur.second;
    int curCost = -cur.first;
    for (int v = 0; v < gr[curDex].size(); v++) {
      int nEnd = gr[curDex][v].e;
      int nDst = curCost + gr[curDex][v].cost;
      if (dst[nEnd] > nDst) {
        dst[nEnd] = nDst;
        pq.push({-nDst, nEnd});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> M >> N;
  string in;

  for (int i = 0; i < N; i++) {
    cin >> in;
    for (int j = 0; j < M; j++) {
      board[i][j] = in[j] == '1' ? true : false;
    }
  }

  int nodenum = 0;
  int idx[4] = {-M, 1, M, -1};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {

      for (int d = 0; d < 4; d++) {
        int ni = i + Di[d];
        int nj = j + Dj[d];
        if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
        gr[nodenum].push_back({nodenum + idx[d], board[ni][nj]});
      }
      nodenum++;
    }
  }

//  for(int i=0;i<gr[150].size(); i++ ){
//    cout<<"to "<<gr[150][i].e<<" cost : "<<gr[150][i].cost<<endl;
//  }

  // 첫노트부터 마지막 노드까지.
  for (int i = 0; i < nodenum; i++)dst[i] = INF;
  pq.push({0, 0});
  dijkstra();

  dst[0] = 0;
  cout << dst[nodenum - 1];
  return 0;
}
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

typedef struct eg {
    int e, cost;
};

priority_queue<P> pq;

int dst[2002];
vector<eg> gr[2002];
vector<int> candidate;
vector<int> trace[2002];
int T, n, m, t, s, g, h;


// 무조건 최단거리로 가는지
// 즉 특정 목적지로 가는것에 특정 선분을 포함하는지
// 또는 특정선분을 포함해 최단거리로 갈 수 있는지
void initDst() {
  for (int i = 1; i <= n; i++) {
    dst[i] = INF;
  }
}

void dijkstra() {

  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    //cout << "DJ "<<cur.first << " " << cur.second << endl;
    int curNode = cur.second;
    int curCost = -cur.first;

    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].e;
      int nCost = curCost + gr[curNode][v].cost;
      //  cout<<" next Node "<<nNode<<endl;
      // cout<<"UPPER "<<dst[nNode]<<" newer "<<nCost<<endl;
      if (dst[nNode] > nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
        trace[nNode].clear();
        trace[nNode].push_back(curNode);
      }else if(dst[nNode] == nCost){
        trace[nNode].push_back(curNode);
      }
    }
  }
}

bool cmp(int a, int b) {
  return a < b;
}

bool isInAtTrace(int targetNode, int g, int h) {
  queue<int> Q;
  Q.push(targetNode);
  bool visited[2002];
  memset(visited, false, sizeof(visited));
  while (!Q.empty()) {
    int cur = Q.front();
  //  cout<<cur<<endl;
    Q.pop();
    if(visited[cur]) continue;
    visited[cur] = true;
    for (int i = 0; i < trace[cur].size(); i++) {
      if ((cur == g && trace[cur][i] == h) || (cur == h && trace[cur][i] == g)) return true;
      Q.push(trace[cur][i]);
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T != 0) {

    for (int i = 0; i < 2002; i++) {
      gr[i].clear();
      trace[i].clear();
    }

    candidate.clear();
    cin >> n >> m >> t;
    cin >> s >> g >> h;

    for (int i = 0; i < m; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      gr[a].push_back({b, d});
      gr[b].push_back({a, d});
    }

    for (int i = 0; i < t; i++) {
      int a;
      cin >> a;
      candidate.push_back(a);
    }
    initDst();

    dst[s] = 0;
    pq.push({0, s});
    dijkstra();


    vector<int> R;
    for (int i = 0; i < candidate.size(); i++) if (isInAtTrace(candidate[i], g, h)) R.push_back(candidate[i]);

    sort(R.begin(), R.end(), cmp);
    for (int i = 0; i < R.size(); i++)cout << R[i] << " ";
    cout<<"\n";
    T--;
  }

  return 0;
}
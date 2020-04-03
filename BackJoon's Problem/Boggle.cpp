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

int W, b;

int Di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int Dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

set<string> FIND;
vector<string> re;

char board[4][4];
bool visited[4][4];

map<int, int> score;

typedef struct nodes {
    nodes *leaves[26];
    bool end;

    nodes() {
      fill(leaves, leaves + 26, nullptr);
      end = false;
    }
};

nodes *root = new nodes();

void addToTries(string s) {
  nodes *now = root;
  for (int i = 0; i < s.size(); i++) {
    nodes *next = now->leaves[s[i] - 'A'];
    if (!next) {
      now->leaves[s[i] - 'A'] = new nodes();
    }
    now = now->leaves[s[i] - 'A'];
  }
  now->end = true;
}

void DFS(int curI, int curJ, nodes *curNode, string trace) {

  visited[curI][curJ] = true;
  if (curNode->end) FIND.insert(trace);
  for (int d = 0; d < 8; d++) {
    int ni = curI + Di[d];
    int nj = curJ + Dj[d];
    if (ni < 0 || ni > 3 || nj < 0 || nj > 3 || visited[ni][nj]) continue;
    char curC = board[ni][nj];
    nodes *nNode = curNode->leaves[curC - 'A'];
    if (!nNode) continue;
    string nTrace;
    nTrace = trace;
    nTrace.push_back(curC);
    DFS(ni, nj, nNode, nTrace);
  }
  visited[curI][curJ] = false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> W;

  score.insert({1,0});
  score.insert({2,0});
  score.insert({3,1});
  score.insert({4,1});
  score.insert({5,2});
  score.insert({6,3});
  score.insert({7,5});
  score.insert({8,11});

  for (int i = 0; i < W; i++) {
    string s;
    cin >> s;
    addToTries(s);
  }

  cin >> b;

  while (b--) {
    memset(visited, false, sizeof(visited));
    FIND.clear();

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> board[i][j];
      }
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (!(root->leaves[board[i][j] - 'A'])) continue;
        memset(visited, false, sizeof(visited));
        string sTrace;
        sTrace.push_back(board[i][j]);
        DFS(i, j, root->leaves[board[i][j] - 'A'], sTrace);
      }
    }

    int point = 0;
    string res = "";

    for (auto it = FIND.begin(); it != FIND.end(); it++) {
      string n = (*it);
      point += score[n.size()];
      if(res.size() == n.size()) res = res < n ? res : n;
      else if(res.size() < n.size()) res = n;
    }

    string tops;
    tops = to_string(point) + " " + res + " "+ to_string(FIND.size());
    re.push_back(tops);
  }

  for (auto it = re.begin(); it != re.end(); it++) {
    cout<<(*it)<<endl;
  }
  return 0;
}


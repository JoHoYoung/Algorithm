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
bool visited[15];
vector<int> gr[12];

vector<vector<int>> PERM;

void perm(int Q, int n, int idx, int depth, int elcnt, vector<int> arr) {

  // cout<<n<<" "<<depth<<endl;
  if (depth == n) {
    if (elcnt < N) return;
    PERM.push_back(arr);
    return;
  }

  for (int i = idx; i <= Q; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    vector<int> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    perm(Q, n, i + 1, depth + 1, elcnt + gr[i].size(), a);
    visited[i] = false;
  }

}

bool allvisited() {
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) return false;
  }
  return true;
}

bool isTrue() {

  for (int i = 0; i < PERM.size(); i++) {
    vector<int> p = PERM[i];
    memset(visited, false, sizeof(visited));
    for (int j = 0; j < p.size(); j++) {
    //  cout << "target : " << p[j] << " " << endl;
      vector<int> g = gr[p[j]];
      for (int k = 0; k < g.size(); k++) {
      //  cout << "el : " << g[k] << endl;
        visited[g[k]] = true;
      }
    }
    if (allvisited()) return true;
  }
  return false;
}

void printPErm() {
  for (int i = 0; i < PERM.size(); i++) {
    for (int j = 0; j < PERM[i].size(); j++) {
      cout << PERM[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    int O;
    cin >> O;
    for (int j = 0; j < O; j++) {
      int tmp;
      cin >> tmp;
      gr[i].push_back(tmp);
    }
  }

  int ans = -1;
  for (int i = 1; i <= M; i++) {
    PERM.clear();
    memset(visited, false, sizeof(visited));
    vector<int> a;
    //void perm(int N, int n, int idx, int depth, int elcnt, vector<int> arr) {
    perm(M, i, 1, 0, 0, a);
  //  cout << " I : " << i << endl;
  //  printPErm();
    if (isTrue()) {
      ans = i;
      break;
    }
  }

  cout << ans;
  return 0;
}
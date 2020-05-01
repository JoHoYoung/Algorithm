#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, K;

vector<string> el;

int sol(int sel) {
  int ans = 0;
  for (int i = 0; i < el.size(); i++) {
    string tg = el[i];
    if(tg.size() == 0) ans++;
    for (int c = 0; c < tg.size(); c++) {
      char tc = tg[c];
      if ((sel & (1 << (tc - 'a'))) == 0) break;
      if (c == tg.size() - 1) ans++;
    }
  }
  //cout<<"RETURN "<<ans<<endl;
  return ans;
}


int max(int a, int b) {
  return a > b ? a : b;
}

bool visited[30];

int ans = -1;

void comb(int n, int N, int idx, int depth, ll sel) {

  if (depth == n) {
    ans = max(ans, sol(sel));
    return;
  }

  for (int i = idx; i <= N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    int nsel = (sel | (1 << i));
    if(static_cast<char>((i + 'a') == 'b')){
     // cout << "select " << static_cast<char>((i + 'a')) << endl;
    }
    comb(n, N, i + 1, depth + 1, nsel);
    visited[i] = false;
  }
}
//2 15
//antabtica
//antatica
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  if (K < 5) {
    cout << 0;
    exit(0);
  }

  memset(visited, false, sizeof(visited));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    s = s.substr(4, s.size());
    for(int j=0;j<4;j++) s.pop_back();
    el.push_back(s);
  }


  int ssel = 0;

  ssel |= (1 << ('a' - 'a'));
  visited['a' - 'a'] = true;

  ssel |= (1 << ('n' - 'a'));
  visited['n' - 'a'] = true;

  ssel |= (1 << ('t' - 'a'));
  visited['t' - 'a'] = true;

  ssel |= (1 << ('i' - 'a'));
  visited['i' - 'a'] = true;

  ssel |= (1 << ('c' - 'a'));
  visited['c' - 'a'] = true;

  ans = sol(ssel);
  comb(K - 5, 25, 0, 0, ssel);
  cout << ans;
  return 0;

}



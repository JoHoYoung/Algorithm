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

int N;

typedef struct unit {
    int x1, y1, x2, y2;
};
vector<unit> el;

int ccw(P A, P M, P B) {
  int t = (A.first - M.first) * (B.second - M.second) - (A.second - M.second) * (B.first - M.first);
  if (t > 0) return 1;
  if (t < 0) return -1;
  return t;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a > b ? b : a;
}

bool isCross(unit a, unit b) {
  P A = {a.x1, a.y1};
  P B = {a.x2, a.y2};

  P C = {b.x1, b.y1};
  P D = {b.x2, b.y2};
  int r1 = ccw(A, C, B) * ccw(A, D, B);
  int r2 = ccw(C, A, D) * ccw(C, B, D);
  //cout<<r1<<" "<<r2<<endl;
  if (r1 == 0 && r2 == 0) {
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);
    return C <= B && A <= D;
  }
  return r1 <= 0 && r2 <= 0;
}

int p[5000];
int cnt[5000];

int parent(int idx) {
  if (idx == p[idx]) return idx;
  return p[idx] = parent(p[idx]);
}

void uni(int a, int b) {
  // cout << "DO! " << endl;
  int A = parent(a);
  int B = parent(b);
  // cout << A << " " << B << endl;
  if (A > B) p[B] = A;
  else p[A] = B;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    p[i] = i;
    cnt[i] = 0;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    el.push_back({x1, y1, x2, y2});
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (isCross(el[i], el[j])) uni(i, j);
    }
  }

//  for (int i = 0; i < N; i++){
//    cout<<parent(i)<<" ";
//  }
  for (int i = 0; i < N; i++) {
    //   cout<<parent(i)<<endl;
    cnt[parent(i)]++;
  }

  ll ans1 = 0, ans2 = 0;
  for (int i = 0; i < N; i++) {
    if (cnt[i]) ans1++;
    ans2 = max(ans2, cnt[i]);
  }

  cout << ans1 << "\n" << ans2 << endl;
  return 0;
}



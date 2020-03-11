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
int T, N, K;

vector<int> el;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

// 최대거리 : K
// 슬라이딩 윈도우 K
P getN(int target) {
  int nTen = 0;
  int nTwo = 0;
  int nFive = 0;
  while (1) {
    if (target % 10 != 0) break;
    nTen++;
    target /= 10;
  }

  while (1) {
    if (target % 2 != 0) break;
    nTwo++;
    target /= 2;
  }

  while (1) {
    if (target % 5 != 0) break;
    nFive++;
    target /= 5;
  }
  return {nTwo + nTen, nFive + nTen};
}

P cache[100002];

void sol() {
  cache[0] = getN(el[0]);
  for (int i = 1; i < N; i++) {
    int nT = INF;
    int nF = INF;
    P cur = getN(el[i]);
    for (int k = 1; k <= K; k++) {
      int prev = i - k;
      if (prev >= 0) {
        P pr = cache[prev];
        nT = min(pr.first + cur.first, nT);
        nF = min(pr.second + cur.second, nF);
      }
    }
    cache[i] = {nT, nF};
    //cout<<"i : "<<i<<" "<<nT<<" "<<nF<<endl;
  }
  cout << min(cache[N - 1].first, cache[N - 1].second)<<"\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){

    el.clear();
    cin>>N>>K;
    for (int i = 0; i < N; i++) {
      int tp;
      cin >> tp;
      el.push_back(tp);
    }
    sol();
  }


  return 0;
}
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

int d, n, m;
vector<int> el;

// mid보다 작은건 건너뛴다
bool canGo(int mid) {

  int sum = 0;
  int cnt = 0;
  for (int i = 1; i < el.size(); i++) {
    int dst = el[i] - el[i - 1];
    // 최소거리보다 작으면 건너뛴다
    if (sum + dst < mid) {
      sum += dst;
      cnt++;
      continue;
    }
    sum = 0;
  }
  //cout<<"CNT : "<<cnt<<endl;
  return cnt <= m;
}

//0 2 11 14 17 21 25

int ans = -1;

int max(int a, int b) {
  return a > b ? a : b;
}

// 돌을 m개 제거
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> d >> n >> m;

  el.push_back(0);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  el.push_back(d);
  sort(el.begin(), el.end());
  int l = 0;
  int r = 1000000000;
  while (l <= r) {
    int mid = (l + r) / 2;
    //  cout<<l<<" "<<r<<endl;
    if (canGo(mid)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
}


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

int N, M;

vector<int> el;
vector<int> re;

int ans = INF;

int min(int a, int b) {
  return a > b ? b : a;
}

bool sol(int m) {

  re.clear();
  int cnt = 0;

  int sum = 0;
  for (int i = 0; i < el.size(); i++) {
    int r = el[i];
    cnt++;
    // cout<<"SUM : "<<sum+r<<endl;
    if (sum + r <= m) {
      if (i == el.size() - 1) {
        re.push_back(cnt);
        return re.size() <= M;
      }
      sum += r;
      continue;
    }
    if (r > m) return false;
    re.push_back(cnt - 1);
    cnt = 0;
    sum = 0;
    i--;
    if (re.size() > M) return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;


  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

//  sort(el.begin(), el.end());

  int l = 0;
  int r = INF;

  while (l <= r) {
    int mid = (l + r) / 2;
    //  cout<<"mid "<<mid<<endl;
    if (sol(mid)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;
  re.clear();

  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < el.size(); i++) {
    int r = el[i];
    cnt++;
    if (sum + r <= ans) {
      if (i == el.size() - 1) {
        re.push_back(cnt);
      }
      sum += r;
      continue;
    }
    re.push_back(cnt - 1);
    cnt = 0;
    sum = 0;
    i--;
  }

  int rem = M - re.size();
  vector<int> fin;

  for (int i = 0; i < re.size(); i++) {

    if (rem <= 0) {
      fin.push_back(re[i]);
      continue;
    }

    if (re[i] == 1) {
      fin.push_back(1);
      continue;
    } else {
      if (re[i] > rem) {
        fin.push_back(re[i] - rem);
        while (rem > 0) {
          fin.push_back(1);
          rem--;
        }
      } else {
        rem++;
        for (int j = 0; j < re[i]; j++) {
          fin.push_back(1);
          rem--;
        }
      }
    }

  }

//  for (int i = 0; i < re.size(); i++) cout << re[i] << " ";
  for (int i = 0; i < fin.size(); i++) cout << fin[i] << " ";
  return 0;

}


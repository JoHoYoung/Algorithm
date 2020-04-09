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

vector<ll> Y;
vector<ll> D;

ll ySum = 0;
ll dSum = 0;

ll getAllSum(ll smallest) {
  if (N % 2 == 0) {
    return (((N / 2) - 1) * ((N / 2)) / 2) * 2 + smallest * N;
  } else {
    return ((N / 2) * ((N / 2) + 1) / 2) * 2 + smallest * N;
  }
}

ll ans = 10000000000000;

ll ABS(ll a) {
  return a > 0 ? a : -a;
}

ll calc(long long low) {
  int mid = N / 2;
  int left = mid - 1, right = mid + 1;
  ll ret = 0;
  ret = abs(Y[mid] - low) + abs(D[mid] - low);
  while (0 <= left && right < N) {
    low++;
    ret += (abs(Y[left] - low) + abs(D[left] - low));
    ret += (abs(Y[right] - low) + abs(D[right] - low));
    left--;
    right++;
  }
  return ret;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int y;
    cin >> y;
    ySum += y;
    Y.push_back(y);
  }
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    dSum += d;
    D.push_back(d);
  }
  ll l = 0;
  ll r = 1000000000000 - N/2;

  ll lb = calc(l);
  ll rb = calc(r);
  while (l <= r) {
    ll mid = (l + r) / 2;
    if(lb < rb){
      r = mid -1;
      rb = calc(r);
    }else{
      l = mid +1;
      lb = calc(l);
    }

  }
  cout << (lb < rb ? lb : rb)<<endl;
  return 0;
}



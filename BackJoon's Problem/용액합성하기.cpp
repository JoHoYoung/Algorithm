#include <iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;
int N;

long long board[100000];


set<long long> s;
long long hi, lo;

int min(int a, int b) {
  if (a > b)return b;
  return a;
}

long long ABS(long long a) {
  if (a < 0) return -a;
  return a;
}

long long result = 1000000000000;
long long rl, rh;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> board[i];
    s.insert(board[i]);
  }

  set<long long>::iterator r = s.end(), l = s.begin();
  r--;

  while (l != r) {
    long long lo = *l;
    long long hi = *r;
    long long sum = lo + hi;

    if (ABS(sum) < ABS(result)) {
      result = ABS(sum);
      rl = lo;
      rh = hi;
    }
    if (sum > 0) {
      --r;
    } else {
      ++l;
    }
  }
  cout << rl+rh;
  return 0;
}
//5
//
//-10 -8 -5 1 7
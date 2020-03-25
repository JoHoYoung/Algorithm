#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;

int alen, blen;

string A;
string B;
string D;

int DP[201][201];

// turn true : A에서 고름
// turn B : B에서 고름
bool isFind;

bool DFS(int Aidx, int Bidx, int depth) {

  if (depth == D.size()) return true;

  int &ref = DP[Aidx][Bidx];
  if (ref != -1) return ref;
  ref = false;
  if (Aidx < alen && A[Aidx] == D[depth]) {
    ref |= DFS(Aidx + 1, Bidx, depth + 1);
  }
  if (Bidx < blen && B[Bidx] == D[depth]) {
    ref |= DFS(Aidx, Bidx + 1, depth + 1);
  }
  return ref;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int tc = N;
  while (tc--) {
    cin >> A >> B >> D;
    memset(DP, -1, sizeof(DP));
    alen = A.size();
    blen = B.size();
    if (DFS(0, 0, 0)) cout << "Data set " << N - tc << ": " << "yes\n";
    else cout << "Data set " << N - tc << ": " << "no\n";
  }
  return 0;
}


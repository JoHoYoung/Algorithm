#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int DP[1010][1010] = {0};

string A;
string B;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

void sol() {
  if (A[0] == B[0]) DP[0][0] = 1;
  else DP[0][0] = 0;

  for (int iB = 1; iB < B.size(); iB++) {
    if (A[0] == B[iB]) DP[0][iB] = 1;
    else DP[0][iB] = DP[0][iB - 1];
  }

  for (int iA = 1; iA < A.size(); iA++) {
    if (B[0] == A[iA]) DP[iA][0] = 1;
    else DP[iA][0] = DP[iA - 1][0];
  }

  for (int iA = 1; iA < A.size(); iA++) {
    for (int iB = 1; iB < B.size(); iB++) {
      if (A[iA] == B[iB]) DP[iA][iB] = DP[iA - 1][iB - 1] + 1;
      else DP[iA][iB] = max(DP[iA][iB - 1], DP[iA - 1][iB]);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B;
  A = '#' + A;
  B = '@' + B;
  sol();
  string ans;


  int iA = A.size() - 1;
  int iB = B.size() - 1;
  while (iA > 0 && iB > 0) {
    if (iB != 0 && DP[iA][iB] == DP[iA][iB - 1]) iB--;
    else if (iA != 0 && DP[iA - 1][iB] == DP[iA][iB]) iA--;
    else {
      ans.push_back(A[iA]);
      iA--;
      iB--;
    }
  }

  cout << DP[A.size() - 1][B.size() - 1] << '\n';
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
  return 0;
}
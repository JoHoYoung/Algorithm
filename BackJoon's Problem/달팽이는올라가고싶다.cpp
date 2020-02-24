#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int A, B, V;

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> A >> B >> V;

  int dif = A - B;

  int left = 0;
  long long right = 10000000000;
  long long result = 10000000000;

  while (left <= right) {
    long long mid = (left + right) / 2;
    long long dist = dif * (mid - 1) + A;

    if (dist >= V) {
      right = mid - 1;
      result = min(result, mid);
    } else if (dist < V) {
      left = mid + 1;
    }
  }
  cout << result;
  return 0;
}
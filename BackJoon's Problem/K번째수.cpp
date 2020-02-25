#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, k;

// 1 2 3 4 5 6 7 8 9
// 2 4 6 8 10 12 14 16 18
// 3 6 9 12 15 18 21 24 27
// 4 8 12 16 20 24 28 32 36
// 5 10 15 20 25 30 35 40 45
// 6 12 18 24 30 36 42 48 54
// 7 14 21 28 35 42 49 56 63
// 8 16 24 32 40 48 56 64 72
// 9 18 27 36 45 54 63 72 81
int binary_search(int left, int right) {

  if (left > right) return left;
  int mid = (left + right) / 2;
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (n > mid / i) {
      cnt += mid / i;
    } else {
      cnt += n;
    }
  }
  if (cnt < k) return binary_search(mid + 1, right);
  else return binary_search(left, mid - 1);
}

int main() {
  scanf("%d %d", &n, &k);

  printf("%d", binary_search(1, k));

  return 0;
}
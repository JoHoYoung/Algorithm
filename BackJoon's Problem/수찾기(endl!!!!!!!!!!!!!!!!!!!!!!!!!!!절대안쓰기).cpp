#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int board[100000];
int toFind[100000];
int result[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> toFind[i];
  }
  sort(board, board + n);
  for (int tc = 0; tc < m; tc++) {
    int key = toFind[tc];
    int left = 0;
    int right = n - 1;
    int find = false;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (board[mid] == key) {
        find = true;
        break;
      }
      if (board[mid] > key) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (find) {
      result[tc] = 1;
    } else {
      result[tc] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    printf("%d\n", result[i]);
  }
  return 0;
}
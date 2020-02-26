#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int N, M, L;

int board[100];
int result = 30000;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int numberToMin(int from, int minTo) {
  int divide = 1;
  while ( ( from / divide )  > minTo) {
    divide++;
  }
  return divide;
}

// 최대 공백을 n으로 하려면.. 사이의 길이가 2N보다 큰게 없어야 함
bool sol(int maxDist) {
  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    int dist = board[i + 1] - board[i];
    cnt += (dist-1) / maxDist;
    if (cnt > M) {
      return false;
    }
  }
  return true;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> L;

  board[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
  }
  board[N + 1] = L;
  N += 2;

  sort(board, board +N);

  // M개의 휴개소를 지어...
  // M개의 휴개소..
  // 제일 긴구간을.. 없애..

  int left = 0;
  int right = 1000;

  // 82 201 411 555 622 755
  //  119 210 144 67 133
  // 제일 긴 구간을 mid로 만드는 경우


  while (left <= right) {
    int mid = (left + right) / 2;
    if (sol(mid)) {
      right = mid - 1;
      result = min(result, mid);
    } else {
      left = mid + 1;
    }
  }
  cout << result;
  return 0;
}

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

// �ִ� ������ n���� �Ϸ���.. ������ ���̰� 2N���� ū�� ����� ��
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

  // M���� �ް��Ҹ� ����...
  // M���� �ް���..
  // ���� �䱸����.. ����..

  int left = 0;
  int right = 1000;

  // 82 201 411 555 622 755
  //  119 210 144 67 133
  // ���� �� ������ mid�� ����� ���


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

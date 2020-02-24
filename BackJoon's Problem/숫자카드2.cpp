#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M;

int board[500000];
int board2[500000];

// lower bound
int bs(int target) {

  int left = 0;
  int right = N;
  while (left < right) {
 //   cout << left << " " << right << endl;
    int pivot = (left + right) / 2;
    if (board[pivot] >= target) {
      right = pivot;
    } else {
      left = pivot + 1;
    }
  }
  return right;
}

//upper bound
int bs2(int target) {
  int left = 0;
  int right = N;
  while (left < right) {
    int pivot = (left + right) / 2;
    //cout << left << " " << right << " " << pivot << endl;
    if (board[pivot] > target) {
      right = pivot;
    } else {
      left = pivot +1;
    }
  }
  return right;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  cin >> M;
  sort(board, board + N);
  for (int i = 0; i < M; i++) {
    cin >> board2[i];
  }

  for (int i = 0; i < M; i++) {
    cout << bs2(board2[i]) - bs(board2[i])  << " ";
  }
  return 0;
}
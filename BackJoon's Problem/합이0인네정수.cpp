#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int N;

int board[4][4000];
vector<int> groupA;
vector<int> groupB;

int findLowerBoundFromArr(vector<int> *targetArr, int targetNum) {
  int left = 0;
  int right = N * N - 1;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (targetArr->at(mid) >= targetNum) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int findUpperBoundfromArr(vector<int> *targetArr, int targetNum) {
  int left = 0;
  int right = N * N - 1;
  int mid = (left + right) / 2;
  while (left < right) {
    mid = (left + right) / 2;
    if (targetArr->at(mid) > targetNum) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if(targetArr->at(right) == targetNum){
    return right+1;
  }
  return right;
}

int main() {

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    // A, B, C, D
    cin >> board[0][i];
    cin >> board[1][i];
    cin >> board[2][i];
    cin >> board[3][i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      groupA.push_back(board[0][i] + board[1][j]);
      groupB.push_back(board[2][i] + board[3][j]);
    }
  }

  sort(groupA.begin(), groupA.end());
  sort(groupB.begin(), groupB.end());

  for (int i = 0; i < N * N; i++) {
    cout<<groupA[i]<<" ";
  }
  cout<<endl;
  for (int i = 0; i < N * N; i++) {
    cout<<groupB[i]<<" ";
  }
  cout<<endl;

  long long result = 0;
  for (int i = 0; i < N * N; i++) {
    long target = groupA[i];
    result += findUpperBoundfromArr(&groupB, -target) - findLowerBoundFromArr(&groupB, -target);
  }
  cout << result;
  return 0;
}

#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

long long X, N;

vector<long long> board;
vector<long long> board2;
vector<long long> board3;

bool travel(long long target, vector<long long> *array) {
  long long left = 0;
  long long right = array->size() - 1;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long val = array->at(mid);
    if (val == target) {
      return true;
    }
    if (val > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // 넓이, 레고조각 수,
  while (cin>>X) {
    cin>>N;
    X *= 10000000;
    // 합이 N인거
    long long temp;
    for (int i = 0; i < N; i++) {
      cin >> temp;
      if (temp == X / 2) {
        board3.push_back(temp);
      } else if (temp > X / 2) {
        board2.push_back(temp);
      } else {
        board.push_back(temp);
      }
    }

    if (N <= 1) {
      cout << "danger" << endl;
    } else {

      sort(board.begin(), board.end());
      sort(board2.begin(), board2.end());

      bool find = false;
      for (long long h = 0; h < board.size(); h++) {
        if (travel(X - board.at(h), &board2)) {
          find = true;
          cout << "yes " << board.at(h) << " " << X - board.at(h)<<endl;
          break;
        }
      }
      if (!find) {
        if (board3.size() >= 2) {
          cout << "yes " << X / 2 << " " << X / 2 << endl;
        } else {
          cout << "danger" << endl;
        }
      }
    }

    board.clear();
    board2.clear();
    board3.clear();

  }
  return 0;
}

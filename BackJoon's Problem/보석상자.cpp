#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;

int board[300000];

int getDivideMin(int numberOfMaximum) {

  int cnt = 0;
  for (int i = 0; i < M; i++) {
    int target = board[i];
    cnt += target / numberOfMaximum;
    if (target % numberOfMaximum != 0) {
      cnt++;
    }
  }
  return cnt;
}

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int result = 1000000000;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> board[i];
  }

  int left = 0;
  int right = 1000000000;

  while (left <= right) {
    int mid = (left + right) / 2;

    int temp = getDivideMin(mid);
    if (temp > N) {
      //result = min(mid , result);
      left = mid + 1;
    } else {
   ///   cout<<"MID : "<<mid<<endl;
      result = min(mid, result);
      right = mid - 1;
    }
  }
  cout << result << endl;
  return 0;
}

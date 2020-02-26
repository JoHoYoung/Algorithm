#include <iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

long long N, K, Q;

long long result[100000][2];

long long parentOfTree(int KzinTree, long long from) {
  return (from + KzinTree - 2) / K;
}

long long getDepth(long long target) {
  if (K == 1){
    return target;
  }
  int cnt = 1;
  while (target != 1) {
    target = parentOfTree(K, target);
    cnt++;
  }
  return cnt;
}

void swap(long long &a, long long &b) {
  long long temp = a;
  a = b;
  b = temp;
}

long long sol(long long smaller, long long larger) {

  if(K == 1){
    return larger - smaller;
  }
  if (larger == smaller) {
    return 0;
  }
  long long depthA = getDepth(smaller);
  long long depthB = getDepth(larger);
  long long dif = depthB - depthA;
  long long cnt = 0;
  for (int i = 0; i < dif; i++) {
    cnt++;
    larger = parentOfTree(K, larger);
  }
  while (smaller != larger) {
    cnt += 2;
    smaller = parentOfTree(K, smaller);
    larger = parentOfTree(K, larger);
  }
  return cnt;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K >> Q;

  for (int i = 0; i < Q; i++) {
    cin >> result[i][0] >> result[i][1];
    if (result[i][0] > result[i][1]) {
      swap(result[i][0], result[i][1]);
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << sol(result[i][0], result[i][1]) << "\n";
  }
  return 0;
}

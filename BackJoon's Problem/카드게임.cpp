#include <string>
#include <vector>
#include <cstring>
using namespace std;
int DP[2001][2001];

int max(int a, int b) {
  return a > b ? a : b;
}

int DFS(vector<int> &lefT, vector<int> &righT,int l, int r) {

  if(l == lefT.size() || r == righT.size()) return 0;
  int &ref = DP[l][r];
  if (ref != -1) return ref;
  ref = 0;

  int lVal = lefT[l];
  int rVal = righT[r];

  if(lVal > rVal){
    ref = rVal + DFS(lefT, righT,l,r+1);
  }

  int delL = DFS(lefT, righT,l+1, r);
  int delB = DFS(lefT, righT, l+1,r+1);

  ref = max(ref, max(delL, delB));
  return ref;
}

int solution(vector<int> left, vector<int> right) {
  memset(DP, -1, sizeof(DP));
  return DFS(left, right, 0,0);
}
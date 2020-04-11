#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, p;
vector<int> yPos[400000], xPos[400000];
int q[100001][4];
int x[300001], y[300001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  set<int> xS, yS;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    xS.insert(x[i]);
    yS.insert(y[i]);
  }

  cin >> p;
  vector<int> re;
  for (int i = 0; i < p; i++) {
    //cout << "CASE " << i << endl;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    xS.insert(x1);
    yS.insert(y1);
    xS.insert(x2);
    yS.insert(y2);
    q[i][0] = x1;
    q[i][1] = y1;
    q[i][2] = x2;
    q[i][3] = y2;
  }
  map<int, int> xH, yH;
  int X = 0;
  int Y = 0;

  for (int x : xS)
    xH[x] = X++;
  for (int y : yS)
    yH[y] = Y++;

  for (int i = 0; i < N; i++) {
    x[i] = xH[x[i]];
    y[i] = yH[y[i]];
    yPos[x[i]].push_back(y[i]);
    xPos[y[i]].push_back(x[i]);
  }
  for(int i=0;i<p;i++){
    q[i][0] = xH[q[i][0]];
    q[i][1] = yH[q[i][1]];
    q[i][2] = xH[q[i][2]];
    q[i][3] = yH[q[i][3]];
  }

  for(int i = 0; i < 400000; ++i){
    sort(xPos[i].begin(), xPos[i].end());
    sort(yPos[i].begin(), yPos[i].end());
  }

  for(int i=0;i<p;i++){
    int ans = 0;
    int x1 = q[i][0], y1 = q[i][1], x2 = q[i][2], y2 = q[i][3];
    ans += upper_bound(xPos[y1].begin(), xPos[y1].end(), x2) - lower_bound(xPos[y1].begin(), xPos[y1].end(), x1);
    ans += upper_bound(xPos[y2].begin(), xPos[y2].end(), x2) - lower_bound(xPos[y2].begin(), xPos[y2].end(), x1);
    if(y2 - y1 > 1){
      ans += lower_bound(yPos[x1].begin(), yPos[x1].end(), y2) - upper_bound(yPos[x1].begin(), yPos[x1].end(), y1);
      ans += lower_bound(yPos[x2].begin(), yPos[x2].end(), y2) - upper_bound(yPos[x2].begin(), yPos[x2].end(), y1);
    }
    cout<<ans<<"\n";
  }

  return 0;
}



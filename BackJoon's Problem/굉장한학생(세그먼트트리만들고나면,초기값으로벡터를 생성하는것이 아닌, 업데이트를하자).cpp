#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 5000001
using namespace std;
using P = pair<int, int>;

int N;

int board[3][500001];

// 굉장한 학생 수
// 모든 성적이 좋은 경우
// 학생넘버를 인덱스로?
// 아니면 번호 특정학생의 등수를 인덱스로?

struct student {
    int stdNo, rank;
};

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

bool comp(student a, student b) {
  return a.rank < b.rank;
}

void update(vector<int> &tree, int index, int node, int value, int l, int r) {
  if (index < l || index > r) return;
  // cout<<"Update node["<<node<<"] + dif"<<endl;
  if (l != r) {
    int mid = (l + r) / 2;
    update(tree, index, node * 2, value, l, mid);
    update(tree, index, node * 2 + 1, value, mid + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  } else {
    tree[node] = value;
  }
}

int query(vector<int> &tree, int node, int start, int end, int l, int r) {
  if (start > r || end < l) return MAXN;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return min(query(tree, node * 2, start, mid, l, r) ,query(tree, node * 2 + 1, mid + 1, end, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  vector<student> S;
  // 등수가 인덱스가 되고, 사람 인덱스가
  int temp;
  for (int j = 1; j <= N; j++) {
    cin >> temp;
    S.push_back({temp, j});
  }
  S.push_back({0, 0});
  sort(S.begin(), S.end(), comp);

  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> temp;
      board[i][temp] = j;
    }
  }

  vector<int> tree(4 * N + 5,  MAXN);

  cout<<tree[10]<<endl;
  student target = S[1];

  for(int i=1;i<=N;i++) update(tree,i,1,MAXN,1,N);
  update(tree, board[0][target.stdNo], 1, board[1][target.stdNo], 1, N);
  int cnt = 1;
  // 나는 굉장하다.
  // it 기준으로. 앞에거 나보다 큰 애들 정렬해서 업데이트 했음
  // 지금 트리를 기준으로, 나보다 등수가 낮은(숫자가 높은)친구가 앞에 애들 숫자 만큼 있어야 함.
  for (int it = 2; it < S.size(); it++) {
    student target = S[it];
    int mySecondRank = board[0][target.stdNo];
    int myThirdRank = board[1][target.stdNo];
    // 나보다 등수가 낮은 애들의 세번?등수의 최솟값
    int getMinimumThirdRank = query(tree, 1, 1, N, 1, mySecondRank );
    if(getMinimumThirdRank > myThirdRank) cnt++;
    update(tree, mySecondRank, 1, myThirdRank, 1, N);
  }

  cout << cnt;
  return 0;
}

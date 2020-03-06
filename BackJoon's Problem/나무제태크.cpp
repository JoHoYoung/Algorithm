#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

int N, M, K;
int board[20][20];
int A[20][20];
int Di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
typedef struct unit {
    int i, j, age;
};

// Ʈ���� ���̸� ����
vector<int> trees[20][20];
vector<unit> deadTree;

// �� : ���̸�ŭ ����� �԰� ���� 1����
// ���� : �����͵��� ������� ���Ѵ�
//������ ���� ������ 2��ŭ ������� �߰�
// ���� : ���� ���̰� 5�ǹ���ΰŸ� ����, 8�����⿡ 1�� ������ �߰�
// �ܿ￡�� ����� �߰�


void spring() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
   //   cout<<"LL";
      sort(trees[i][j].begin(), trees[i][j].end());
      vector<int> tree = trees[i][j];
      // ���������� ���� ���� �ε���
      int lastdex = 0;
      for (int k = 0; k < tree.size(); k++) {
        int targetAge = tree[k];
        //cout<<"AT "<<i<<" "<<j<<" "<<k<<endl;
        //cout<<"FEED : "<<board[i][j]<<" cost "<<targetAge<<endl;
        if (board[i][j] < targetAge) break;
        board[i][j] -= targetAge;
        trees[i][j][k]++;
        lastdex++;
      }
      for (int k = lastdex; k < tree.size(); k++) {
      //  cout<<"DEAD At "<<i<<" "<<j<<" LIFE : "<<tree[k]<<endl;
        deadTree.push_back({i, j, tree[k]});
      }
      if(lastdex != tree.size()) trees[i][j].erase(trees[i][j].begin() + lastdex, trees[i][j].end());
    }
  }
}


void summer() {
  //cout<<"DEAD"<<deadTree.size()<<endl;
  for (int i = 0; i < deadTree.size(); i++) {
    unit target = deadTree[i];
    board[target.i][target.j] += target.age/2;
  }
  deadTree.clear();
}

void add(int i, int j) {
  for (int d = 0; d < 8; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1) continue;
    trees[ni][nj].push_back(1);
  }
}

void authm() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vector<int> tree = trees[i][j];
      for (int k = 0; k < tree.size(); k++) {
        int targetAge = tree[k];
      //  cout<<"TARGET AGE : "<<targetAge<<endl;
        if (targetAge % 5 == 0) add(i, j);
      }
    }
  }
}

void winter() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] += A[i][j];
    }
  }
}

int count() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vector<int> tree = trees[i][j];
      cnt += tree.size();
    }
  }
  return cnt;
}

void yearGone(){
  spring();
  //cout<<"SPINRG";
  summer();
  authm();
  winter();
}
// k���� ����ִ� ���� ��
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      board[i][j] = 5;
    }
  }

  int i, j, age;
  //� �������� ����� �Դ´�.
  // ���� ���ϰ� ��� �״´�.

  for (int t = 0; t < M; t++) {
    cin >> i >> j >> age;
    trees[i-1][j-1].push_back(age);
  }

  for(int i=0;i<K;i++){
    //cout<<"GOGO"<<endl;
    yearGone();
  }
  cout<<count();
  return 0;
}
#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int n,k,s;

int solve[50000][2];

int board[401][401];

struct Point{
    int type;
    int pos;
    vector<int> parents;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  cin>>k;

  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      board[i][j] = 0;
    }
  }

  vector<int> myParents[n+1];
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a;
    cin>>b;
    board[a][b] = -1;
    board[b][a] = 1;

    myParents[b].push_back(a);
  }

  cin>>s;

  for(int i=0;i<s;i++){
    cin>>solve[i][0];
    cin>>solve[i][1];
  }

  queue<Point> Q;
  vector<int> result;

  for(int t=0;t<s;t++){

    bool visited[n+1];
    bool visited1[n+1];

    int start = solve[t][0];
    int destination = solve[t][1];

    if(board[start][destination] != 0){
      result.push_back(board[start][destination]);
      continue;
    }

    for(auto it = myParents[start].begin(); it != myParents[start].end(); it++){
      vector<int> n;
      Q.push(Point{0, (*it),n});
    }

    for(auto it = myParents[destination].begin(); it != myParents[destination].end(); it++){
      vector<int> n;
      Q.push(Point{1, (*it),n});
    }

    bool find = false;
    while(!Q.empty()){
      Point target = Q.front();
      Q.pop();

      if(board[start][destination] != 0){
        result.push_back(board[start][destination]);
        continue;
      }

      if(target.type == 0){
        if(target.pos == destination){
          find = true;
          result.push_back(1);
          while(!Q.empty()){
            Q.pop();
          }
          break;
        }
        for(auto it = myParents[target.pos].begin(); it != myParents[target.pos].end(); it++){
          if(!visited[(*it)]){
            visited[(*it)] = true;
            for(auto p = target.parents.begin();p != target.parents.end();p++){
              board[(*p)][(*it)] =-1;
              board[(*it)][(*p)] =1;
            }
            vector<int> n;
            n.assign(target.parents.begin(),target.parents.end());
            n.push_back(target.pos);
            Q.push(Point{0,(*it),n});
          }
        }
      }else{
        if(target.pos == start){
          find = true;
          result.push_back(-1);
          while(!Q.empty()){
            Q.pop();
          }
          break;
        }
        for(auto it = myParents[target.pos].begin(); it != myParents[target.pos].end(); it++){
          if(!visited1[(*it)]){
            visited1[(*it)]=true;
            visited[(*it)] = true;
            for(auto p = target.parents.begin();p != target.parents.end();p++){
              board[(*p)][(*it)] =-1;
              board[(*it)][(*p)] =1;
            }
            vector<int> n;
            n.assign(target.parents.begin(),target.parents.end());
            n.push_back(target.pos);
            Q.push(Point{1,(*it),n});
          }
        }
      }
    }
    while(!Q.empty()){
      Q.pop();
    }
    if(!find){
      result.push_back(0);
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }


  for(auto it = result.begin(); it!=result.end();it++){
    cout<<(*it)<<endl;
  }

  return 0;
}
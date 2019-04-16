// BFS DFS

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int Map[10002][10002];


int queue[10002];
int head = 0;
int rear = 0;
int N;

void push(int x)
{
    queue[rear++] = x;
}

int pop() {
    if(head == rear)
        return -1;

    return queue[head++];
}

bool visited[10002];

void dfs(int V)
{
    visited[V]=true;
    for(int i=1;i<=N;i++)
    {
        if(Map[V][i] == 1 && !visited[i]) {
            cout<<i;
            visited[i] = true;
            dfs(i);
        }
    }
}

void bfs(int V){

    while(head!=rear)
    {
        V = pop();
        visited[V]=true;
        for(int i=1;i<=N;i++)
        {;
            if(Map[V][i] == 1 && !visited[i]) {
                visited[i] = true;
                cout<<i;
                push(i);
            }
        }
    }
}

int main()
{
    int M,V;
    cin>>N;
    cin>>M>>V;

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        Map[a][b] = 1;
        Map[b][a] = 1;
    }

    push(V);

    cout<<V;
    dfs(V);
    cout<<endl;

    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    cout<<V;
    bfs(V);
    return 1;
}
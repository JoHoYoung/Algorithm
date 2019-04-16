#include<vector>
#include<string>
#include <cstdio>
using namespace std;

typedef struct{
    int dx;
    int dy;
}Dxy;

typedef struct{
    int x;
    int y;
    int holenum;
}Pos;

typedef struct{
    int x;
    int y;
    int dir;
}unit;

unit data;
vector<Pos> hole;
// Dir
int U = 0;
int R = 1;
int D = 2;
int L = 3;

int block[6][4];
int map[106][106];
Dxy A[4] = {{-1,0},{0,1},{1,0},{0,-1}};


// 블록 만났을때.
Pos findHole(int x,int y,int num){

    for(int i=0;i<hole.size();i++){
        if((hole[i].holenum == num)&&(hole[i].x != x || hole[i].y != y)) {
            return hole[i];
        }
    }
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int N;
int Gscore = 0;
int initx, inity, dir;
int score = 0;

int loop()
{

    while(1){
        // cout<<"Now X: "<<nowx<<" ,Now Y: "<<nowy<<" Now dir: "<<dir<<" BLOCK :"<<map[nowx][nowy]<<endl;
        if((data.x == initx && data.y == inity && score !=0) || (map[data.x][data.y] == -1)){
            //  cout<<"END at Initial pos | Score :  "<<score<<endl;
            Gscore = max(score, Gscore);
            score = 0;
            break;
        }

        if(map[data.x][data.y] >= 6) {
            Pos holeP = findHole(data.x, data.y, map[data.x][data.y]);
            data.x = holeP.x + A[data.dir].dx;
            data.y = holeP.y + A[data.dir].dy;
            continue;
        }

        if(map[data.x][data.y]>=1 && map[data.x][data.y]<=5){
            score++;
            data.dir = block[map[data.x][data.y]][data.dir];
            data.x += A[data.dir].dx;
            data.y += A[data.dir].dy;
            continue;
        }

        data.x += A[data.dir].dx;
        data.y += A[data.dir].dy;
        // 지금 현재위치, 블락번호, 방향, 점수,등을 고려
    }

    return 0;
}
int main(){

    int T;
    scanf("%d",&T);
    //cin>>T;
    block[1][U] = D; block[1][R] = L; block[1][D] = R; block[1][L] = U;
    block[2][U] = R; block[2][R] = L; block[2][D] = U; block[2][L] = D;
    block[3][U] = L; block[3][R] = D; block[3][D] = U; block[3][L] = R;
    block[4][U] = D; block[4][R] = U; block[4][D] = L; block[4][L] = R;
    block[5][U] = D; block[5][R] = L; block[5][D] = U; block[5][L] = R;

    for(int k=0;k<T;k++){

        hole.clear();
        scanf("%d",&N);
        //cin>>N;

        for(int i=0;i<N+2;i++){
            for(int j=0;j<N+2;j++){
                if(i==0 || j==0 || i==N+1 || j==N+1) {
                    map[i][j] = 5;
                }
                else
                {
                    scanf("%d",&map[i][j]);
                    //cin>>map[i][j];
                    if(map[i][j] >=6){
                        //      cout<<"PUSH to HOLE Pos("<<i<<", "<<j<<")"<<endl;
                        hole.push_back(Pos{i,j,map[i][j]});
                    }
                }

            }
        }

        for(int x=1;x<N+1;x++){
            for(int y=1;y<N+1;y++){
                if(map[x][y] == 0){
                    initx = x;
                    inity = y;

                    score = 0;
                    // --- 여기까지 ok ----
                    // cout<<"Start at initial Pos : ("<<initx<<", "<<inity<<")"<<endl;
                    for(int d=0;d<4;d++){
                        // cout<<"Loop For Each Direction | Now : "<<d<<endl;
                        dir = d;
                        data = {x, y, dir};
                        loop();
                    }

                }
            }
        }
        printf("#%d %d\n",k+1,Gscore);
        Gscore = 0;
        //cout<<"#"<<k+1<<" "<<Gscore<<endl;
    }

    return 0;
}

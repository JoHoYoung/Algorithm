// 왼쪽상단, 오른쪽상단, 오른쪽하단, 왼쪽 하단
let Pos = [[[0,1],[1,0],[1,1]]];

// 맨위면 상단 X
// 맨 왼쪽이면 왼쪽 X
// 맨 오른쪽이면 오른쪽 X
// 맨 아래면 하단 X

let toDelete = [];
let board = [];
function FIND(i,j,m,n){
    let pivot = board[i][j];

    if(pivot === '*'){
        return;
    }

    for(let a=0;a<Pos.length;a++){
        let find = true;

        for(let b=0;b<Pos[a].length;b++){
            let I = i+Pos[a][b][0];
            let J =  j+Pos[a][b][1];
            if( I < 0 || I >= m || J>=n || J<0 ){
                find = false;
                break;
            }
            if(board[I][J] !== pivot){
                find = false;
                break;
            }
        }

        if(find){
            toDelete.push([i,j]);
            for(let q=0;q<Pos[a].length;q++){
                toDelete.push([i+Pos[a][q][0],j+Pos[a][q][1]]);
            }
        }
    }
}

function reArragneMap(m,n){
    for(let j=0;j<n;j++){
        for(let i=m-1;i>=0;i--){
            if(board[i][j] === '*'&& i!==0){
                for(let k=i-1;k>=0;k--){
                    if(board[k][j] !== '*'){
                        let temp = board[k][j];
                        board[k][j] = '*';
                        board[i][j] = temp;
                        break;
                    }
                }
            }
        }
    }
}

function solution(m, n, map) {
    let answer = 0;
    for(let i=0;i<map.length;i++){
        board.push(map[i].split(''))
    }
    while(1) {
        toDelete = [];
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                FIND(i, j, m, n)
            }
        }

        if (toDelete.length === 0) {
            break;
        }

        for (let i = 0; i < toDelete.length; i++) {
            board[toDelete[i][0]][toDelete[i][1]] = '*';
        }
        reArragneMap(m, n);
        //  console.log(board)
    }
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(board[i][j] === '*'){
                answer++;
            }
        }
    }
    return answer;
}
let arr = ["CCBDE", "AAADE", "AAABF", "CCBBF"]
solution(6,6,["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]);

let map;
let Dir1 = [{i:1,j:0},{i:2,j:0},{i:2,j:1}];
let Dir2 = [{i:1,j:0},{i:2,j:0},{i:2,j:-1}];
let Dir3 = [{i:1,j:0},{i:1,j:1},{i:1,j:2}];
let Dir4 = [{i:1,j:0},{i:1,j:-1},{i:1,j:-2}];
let Dir5 = [{i:1,j:0},{i:1,j:-1},{i:1,j:1}];

let Dir = [Dir1,Dir2,Dir3,Dir4,Dir5];
let DEX = [];
let setJ = new Set();
let ttaa;
let count = 0;
let shape;

// shape 0이면 둘중 큰거
// 1이면 둘중 작은거
// 2이면 제일작은거밴
// 3이면 제일 큰거밴
// 4이면 중간거만 밴
function CanBlock(leftest, uppest) {
    let pivot = map[leftest][uppest];
    for(let i=0;i<5;i++){
        let flag = false;
        DEX.push([leftest, uppest]);
        setJ.add(uppest);

        for(let j=0;j<3;j++){
            let newI = leftest + Dir[i][j].i;
            let newJ = uppest + Dir[i][j].j;

            if(newI < 0 || newI >=map.length || newJ < 0 || newJ >= map.length) {
                DEX = [];
                setJ.clear();
                flag = false;
                break;
            }

            if(map[newI][newJ] !== pivot){
                DEX = [];
                setJ.clear();
                flag = false;
                break;
            }

            setJ.add(newJ);
            DEX.push([newI,newJ]);
            if(j === 2){
                shape = i;
                flag = true;
                break;
            }
        }

// shape 0이면 둘중 큰거
// 1이면 둘중 작은거
// 2이면 제일작은거밴
// 3이면 제일 큰거밴
// 4이면 중간거만 밴

        if(flag === true){
            switch(shape){
                case 0:
                    ttaa = [uppest+1];
                    break;
                case 1:
                    ttaa = [uppest-1];
                    break;
                case 2:
                    ttaa = [uppest+1,uppest+2];
                    break;
                case 3:
                    ttaa = [uppest-1,uppest-2];
                    break;
                case 4:
                    ttaa = [uppest-1,uppest+1];
                    break;
            }
            for(let q=0;q<ttaa.length;q++) {
                for(let k =0 ;k<map.length;k++){
                    if(map[k][ttaa[q]] === pivot){
                        break;
                    }else if(map[k][ttaa[q]] !== 0 && map[k][ttaa[q]] !== pivot){
                        flag = false;
                        break;
                    }

                }

            }
            if(flag === true){
                count++;
                for(let k =0 ;k<DEX.length;k++){
                    map[DEX[k][0]][DEX[k][1]] = 0;
                }
                setJ.clear();
                DEX = [];
                break;
            }else{
                setJ.clear();
                DEX = [];
                break;
            }
        }
        else{
            setJ.clear();
            DEX = [];
        }

    }
}


function solution(board) {
    map = board;
    let N = board.length;
    while(1){
        let temp = count;
        for(let i=0;i<N;i++){
            for(let j = 0;j<N;j++){
                if(map[i][j] > 0){
                    CanBlock(i,j);
                }
            }
        }
        if(temp === count){
            break;
        }
    }
    return count;
}
// // //
// let Arr =[[0,0,0,0,0,0,0,0,0,0],
//     [0,0,0,0,0,0,0,0,0,0],
//     [0,0,0,0,0,0,0,0,0,0],
//     [0,0,0,0,0,0,0,0,0,0],
//     [0,0,0,0,0,0,4,0,0,0],
//     [0,0,0,0,0,4,4,4,0,0],
//     [0,0,0,0,3,0,0,0,0,0],
//     [0,0,0,2,3,0,0,0,5,5],
//     [1,2,2,2,3,3,0,0,0,5],
//     [1,1,1,0,0,0,0,0,0,5]]
//
// console.log(solution(Arr));
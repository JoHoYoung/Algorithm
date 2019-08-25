//벽은 벽.. 하나라도 벽ㅇ인건 벽

function Num(num){
    let a =1;
    for(let i=0;i<num;i++){
        a*=2;
    }
    return a;
}
// 16비트 라는 것.
function intToBytearr(n,num){
    let pivot = Num(n-1);
    let arr = [];
    while(pivot >= 1) {
        if(num >= pivot){
            arr.push(1);
            num = num - pivot;
        }else{
            arr.push(0)
        }
        pivot /= 2;
    }
    return arr;
}
function calculate(arr1,arr2){
    let arr = [];
    for(let i=0;i<arr1.length;i++){
        if(arr1[i] === 1 || arr2[i] === 1){
            arr.push(1)
        }else{
            arr.push(0)
        }
    }
    return arr;
}

function mapToAnswer(map){
    let arr = [];
    for(let i=0;i<map.length;i++){
        let str ="";
        for(let j=0;j<map[i].length;j++){
            if(map[i][j] === 0){
                str = `${str} `
            }else{
                str = `${str}#`
            }
        }
        arr.push(str)
    }
    return arr;
}

function solution(n, arr1, arr2) {
    let map = [];
    for(let i=0;i<n;i++){
        let a = intToBytearr(n,arr1[i]);
        let b = intToBytearr(n,arr2[i]);
        map.push(calculate(a,b))
    }
    let a = mapToAnswer(map);
    return a;
}
let n = 5;
let arr1 = [9, 20, 28, 18, 11]
let arr2 = [30, 1, 21, 17, 28]
solution(n,arr1,arr2);
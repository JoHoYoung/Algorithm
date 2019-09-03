// n번째 단어까지 입력했는데 겹치는게 있으면.. +1
// 없으면 그것이 피봇.

// 첫글자가 같은것들끼리 조합
// 두번째 글자가 같은것들끼리 조합
// 세번째 글자가 같은것들끼리 조합

let result = 0;

function recur(arr,idx){
    for(let i=0;i<arr.length;i++){
        if(arr[i].length === idx){
            result += arr[i].length;
        }
    }
    for(let i=0;i<26;i++){
        let c = String.fromCharCode('a'.charCodeAt(0) + i)
        let arr2 = arr.filter(el => {
            return el[idx] === c});
        if(arr2.length > 1){
            recur(arr2,idx+1,c)
        }
        if(arr2.length === 1){
            result +=idx+1;
        }
    }
}

function solution(words) {

    for(let i=0;i<26;i++){
        let c = String.fromCharCode('a'.charCodeAt(0) + i);
        let arr2 = words.filter(el => el[0] === c);
        if(arr2.length > 1){
            recur(arr2,1)
        }
        if(arr2.length === 1){
            result +=1;
        }
    }
    console.log(result);
    return result;
}
solution(["g","gb"]);
//solution([ 'go', 'gone', 'guild' ] );
let result = 0;
function recur(arr,idx){

    for(let i=0;i<arr.length;i++){
        if(arr[i].length === idx){
            result += arr[i].length;
        }
    }

    for(let i=0;i<26;i++){
        let c = String.fromCharCode('a'.charCodeAt(0) + i);
        let arr2 = arr.filter(el => el[idx] === c);
        if(arr2.length > 1){
            recur(arr2,idx+1,c)
        }
        if(arr2.length === 1){
            result +=idx+1;
        }
    }
}

function solution(words) {
    recur(words,0);
    return result;
}
solution(["g","gb"]);
//solution([ 'go', 'gone', 'guild' ] );
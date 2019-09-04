let dict = {
    "0":"0",
    "1":"1",
    "2":"2",
    "3":"3",
    "4":"4",
    "5":"5",
    "6":"6",
    "7":"7",
    "8":"8",
    "9":"9",
    "10":"A",
    "11":"B",
    "12":"C",
    "13":"D",
    "14":"E",
    "15":"F",
};

function deciToN(deci, N){
    let arr = [];
    let pivot = 1;
    while(1) {
        pivot *= N;
        if(pivot > deci){
            pivot /= N;
            break;
        }
    }
    while(1) {
        arr.push(dict[parseInt(deci/pivot).toString()]);
        deci = deci % pivot;
        pivot /= N;
        if(pivot < 1){
            break;
        }
    }
    return arr;
}

function solution(n, t, m, p) {

    let numberMax = t * m;
    let data = [];
    let idx = 0;

    while(data.length <= numberMax){
        data = data.concat(deciToN(idx++, n))
    }
    let result = "";
    let pivot = p-1;
    while(result.length <= t-1){
        result = result + data[pivot];
        pivot += m;
    }

    console.log(result);
    return result;
}
solution(16,16,2,1);
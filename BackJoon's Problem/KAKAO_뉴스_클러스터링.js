function strToGroup(str){
    let arr = [];
    for(let i=1;i<str.length;i++){
        let left = str[i-1].toLowerCase();
        let now = str[i].toLowerCase();
        if(now>'z' || now<'a'){
            i++;
            continue;
        }
        if(left >'z' || left<'a'){
            continue;
        }
        arr.push(left+now)
    }
    console.log(arr)
    return arr
}

// 중복 허용가능

function solution(str1, str2) {
    let answer;
    let arr1 = strToGroup(str1);
    let arr2 = strToGroup(str2);

    if(str1.toLowerCase() === str2.toLowerCase())
    {
        return 65536;
    }
    let share = 0;
    let sum;
    for(let i=0;i<arr1.length;i++){
        let left = arr1[i];
        let find = false;
        for(let j=0;j<arr2.length;j++){
            let right = arr2[j];
            if(left === right){
                share ++;
                find = true;
                arr2.splice(j,1);
                break;
            }
        }
        if(find){
            arr1.splice(i,1);
            i--;
        }
    }
    sum = share + arr1.length + arr2.length;
    answer = parseInt((share/sum)*65536);
    return answer;
}

a = solution("aa1+aa2","AAAA12");
console.log(a)
function getCode(al){
    return al.charCodeAt(0);
}
// 사전에 있는 제일 긴 글자를 찾아야 함.
let dict = {};
function solution(msg) {
    msg = msg.toLowerCase();
    let result = [];
    let dpivot = 27;

    for(let i=0;i<="z".charCodeAt(0) - "a".charCodeAt(0); i++) {
        dict[String.fromCharCode(i+"a".charCodeAt(0))] = i+1;
    }

    for(let i=0;i<msg.length;i++){
        if(i === msg.length-1){
            result.push(dict[msg[i]]);
            break;
        }

        let temp = msg[i];
        // 사전에 없는 제일 긴 글자 찾음
        while(dict[temp] !== undefined && i !== msg.length-1){
            i++;
            temp = temp + msg[i];
        }
        if(dict[temp] !== undefined){
            result.push(dict[temp]);
            break;
        }
        dict[temp] = dpivot++;
        if(temp.length === 1){
            result.push(dict[temp]);
        } else {
            result.push(dict[temp.substring(0, temp.length-1)]);
        }
        i--;
    }
    return result;
}
solution("ABABABABABABABAB")
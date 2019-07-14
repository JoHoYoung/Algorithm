
let map = {};

function process(chars){
    let words = chars.split(' ');
    let command = words[0];
    let uid = words[1];
    let name = words[2];

    switch(command){
        case "Enter":
            map[uid] = name;
            break;
        case "Change":
            map[uid] = name;
            return '';
    }
}

/**
 * @return {string}
 */
function Rprocess(chars){
    let words = chars.split(' ');
    let command = words[0];
    let uid = words[1];

    switch(command){
        case "Enter":
            return `${map[uid]}님이 들어왔습니다.`;
        case "Leave":
            return `${map[uid]}님이 나갔습니다.`;
    }
}


function solution(record) {
    var answer = [];

    for(let i=0; i<record.length;i++){
        process(record[i])
    }
    for(let i=0; i<record.length;i++){
        let result = Rprocess(record[i]);
        if (result !== '' && result){
            answer.push(result);
        }
    }
    return answer;
}

let a = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
solution(a)
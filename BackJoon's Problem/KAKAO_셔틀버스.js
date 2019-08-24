let min = 1;
let hour = 60;

function timeToMin(str){
    let result = [];
    for(let i=0;i<str.length;i++){
        let arr = str[i].split(":");
        let h =parseInt(arr[0]);
        let m =parseInt(arr[1]);

        result.push(h*hour + m*min);
    }
    return result;
}
function genBus(n,t){
    let arr = [];
    let start = 9*hour;
    for(let i=0;i<n;i++){
        arr.push({time:start + t*i*min,users:[]});
    }
    return arr;
}
function solution(n, t, m, timetable) {
    let answer = '';

    let bus = genBus(n,t);

    let users = timeToMin(timetable);
    users.sort((a,b) => {
       return a-b;
    });

    let emptyPivot = 0;
    console.log("USERS",users);
    for(let i=0;i<users.length;i++){
        console.log("EMPTY PIVOT : ",emptyPivot);
        if(emptyPivot >= bus.length){
            break;
        }
        if(bus[emptyPivot].time>=users[i] && bus[emptyPivot].users.length < m){// 더 빨리도착하는 버스
            bus[emptyPivot].users.push(users[i]);

        }else{
            emptyPivot ++;
            i--;
        }
    }
    let target = bus[bus.length-1];
    if(target.users.length === m){
        answer = target.users[target.users.length -1] -1;
    }else{
        answer = target.time;
    }
    let H;
    let M;
    if(parseInt(answer/hour) < 10){
        H = `0${parseInt(answer/hour)}`
    }else{
        H = parseInt(answer/hour).toString()
    }

    if(answer%hour < 10){
        M = `0${answer%hour}`
    }else{
        M = (answer%hour).toString()
    }
    console.log(bus);
    return `${H}:${M}`;
}

let n = 2;
let t = 1;
let m = 2;
let timetable = ["09:00", "09:00", "09:00", "09:00"];
a = solution(n,t,m,timetable)
console.log(a)
// t분 간격으로 n회 m명
// 탈 수 있는 제일 늦은 도착시간.
// 09 10 11 12 13 14 15 16 17 18
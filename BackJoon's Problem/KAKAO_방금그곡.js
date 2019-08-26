let map = {
    "C":"a",
    "C#":"b",
    "D":"c",
    "D#":"d",
    "E":"e",
    "F":"f",
    "F#":"g",
    "G":"h",
    "G#":"i",
    "A":"j",
    "A#":"k",
    "B":"l"
};
function resetStr(str){
    let i = 1;
    let temp = "";
    let re = "";
    temp = str[0];
    while(1){
        let char = str[i];
        if(char === '#'){
            temp = temp+char;
        }else{// #이 아닌 음일때만 푸쉬
            re = re+map[temp];
            temp = char;
        }
        i++;
        if(i === str.length){
            re = re + map[temp];
            break
        }
    }
    return re;
}

function played(str,time){
    let re = '';
    let pivot = str.length;
    let idx =0;
    let melody = str.split('');
    for(let i=0;i<time;i++){
        re = re + melody[(idx++)%pivot];
    }
    return re;
}

// 예외.
// 기억하는게 더 길수도 있다.
// 기억하는게 제시된거의 총 재생시간보다 길 수 는 없을듯.
function solution(m, musicinfos) {
    // 음의 길이 1~1439
    // 1분 : 60
    // 20분 : 1200
    // 두개 이으면 그중에는 있겠네.
    // a,b,c,d, e,f,g,h, i,z,k,l
    let data = [];
    m = resetStr(m);
    for(let i=0;i<musicinfos.length;i++) {

        let arr = musicinfos[i].split(',');

        let name = arr[2];
        let melody = resetStr(arr[3]);

        let start = arr[0].split(":");
        let startT = parseInt(start[0])*60 + parseInt(start[1]);

        let end = arr[1].split(":");
        let endT = parseInt(end[0])*60 + parseInt(end[1]);

        let runningTime = endT - startT+1;
        let playedMelody = played(melody,runningTime);
        data.push({name,play : playedMelody});
    }
    let result = {name:"",play:""};
    for(let i=0;i<data.length;i++){
        if (data[i].play.indexOf(m) !== -1){
            if(result.play.length < data[i].play.length)
            result = data[i];
        }
    }
    if(result.name === ""){
        return "'(None2)'"
    }

    return result.name
}
solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]);
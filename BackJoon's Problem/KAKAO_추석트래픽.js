const window = {
    start:0,
    end :0
};

function solution(lines) {
    let ms = 1;
    let sec = 1000*ms;
    let min = 60*sec;
    let hour = 60*min;
    let Milis = [];

    for(let i=0;i<lines.length;i++){
        let arr = lines[i].split(' ');
        let time = arr[1].split(':');

        let H = parseInt(time[0]);
        let M = parseInt(time[1]);
        let S = parseFloat(time[2]);
        let ms = S*sec + M*min + H*hour;
        let T = arr[2].substring(0,arr[2].length-1);
        Milis.push({start:ms-(T*sec-1),duration:T*sec,end:ms});
    }

    Milis.sort((a,b) => {
        return a.start - b.start
    });

    let result = 0;
    let upperend =0;

    for(let i=0;i<Milis.length;i++){
        let p=0;
        if (upperend > Milis[i].end) {
            i++;
            continue;
        }
        if(upperend > Milis[i].start) {
            p = upperend - Milis[i].start;
        }

        for(p;p<Milis[i].duration;p++){
            window.start = Milis[i].start + p;
            window.end = window.start + 999 ;
            let count = 0;
            for(let j=i;j<Milis.length;j++){
                let start = Milis[j].start;
                let end = Milis[j].end;
                if(!(window.start > end || window.end <start)){
                    count ++;
                }
            }
            if(result<count){
                result = count;
            }
        }
        upperend = Milis[i].end;
    }
   // console.log(result);
    return result;
}

let map =  [
    "2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
];

// let map =  [
//     "2016-09-15 01:00:04.002 2.0s",
// "2016-09-15 01:00:07.000 2s"
// ]

solution(map);
let cacheQueue = [];
let MAX_LEN;
let time = 0;
function enQueue(el){
    if(cacheQueue.length<MAX_LEN){
        cacheQueue.push(el)
    }
}

function deQueue(i){
      cacheQueue.splice(i,1);
}

function LRU(el){
    let find = false;
    // 캐시안에 있으면
    //console.log(cacheQueue);
    for(let i=0;i<cacheQueue.length;i++){
        if(cacheQueue[i] === el){
            deQueue(i);
            enQueue(el);
            find = true;
            time+=1;
            break;
        }
    }
    if(!find){
        //캐시가 가득찬 상태면
        if(cacheQueue.length >= MAX_LEN){
            cacheQueue.splice(0,1);
            enQueue(el)
        }else{
            enQueue(el)
        }
        time+=5;
    }
    // 캐시안에 없으면
}


function solution(cacheSize, cities) {
    MAX_LEN = cacheSize;
    for(let i=0;i<cities.length;i++){
        LRU(cities[i].toLowerCase())
    }
    //console.log(time);
    return time;
}

let arr = ["Jeju", "Pangyo", "NewYork", "newyork"]
solution(2,arr);
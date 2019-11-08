function solution(lines) {
  let sec = 1000;
  let min = sec*60;
  let hour = min*60;


  function MAX(a,b){
    if(a>b){
      return a;
    }
    return b;
  }

  function timeToNum(line){
    let times = line.split(" ");
    let time = times[1];
    let duration = times[2];
    time = time.split(":");

    let end = time[0]*hour + time[1]*min + parseInt(parseFloat(time[2])*1000);
    let start = end - (parseInt(parseFloat(duration.substring(0,duration.length-1)*1000))-1);
    return {start,end};
  }

  let times = [];
  for(let i=0;i<lines.length;i++){
    times.push(timeToNum(lines[i]));
  }

  times.sort((a,b) => {
    return a.start - b.start;
  });


  let result = 0;
  let upperEnd = 0;
  for(let k=0;k<times.length;k++){

    let p = upperEnd;
    if(upperEnd > times[k].end){
      k++;
      continue;
    }

    if(upperEnd < times[k].start){
      p = times[k].start;
    }

    for(p;p<=times[k].end;p++){
      let temp =0;
      let windowLeft = p;
      let windowRight = p+999;

      for(let t=k;t<times.length;t++){
        if( !((windowLeft > times[t].end) || windowRight < times[t].start)){
          temp ++;
        }
      }
      result = MAX(result, temp);
    }

    upperEnd = times[k].end;
  }
  console.log(result);
  return result;
}
solution(	["2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s"])
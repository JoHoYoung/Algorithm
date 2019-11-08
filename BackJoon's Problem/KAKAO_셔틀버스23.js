function solution(n, t, m, timetable) {
  let M = 1;
  let H = M*60;

  function getBus(){
    let arr =[];
    let start = 9*H;
    for(let i=0;i<n;i++){
      arr.push({start : start + (i)*t,users:[], num:0});
    }
    return arr;
  }
  let BUS = getBus();
  function sToTime(str){
    let times = str.split(':');
    return parseInt(times[0])*H + parseInt(times[1])*M;
  }
  timetable = timetable.map((el) => sToTime(el));
  timetable.sort((a,b) => a-b);

  let pivot = 0;

  for(let i=0;i<timetable.length;i++){
    if(pivot >= BUS.length){
      break;
    }
    if(BUS[pivot].start<timetable[i] || BUS[pivot].num >= m){
      pivot++;
      i--
    }else{
      BUS[pivot].users.push(timetable[i]);
      BUS[pivot].num++;
    }
  }

  let target = BUS[BUS.length-1];

  //console.log(target);
  let time;
  if(target.num === m){
    time = target.users[target.users.length-1]-1;
  }else{
    time = target.start;
  }

  if(parseInt(time/60) < 10){
    H = `0${parseInt(time/60)}`
  }else{
    H = parseInt(time/60).toString()
  }

  if(time%60 < 10){
    M = `0${time%60}`
  }else{
    M = (time%60).toString()
  }
  return `${H}:${M}`;
}

console.log(solution(2, 10, 2, ["09:10", "09:09", "08:00"]));
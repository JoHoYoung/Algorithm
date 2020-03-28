function solution(k, room_number) {

  let p2 = {};

  function parent2(idx){
    if(!p2[idx]) {
      p2[idx] = idx;
    }
    if(p2[idx] === idx) return idx;
    return p2[idx] = parent2(p2[idx]);
  }

  let re = [];
  for(let i=0;i<room_number.length;i++){
    let rn = parent2(room_number[i].toString());
    re.push(rn);
    p2[rn.toString()] = parent2((parseInt(rn)+1).toString());
  }
  re = re.map(el => parseInt(el));
  return re;
}
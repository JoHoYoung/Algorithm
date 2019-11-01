//40분 문자열압
let arr = [];


function sCompare(pivot, s, startIdx, depth) {
  let len = pivot.length;
  if(startIdx + len > s.length){
    if(depth !== 1){
      arr.push(`${depth}${pivot}`)
    }else {
      arr.push(`${pivot}`);
    }
    arr.push(s.substring(startIdx,s.length));
    return;
  }
축
  if (s.substring(startIdx, startIdx+len) === pivot) {
    sCompare(pivot, s, startIdx + len,depth+1);
  } else {
    // end
    if(depth !== 1){
      arr.push(`${depth}${pivot}`)
    }else {
      arr.push(`${pivot}`);
    }
    sCompare(s.substring(startIdx,startIdx+len), s, startIdx + len,1);
  }
}

function solution(s) {
  let pivot = parseInt(s.length/2);
  let len = 1;
  let slen = s.length;
  let result = 1000000;
  while(len <= s.length){
    sCompare(s.substring(0,len),s,len,1);
    result = result > arr.join('').length ? arr.join('').length : result;
    // console.log(arr);
    arr = [];
    len += 1;
  }
  return result;
}

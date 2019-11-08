//중복가능
function resetStr(str){
  let arr = [];
  for(let i=1;i<str.length;i++){
    let left = str[i-1].toLowerCase();
    let now = str[i].toLowerCase();
    if(now>'z' || now<'a'){
      i++;
      continue;
    }
    if(left >'z' || left<'a'){
      continue;
    }
    arr.push(left+now)
  }
 // console.log(arr)
  return arr;
}

function solution(str1, str2) {

  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();

  if(str1 === str2){
    return 65536;
  }

  let a = resetStr(str1);
  let b = resetStr(str2);
 // console.log(a,b);
  let sum = a.length + b.length;

  let U = 0;
  for(let i=0;i<a.length;i++){
    let A = a[i];
    let find = false;
    for(let j=0;j<b.length;j++){
      let B = b[j];
      if(A===B){
        find = true;
        b.splice(j,1);
        break;
      }
    }
    if(find){
      U++;
      a.splice(i,1);
      i--;
    }
  }
  return parseInt((U/(sum-U))*65536);
}
//console.log(solution("handshake", "shake hands"));
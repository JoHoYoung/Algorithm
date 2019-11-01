//1 균형잡힌 문자열로 분리.

function reverse(s){
  let result = "";
  for(let i=0;i<s.length;i++){
    if(s[i] === '('){
      result += ')'
    }else{
      result += '(';
    }
  }
  return result;
}

function myfunc(s){
  let UV = getUV(s);
  let U = UV[0];
  let V = UV[1];

  //console.log(UV);

  if(s === ''){
    return '';
  }

  if(isOK(U)){
    return `${U}${myfunc(V)}`
  }else{
    return `(${myfunc(V)})${reverse(U.substring(1,U.length-1))}`;
  }

}

function getUV(arr){

  if(arr.length === 0){
    return ['',''];
  }
  let pivot;
  if(arr[0] === '('){
    pivot = -1;
  }else{
    pivot = 1
  }

  for(let i=1;i<arr.length;i++){
    if(arr[i] === '('){
      pivot += -1;
    }else{
      pivot += 1;
    }
    if(pivot === 0){
      return [arr.substring(0,i+1), arr.substring(i+1,arr.length)];
    }
  }
}

function pop(arr){
  if(arr.length === 0){
    return '-';
  }
  let result = arr[arr.length-1];
  arr.splice(arr.length-1,1);
  return result;
}
// 오른쪽은 앞에 왼
function isOK(arr) {
  let stack = [];

  if(arr[0] !== '('){
    return false;
  }

  for(let i=0;i<arr.length;i++){
    if(arr[i] === '('){
      stack.push(arr[i]);
    }else if(arr[i] === ')'){
      if(pop(stack) === '-'){
        return false;
      }
    }
  }
  if(stack.length === 0){
    return true;
  }
}


function solution(p) {
  return myfunc(p);
}

solution("()))((()");
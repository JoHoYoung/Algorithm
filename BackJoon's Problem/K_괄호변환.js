function solution(p) {
  function getUV(s){
    let count = 0;
    let i;
    for(i=0;i<s.length;i++){
      if(s[i] === ')'){
        count++;
      }else{
        count --;
      }

      if(i!==0 && count === 0){
        break;
      }
    }
    return [s.substring(0,i+1),s.substring(i+1,s.length)]
  }

  function isCorrect(s){
    if(s[0] !== '(')
      return false;

    let count = 0;
    for(let i=0;i<s.length;i++){
      if(s[i] === '('){
        count ++;
      }else{
        count--;
      }
      if(count <0){
        return false;
      }
    }
    return true;
  }
  function reverse(s){
    let result = "";
    for(let i=0;i<s.length;i++){
      if(s[i] === '('){
        result += ')'
      }else{
        result += '('
      }
    }
    return result;
  }

  function work(s){
    if(s === ""){
      return "";
    }
    let data = getUV(s);
    let U= data[0];
    let V = data[1];

    if(isCorrect(U)){
      return `${U}${work(V)}`
    }else{
      return `(${work(V)})${reverse(U.substring(1,U.length-1))}`
    }
  }
  return work(p);
}
//console.log(solution("(()())()"));
function solution(p) {

  // 균형잡힌 문자열
  if(p.length === 0) return "";
  function getUV(s){
    let l =0;
    let r = 0;
    for(let i=0;i<s.length;i++){
      if(s[i] === '(') l++;
      else r++;

      if(l === r) return [s.substring(0, i+1), s.substring(i+1,s.length)];
    }
  }

  function isCorrect(s){
    let l =0;
    let r = 0;
    for(let i=0;i<s.length;i++){
      if(s[i] === '(') l++;
      else r++;
      if(r > l) return false;
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

  function sol(s){
    //console.log(s);
    if(s.length ===0) return "";
    let UVS = getUV(s);
    //console.log(UVS);
    let U = UVS[0];
    let V = UVS[1];
    if(isCorrect(U)){
      return U + sol(V);
    }else{
     // console.log("GO");
      let s = '(';
      s += sol(V);
      s += ')';
      U = U.substring(1, U.length-1);
     // console.log(U);
      U = reverse(U);
      s += U;
      return s;
    }
  }
  return sol(p);
}

console.log(solution("()))((()"));
//console.log(solution(")("));

function solution(s) {

  function min(a,b){
    if(a>b){
      return b;
    }
    return a;
  }
  // 단위;;
  let M = s.length;
  for(let t=1;t<=s.length/2;t++){
    let upper = s.substring(0,t);
    let depth = 1;
    let result = [];
    for(let i=t;i<s.length;i+=t){

      if(i+t>s.length){
        if(depth === 1){
          result.push(upper);
        }else{
          result.push(`${depth}${upper}`)
        }
        result.push(s.substring(i,s.length));
      }else{
        let now = s.substring(i,i+t);
        if(i+t === s.length){
          if(upper === now){
            result.push(`${depth+1}${upper}`)
          }else{
            if(depth === 1){
              result.push(upper);
            }else{
              result.push(`${depth+1}${upper}`)
            }
            result.push(now);
          }
        }else if(now !== upper){
          if(depth === 1){
            result.push(upper);
          }else{
            result.push(`${depth}${upper}`)
          }
          depth = 1;
        }else{
          depth ++;
        }
        upper = now;
      }
    }
    //console.log(result);
    M = min(M,result.join("").length);
  }

  return M;
}



solution("ababcdcdababcdcd");
//solution("aabbaccc")
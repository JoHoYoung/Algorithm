function solution(words, queries) {

  let tries = {count :0};
  let reveresTries = {count : 0};

  let reversWords  =[];

  for(let i=0;i<words.length;i++){
    reversWords.push(words[i].split("").reverse().join(""));
  }

  function buildTries(T,data){
    for(let i=0;i<data.length;i++){
      if(!T[data[i].length]){
        T[data[i].length] = {count :0}
      }
      let node = T[data[i].length];
      for(let j=0;j<data[i].length;j++){
        let C = data[i][j];
        node.count += 1;
        if(!node[C]){
          node[C] = {count:0}
        }
        node = node[C];
      }
    }
  }
  buildTries(tries,words);
  buildTries(reveresTries,reversWords);

  function travels(T,str,num){
    let node = T[num];
    if(!node){
      return 0;
    }
    for(let i=0;i<str.length;i++){
      if(node[str[i]]){
        node = node[str[i]];
      }else{
        return 0;
      }
    }
    return node.count;
  }

  let result = [];
  for(let i=0;i<queries.length;i++){
    let isreverse = false;
    if(queries[i][0] === "?"){
      isreverse = true;
      queries[i] = queries[i].split("").reverse().join("");
    }

    let num = queries[i].length;
    let target = (queries[i].split("?"))[0];

    if(isreverse){
      result.push(travels(reveresTries,target,num));
    }else{
      result.push(travels(tries,target,num));
    }

  }
  return result;
}
//solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],["fro??", "????o", "fr???", "fro???", "pro?"]);

function solution(words) {
  let tries = {
    count:0
  };

  function buildTrie(word){
    let upper = tries;
    tries.count++;
    for(let i=0;i<word.length;i++){
      let C = word[i];
      if(!upper[C]){
        upper[C] = {count:1};
      }else{
        upper[C].count++;
      }
      upper = upper[C];
    }
  }

  function travels(word){
    let node = tries;
    let depth = 0;
    for(let i=0;i<word.length;i++){
      if(node[word[i]].count === 1){
        depth++;
        break;
      }else{
        depth++;
        node = node[word[i]];
      }
    }
    return depth;
  }

  for(let i=0;i<words.length;i++){
    buildTrie(words[i]);
  }
  let count = 0;
  for(let i=0;i<words.length;i++){
    count += travels(words[i]);
   // console.log(travels(words[i]))
  }
 // console.log(tries);
  return count;
}
solution(["go", "gone", "guild"]);
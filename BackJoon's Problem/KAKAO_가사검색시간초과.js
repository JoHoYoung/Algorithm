function solution(words, queries) {
  let answer = [];

  for(let i=0;i<queries.length;i++){
    let reverse = false;
    if(queries[i][0] === '?'){
      reverse = true;
      queries[i] = queries[i].split('').reverse().join("");
    }

    let qa = queries[i].split('?');
    let q = qa[0];

    let remainNum = qa.length-1;
    let count = 0;

    //console.log(qa);
    for(let j=0;j<words.length;j++){
      let word = words[j];

      if(reverse){
        word = word.split('').reverse().join("");
      }

      if(word.indexOf(q) === 0 && word.length - q.length === remainNum){
        count++;
      }
    }
    answer.push(count)
  }
  //console.log(answer);
  return answer;
}
solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]);
let tries = {};
let reversetries = {}
function buildtrie(words) {

  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    let len = word.length;

    if (!tries[len]) {
      tries[len] = {count:0};
    }

    let pivottrie = tries[len];
    pivottrie.count+=1;

    for (let j = 0; j < word.length; j++) {
      let char = word[j];
      if (!pivottrie[char]) {
        pivottrie[char] = {count:0};
      }

      pivottrie = pivottrie[char];
      pivottrie.count+=1;

    }
  }
}


function buildReverestrie(words) {

  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    let len = word.length;

    if (!reversetries[len]) {
      reversetries[len] = {count:0};
    }

    let pivottrie = reversetries[len];
    pivottrie.count+=1;

    for (let j = 0; j < word.length; j++) {
      let char = word[j];
      if (!pivottrie[char]) {
        pivottrie[char] = {count:0};
      }
      pivottrie = pivottrie[char];
      pivottrie.count+=1;
    }
  }
}


function travels(q, len) {

  let node = tries[len.toString()];
  let idx = 0;

  if(!node){
    return 0;
  }

  if(q === ''){
    return node.count;
  }

  while (node) {
   node = node[q[idx++]];
    if (idx === q.length) {
      if(!node){
        return 0;
      }
      return node.count;
    }
  }
  return 0;
}

function reverestravels(q, len) {

  let node = reversetries[len.toString()];
  let idx = 0;
  if(!node){
    return 0;
  }

  if(q === ''){
    return node.count;
  }
  while (node) {
    node = node[q[idx++]];
    if (idx === q.length) {
      if(!node){
        return 0;
      }
      return node.count;
    }
  }
  return 0;
}


function solution(words, queries) {
  let answer = [];
  let rev = words.map(el => el.split("").reverse().join(""));

  buildtrie(words);
  buildReverestrie(rev);

  for (let i = 0; i < queries.length; i++) {
    let reverse = false;
    if (queries[i][0] === '?') {
      reverse = true;
      queries[i] = queries[i].split('').reverse().join("");
    }

    let qa = queries[i].split('?');
    let q = qa[0];

    if(reverse){
      answer.push(reverestravels(q, queries[i].length));
    }else{
      answer.push(travels(q, queries[i].length));
    }

  }
  return answer;
}

solution(["dsa","frodo", "front", "frost", "frozen", "frame", "kakao"], ["??a"]);
function solution(user_id, banned_id) {
  let trie = {count: 0};

  function buildTrie(str) {
    let node = trie[str.length];
    node.count += 1;
    for (let i = 0; i < str.length; i++) {
      if (!node[str[i]]) {
        node[str[i]] = {count: 1};
      } else {
        node[str[i]].count++;
      }
      node = node[str[i]];
    }
  }

  for (let i = 0; i < user_id.length; i++) {
    if (!trie[user_id[i].length]) {
      trie[user_id[i].length] = {count: 1};
    }
    buildTrie(user_id[i]);
  }
  /**
   * @return {number}
   */
  let re = [];
  for (let i = 0; i < banned_id.length; i++) re.push([]);

  function DFS(tries, target, depth, trace, idx) {
    if (depth === target.length) {
      re[idx].push(trace);
    }
    let cur = target[depth];

    if (cur === '*') {
      for (let key in tries) {
        if (key === "count") continue;
        let nTries = tries[key];
        DFS(nTries, target, depth + 1, trace + key, idx);
      }
    } else {
      let nTrie = tries[cur];
      if (nTrie) {
        DFS(nTrie, target, depth + 1, trace + cur, idx);
      }
    }
  }


  for (let i = 0; i < banned_id.length; i++) DFS(trie[banned_id[i].length], banned_id[i], 0, "", i);

  let comb = [];
  function com(depth, ar) {
    if (depth === re.length) {
      comb.push(ar);
      return;
    }
    for (let i = 0; i < re[depth].length; i++) {
      let arr = ar.slice();
      if(ar.indexOf(re[depth][i]) !== -1) continue;
      arr.push(re[depth][i]);
      com(depth + 1, arr);
    }
  }
  com(0, []);
  let ans = new Set();
  for(let i=0;i<comb.length;i++){
    comb[i].sort();
    ans.add(comb[i].join(''));
  }
  return ans.size;
}

//solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"]);
function solution(words, queries) {

  const node = () => {
    return {
      cnt: 0,
      leaves: {},
      end: false,
    }
  };

  let root = node();
  let reverseRoot = node();

  function buildTrie(root, idx, s) {
    if (!root[s.length]) root[s.length] = node();
    let now = root[s.length];
    for (let i = 0; i < s.length; i++) {
      now.cnt++;
      if (!now.leaves[s[i]]) now.leaves[s[i]] = node();
      now = now.leaves[s[i]];
    }
    now.end = true;
  }

  let reverseWords = words.map(el => el.split("").reverse().join(""));

  for (let i = 0; i < words.length; i++) buildTrie(root, 0, words[i]);
  for (let i = 0; i < words.length; i++) buildTrie(reverseRoot, 0, reverseWords[i]);

  //console.log(reverseRoot)
  function travel(now, s, idx) {
    if (!now) return 0;
    //console.log(s,idx);
    let re = 0;
    let curC = s[idx];

    if (idx === s.length) {
      if (now.end) return 1;
      return 0;
    }

    if (curC === '?') {
      re += now.cnt;
    } else {
      let leaf = now.leaves[s[idx]];
      if (leaf) {
        re += travel(leaf, s, idx + 1);
      }
    }
    return re;
  }

  let ans = [];
  for (let i = 0; i < queries.length; i++) {
    if (queries[i][0] === '?') ans.push(travel(reverseRoot[queries[i].length], queries[i].split("").reverse().join(""), 0));
    else ans.push(travel(root[queries[i].length], queries[i], 0));
  }

  //console.log(ans);
  return ans;
}


solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]);
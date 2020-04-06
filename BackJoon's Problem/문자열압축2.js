function solution(s) {

  let pivot = "";
  // copare length
  const min = (a, b) => a > b ? b : a;
  let ans = 987654321;

  for (let l = 1; l <= s.length; l++) {

    let arr = [];
    for (let i = 0; i < s.length; i += l) arr.push(s.substring(i, i + l));
    let pivot = arr[0];
    let cnt = 1;
    let re = "";
    for (let i = 1; i < arr.length; i++) {

      let target = arr[i];
      if (pivot === target) {
        cnt++;
        continue;
      } else {
        if (cnt !== 1) re += `${cnt}${pivot}`;
        else re += pivot;
        cnt = 1;
        pivot = target;
      }
    }
    if (cnt !== 1) re += `${cnt}${pivot}`;
    else re += pivot;

    ans = min(ans, re.length);
 //   console.log(re);
 //   console.log(arr);
  }

  return ans;
}

//solution("aabbaccc");

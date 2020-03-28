function solution(s) {

  s = s.substring(1, s.length - 1);
  let arr = s.split("},");
  arr = arr.map(el => {
    return el.substring(1, el.length)
  });
  arr[arr.length - 1] = arr[arr.length - 1].substring(0, arr[arr.length - 1].length - 1)
  arr = arr.map(el => el.split(','));
  arr.sort((a, b) => {
    return b.length - a.length;
  });

  let re = [];
  let tmp = [];
  for(let i=0;i<100001;i++) tmp.push(0);
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr[i].length; j++) {
      let no = parseInt(arr[i][j]);
      tmp[no]++;
    }
  }
  for(let i=0;i<100001;i++) {
    if(tmp[i] === 0 ) continue;
    re.push({idx : i,no : tmp[i]});
  }
  re.sort((a,b) => {
    return b.no - a.no;
  });
 let ans = [];
  for(let i=0;i<re.length;i++){
    ans.push(re[i].idx);
  }
//  console.log(ans);
  return ans;
}

solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
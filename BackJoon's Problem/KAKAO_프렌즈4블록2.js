function getAllCombinations(arr, m) {
  const combinations = [];
  const picked = [];
  const used = [];
  for (item of arr) used.push(0);

  function find(picked) {
    if (picked.length === m) {
      const rst = [];
      for (let i of picked) {
        rst.push(arr[i]);
      }
      combinations.push(rst);
      return;
    } else {
      let start = picked.length ? picked[picked.length - 1] + 1 : 0;
      for (let i = start; i < arr.length; i++) {
        if (i === 0 || arr[i] !== arr[i - 1] || used[i - 1]) {
          picked.push(i);
          used[i] = 1;
          find(picked);
          picked.pop();
          used[i] = 0;
        }
      }
    }
  }
  find(picked);
  return combinations;
}

function solution(m, n, board) {

  function getMap(){
    let map = [];
    for(let j=board[0].length-1;j>=0;j--){
      let arr = [];
      for(let i=0;i<board.length;i++){
        arr.push(board[i][j])
      }
      map.push(arr);
    }
    return map;
  }

  let map = getMap();
  let pivot = map[0].length;

  function arrange(){
    for(let i=0;i<map.length;i++){
      let target = map[i];
      target = target.filter(el => el !== '*');
      for(let j = target.length;j<pivot;j++){
        target.unshift('*');
      }
      map[i] =target;
    }
  }
  let count = 0;
  while(1){

    let find = false;
    let todel = [];
    for(let i=0;i<map.length-1;i++){
      for(let j=0;j<map[0].length-1;j++){
        let key = map[i][j];
        if(key === '*') {
          continue;
        }
        if(key === map[i+1][j] && key === map[i+1][j+1] && key === map[i][j+1]){
          find = true;
          todel.push([i,j]);
          todel.push([i+1,j]);
          todel.push([i+1,j+1]);
          todel.push([i,j+1]);
        }
      }
    }
    if(!find){
      break;
    }
    for(let i=0;i<todel.length;i++){
      map[todel[i][0]][todel[i][1]] = '*';
    }
    arrange();
  }
  for(let i=0;i<map.length;i++){
    for(let j=0;j<map[0].length;j++){
      if(map[i][j] === '*'){
        count++;
      }
    }
  }
  return count;
}
solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]);
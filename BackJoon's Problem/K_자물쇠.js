function solution(key, lock) {

  function getEmptyKey() {
    let arr = [];
    for (let i = 0; i < key.length; i++) {
      let temp = [];
      for (let j = 0; j < key[0].length; j++) {
        temp.push(0);
      }
      arr.push(temp);
    }
    return arr;
  }

  let Keys = [key];
  for (let i = 0; i < 3; i++) {
    Keys.push(getEmptyKey());
  }


  let up=lock.length, down= 0, left =lock.length, right =0;

  function max(a,b){
    if(a>b){
      return a;
    }
    return b;
  }

  function min(a,b){
    if(a>b){
      return b;
    }
    return a;
  }

  for (let i = 0; i < lock.length; i++) {
    for (let j = 0; j < lock[0].length; j++) {
      if (lock[i][j] === 0) {
        up = min(up,i);
        down = max(down,i);

        left = min(left,j);
        right = max(right,j);
      }
    }
  }

  let width = right - left +1;
  let height = down - up +1;

  if (width > key.length || height > key.length) {
    return false;
  }

  for (let t = 1; t < 4; t++) {
    let K = Keys[t];
    if (t === 1) {
      for (let i = 0; i < K.length; i++) {
        for (let j = 0; j < K[0].length; j++) {
          K[j][K.length - 1 - i] = key[i][j]
        }
      }
    } else if (t === 2) {
      for (let i = 0; i < K.length; i++) {
        for (let j = 0; j < K[0].length; j++) {
          K[K.length - 1 - i][K.length - 1 - j] = key[i][j]
        }
      }
    } else if (t === 3) {
      for (let i = 0; i < K.length; i++) {
        for (let j = 0; j < K[0].length; j++) {
          K[K.length - 1 - j][i] = key[i][j]
        }
      }
    }
  }

  let verticalMin = left - (key.length - width);
  let verticalMax = left;


  let hortizonMin = up - (key.length - height);
  let horizonMax = up;

  console.log(up,down,left,right)
  //console.log(verticalMin,verticalMax,hortizonMin,horizonMax);

  function Do(KEY) {
    for(let hori = hortizonMin;hori<=horizonMax;hori++){
      for(let verti = verticalMin;verti<=verticalMax;verti++){
        let find = true;
        for(let i=0;i<lock.length;i++){
          for(let j=0;j<lock.length;j++){
            let val;
            if(i - hori < 0 || i - hori >= key.length || j-verti <0 || j-verti >= key.length){
              val = 0;
            }else{
              val = KEY[i -hori][j - verti];
            }

            if(val + lock[i][j] !== 1){
              find = false;
              break;
            }
          }
        }
        if(find){
          return true;
        }
      }
    }
    return false;
  }

  for(let i=0;i<Keys.length;i++){
    if(Do(Keys[i])){
      return true;
    }
  }
  return false;
}

// console.log(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],
//   [ [1, 1, 1, 1, 1],
//     [1, 1, 1, 1, 1],
//     [1, 1, 1, 0, 1],
//     [1, 1, 1, 1, 0],
//     [1, 1, 1, 0, 1]
//   ]));
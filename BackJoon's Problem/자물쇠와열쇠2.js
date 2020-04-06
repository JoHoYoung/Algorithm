function solution(key, lock) {

  let M = key.length - 1;
  let blankNo = 0;
  for (let i = 0; i < lock.length; i++) {
    for (let j = 0; j < lock.length; j++) {
      if (lock[i][j] === 0) blankNo++;
    }
  }
  //console.log(blankNo)

  function rot(mode) {
    let arr = [];
    for (let i = 0; i < key.length; i++) {
      let a = [];
      for (let j = 0; j < key.length; j++) {
        a.push(0);
      }
      arr.push(a);
    }

    if (mode === 1) {
      for (let i = 0; i < key.length; i++) {
        for (let j = 0; j < key.length; j++) {
          arr[j][M - i] = key[i][j]
        }
      }
    } else if (mode === 2) {
      for (let i = 0; i < key.length; i++) {
        for (let j = 0; j < key.length; j++) {
          arr[M - i][M - j] = key[i][j]
        }
      }
    } else if (mode === 3) {
      for (let i = 0; i < key.length; i++) {
        for (let j = 0; j < key.length; j++) {
          arr[M - j][i] = key[i][j]
        }
      }
    }
    return arr;
  }

  let keys = [key];
  for (let i = 1; i <= 3; i++) {
    keys.push(rot(i));
  }

//  console.log(keys);
  for (let k = 0; k < 4; k++) {
    let targetKey = keys[k];
    for (let leftpivot = -lock.length-1; leftpivot <= lock.length+1; leftpivot++) {
      for (let uppivot = -lock.length-1; uppivot <= lock.length+1; uppivot++) {
    // for (let leftpivot = -1; leftpivot <= -1; leftpivot++) {
    //   for (let uppivot = -1; uppivot <= -1; uppivot++) {
        let cnt = 0;
        let CONT = true;
        for (let i = 0; i < lock.length; i++) {
          for (let j = 0; j < lock.length; j++) {
            let keyI = i + uppivot;
            let keyJ = j + leftpivot;
            if (keyI < 0 || keyI > key.length - 1 || keyJ < 0 || keyJ > key.length - 1) continue;
            if (targetKey[keyI][keyJ] === lock[i][j]) {
              cnt = 0;
              CONT = false;
              break;
            }
            if(targetKey[keyI][keyJ] === 1 && lock[i][j] === 0) cnt++;
          }
          if(!CONT){
            cnt = 0;
            break;
          }
        }
      //  console.log(cnt);
        if(cnt === blankNo && CONT) return true;
      }
    }
  }
  return false;
}

console.log(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]));
// 90도, 180도, 270도.
// 오른, 아래, 왼쪽, 오른

function rot(i, j, last, mode) {
  if (mode === 0) {
    return [last - j, i];
  }

  if (mode === 1) {
    return [last - i, last - j];
  }

  if (mode === 2) {
    return [j, last - i];
  }

  if(mode === 3){
    return [i,j];
  }
}

function transpos(i, j, hor, vert) {
  return [i + vert, j + hor];
}

function getPos(i, j, last, mode, hor, vert) {
  let transPos = transpos(i, j, hor, vert);
  let rotPos = rot(transPos[0],transPos[1],last,mode);
  return rotPos;
}

function solution(key, lock) {
  let dif = lock.length - key.length;
  for (let i = 0; i < key.length; i++) {
    for (let j = 0; j < dif; j++) {
      key[i].push(0);
    }
  }
  for (let i = 0; i < dif; i++) {
    let arr = [];
    for (let j = 0; j < lock.length; j++) {
      arr.push(0);
    }
    key.push(arr);
  }

  for(let Mode = 0;Mode<=3;Mode++){
    for(let hor = lock.length;hor>=-lock.length;hor--){
      for(let vert = lock.length;vert>=-lock.length;vert--){

        let find = true;
        for(let i=0;i<lock.length;i++){

          for(let j=0;j<lock.length;j++){
            let val = 0;
            let pos = getPos(i,j,lock.length-1,Mode,hor,vert);

            if(pos[0] < 0 || pos[0]>=lock.length){
              val = 0;
            }else if(pos[1]<0 || pos[1]>=lock.length){
              val = 0;
            }else{
              val = key[pos[0]][pos[1]];
            }

            if(lock[i][j] + val !== 1){
              find = false;
              break;
            }
          }
          if(!find){
            break;
          }

        }

        if(find){
          return true;
        }

      }
    }
  }
  return false;
}

//solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],[[1, 1, 1], [1, 1, 0], [1, 0, 1]]);
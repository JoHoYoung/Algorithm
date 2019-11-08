// 기둥설치 : 바닥 OR 보 위, 다른 기둥 위
// 보 설치 : 한쪽끝이 기둥 OR 양쪽 다 보

// 기둥 : 위로
// 보 : 오른쪽으로
// 기둥은 j만
// 보는 i만

let C = [];
let B = [];
let N;

function isCorrectC(i, j) {

  if (i === 0) {
    return true;
  }

  if (B[i][j - 1] || B[i][j]) {
    return true;
  }

  if (C[i - 1][j]) {
    return true;
  }
  return false;
}


function isCorrectB(i, j) {
  //console.log(i);
  if (C[i - 1][j] || C[i - 1][j + 1]) {
    return true;
  }

  if (B[i][j - 1] && B[i][j + 1]) {
    return true;
  }
  return false;
}

function insertC(i, j) {
  C[i][j] = true;
}

function insertB(i, j) {
  B[i][j] = true;
}

function deleteC(i, j) {
  C[i][j] = false;
}

function deleteB(i, j) {
  B[i][j] = false;
}

function canInsertC(i, j) {

  if (i === 0) {
    insertC(i, j);
    return true;
  }

  if (C[i - 1][j] || B[i][j - 1] || B[i][j]) {
    insertC(i, j);
    return true;
  }
  return false;
}

function canInsertB(i, j) {

  if (B[i][j - 1] && B[i][j + 1]) {
    insertB(i, j);
    return true;
  }

  if (C[i - 1][j] || C[i - 1][j + 1]) {
    insertB(i, j);
    return true;
  }

  return false;
}

function treverseL(i, j) {
  while (B[i][j] && j >= 0) {
    if (C[i - 1][j]) {
      return true;
    }
    j--;
  }
  return false;
}

function treverseR(i, j) {
  while (B[i][j] && j < N) {
    if (C[i - 1][j + 1]) {
      return true;
    }
    j++
  }
  return false;
}

function canDeleteC(i, j) {

  if (B[i + 1][j] && B[i + 1][j - 1]) {
    if (!treverseL(i + 1, j - 1) || !treverseR(i + 1, j)) {
      return false;
    }
  } else if (B[i + 1][j]) {
    if (!C[i][j + 1]) {
      return false;
    }
  } else if (B[i + 1][j - 1]) {
    if (!C[i][j - 1]) {
      return false;
    }
  } else if (C[i + 1][j]) {
    return false;
  }
  // 위에 아무것도 없는경우
  deleteC(i, j);
  return true;
}

// 보를 삭제하는 경우.
// 위에 기둥있으면 불가.
//
function canDeleteB(i, j) {

  if (B[i][j - 1] && B[i][j + 1]) {
    if ((!C[i - 1][j + 2] && !C[i - 1][j + 1]) || (!C[i - 1][j - 1] && !C[i - 1][j])) {
      return false;
    }
  } else if (B[i][j + 1]) {
    if (!C[i - 1][j + 2] && !C[i - 1][j + 1]) {
      return false;
    }
  } else if (B[i][j - 1]) {
    if (!C[i - 1][j - 1] && !C[i - 1][j]) {
      return false;
    }
  } else if (C[i][j] && C[i][j + 1]) {
    if (!C[i - 1][j] || !C[i - 1][j + 1]) {
      return false;
    }
  } else if (C[i][j + 1]) {
    if (!C[i - 1][j + 1]) {
      return false;
    }
  } else if (C[i][j]) {
    if (!C[i - 1][j]) {
      return false;
    }
  }

  // else if(C[i][j] && C[i][j+1]){
  //   if(!C[i-1][j] || !C[i-1][j+1] ){
  //     return false;
  //   }
  // } else if (C[i][j] && !C[i - 1][j]) {
  //   return false;
  // }else if (C[i][j + 1] && !C[i - 1][j + 1]) {
  //   return false;
  // }
  deleteB(i, j);
  return true;
}

function Action(msg) {
  //console.log(msg);
  let j = msg[0];
  let i = msg[1];
  let type = msg[2];
  let action = msg[3];

  if (action === 1) { //insert
    if (type === 0) {
      canInsertC(i, j);
    } else {
      canInsertB(i, j);
    }
  } else { // delete
    if (type === 0) {
      C[i][j] = false;
      let flag = true;
      for (let I = 0; I <= N; I++) {
        for (let J = 0; J <= N; J++) {
          if (C[I][J]){
            if(!isCorrectC(I,J)){
              flag = false;
              break;
            }
          }

          if (B[I][J]){
            if(!isCorrectB(I,J)){
              flag = false;
              break;
            }
          }
        }
        if (!flag) {
          C[i][j] = true;
          break;
        }
      }
    } else {
      B[i][j] = false;
      let flag = true;
      for (let I = 0; I <= N; I++) {
        for (let J = 0; J <= N; J++) {
          if (C[I][J]){
            if(!isCorrectC(I,J)){
              flag = false;
              break;
            }
          }
          if (B[I][J]){
            if(!isCorrectB(I,J)){
              flag = false;
              break;
            }
          }
        }
        if (!flag) {
          B[i][j] = true;
          break;
        }
      }
    }
  }
}


function Result() {
  let result = [];
  for (let i = 0; i <= N; i++) {

    for (let j = 0; j <= N; j++) {
      if (C[i][j]) {
        result.push([j, i, 0])
      }

      if (B[i][j]) {
        result.push([j, i, 1])
      }
    }
  }
  return result;
}

function solution(n, build_frame) {
  N = n;

  for (let i = 0; i <= n; i++) {
    let arr = [];
    let arr2 = [];
    for (let j = 0; j <= n; j++) {
      arr.push(false);
      arr2.push(false);
    }
    C.push(arr);
    B.push(arr2);
  }

  for (let i = 0; i < build_frame.length; i++) {
    Action(build_frame[i]);
  }

  let result = Result();
  result.sort((a, b) => {
    if (a[0] === b[0]) {
      if (a[1] === b[1]) {
        return a[2] - b[2];
      }
      return a[1] - b[1];
    }
    return a[0] - b[0];
  });
//  console.log(result);
  return result;
}

//0 기둥 1 보
//solution(500, [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]]);
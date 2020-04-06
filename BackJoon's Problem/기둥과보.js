function solution(n, build_frame) {

  // 기둥은 y가 증가하는 맵
  let CMap = [];
  let BMap = [];
  for (let i = 0; i <= n; i++) {
    let arr = [];
    let arr2 = [];
    for (let j = 0; j <= n; j++) {
      arr.push(false);
      arr2.push(false);
    }
    CMap.push(arr);
    BMap.push(arr2);
  }

  function canInsertC(x, y) {
    if (y === 0) return true;
    if (x === 0) {
      return CMap[y - 1][x] || BMap[y][x];
    } else if (x === n) {
      return CMap[y - 1][x] || BMap[y][x - 1];
    } else {
      return CMap[y - 1][x] || BMap[y][x - 1] || BMap[y][x];
    }
  }

  function canInsertB(x, y) {
    if (y === 0) return false;
    if (x === 0) {
      return CMap[y - 1][x] || CMap[y - 1][x + 1];
    }
    if (x === n - 1) {
      return CMap[y - 1][x] || CMap[y-1][x + 1]
    }
    return CMap[y - 1][x] || CMap[y - 1][x + 1] || (BMap[y][x - 1] && BMap[y][x + 1]);
  }

  function isCorrect() {
    for (let y = 0; y <= n; y++) {
      for (let x = 0; x <= n; x++) {
        if (CMap[y][x] && !canInsertC(x, y)) return false;
        if (BMap[y][x] && !canInsertB(x, y)) return false;
      }
    }
    return true;
  }

  for (let i = 0; i < build_frame.length; i++) {
    let x = build_frame[i][0];
    let y = build_frame[i][1];
    let a = build_frame[i][2];
    let b = build_frame[i][3];
    // 기둥
    if (a === 0) {
      //삭제
      if (b === 0) {
        CMap[y][x] = false;
        if (!isCorrect()) CMap[y][x] = true;
        //설치
      } else {
        if (canInsertC(x, y)) CMap[y][x] = true;
      }
      //보
    } else {
      //삭제
      if (b === 0) {
       BMap[y][x] = false;
       if (!isCorrect()) BMap[y][x] = true;
        //설치
      } else {
        if (canInsertB(x, y)) BMap[y][x] = true;
      }
    }
  }
  // console.log(BMap);
  // console.log(CMap);
  let re = [];
  for (let y = 0; y <= n; y++) {
    for (let x = 0; x <= n; x++) {
      if (CMap[y][x]) re.push([x, y, 0]);
      if (BMap[y][x]) re.push([x, y, 1]);
    }
  }
  re.sort((a, b) => {
    if (a[0] === b[0]) {
      if (a[1] === b[1]) {
        return a[2] - b[2];
      }
      return a[1] - b[1];
    }
    return a[0] - b[0];
  });

  console.log(re);
  return re;
}
solution(	5, [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]);

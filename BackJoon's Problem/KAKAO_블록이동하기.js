function solution(board) {

  let N = board.length;
  const LOC = (i, j, p, d) => {
    return {
      i, j, p, d
    };
  };

  let Di = [-1, 0, 1, 0];
  let Dj = [0, 1, 0, -1];

  let visited = [];
  for (let i = 0; i <= 1; i++) {
    let arr = [];
    for (let j = 0; j < 100; j++) {
      let a = [];
      for (let k = 0; k < 100; k++) {
        a.push(987654321);
      }
      arr.push(a);
    }
    visited.push(arr);
  }

  let Q = [];
  let ans = 987654321;

  Q.push(LOC(0, 0, 0, 0));
  while (Q.length > 0) {
    let cur = Q.shift();

    let curI = cur.i;
    let curJ = cur.j;
    let curP = cur.p;
    let curD = cur.d;
  //  console.log(curI,curJ,curP,curD);

    if ((curP === 0 && curI === N - 1 && curJ === N - 2) || (curP === 1 && curI === N - 2 && curJ === N - 1)) {
      if (ans > curD) {
        console.log(curD);
        ans = curD;
        continue;
      }
    }

    for (let d = 0; d < 4; d++) {
      let ni = curI + Di[d];
      let nj = curJ + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || board[ni][nj] === 1) continue;
      // 가로방향일때

      if (curP === 0 && ((nj + 1 < 0 || nj + 1 > N - 1) || board[ni][nj + 1] === 1)) continue;
      if (curP === 1 && ((ni + 1 < 0 || ni + 1 > N - 1) || board[ni + 1][nj] === 1)) continue;
      if (visited[curP][ni][nj] <= curD + 1) continue;
      visited[curP][ni][nj] = curD + 1;
      Q.push(LOC(ni, nj, curP, curD + 1));
    }

    // 자기를 회전시키는것
    // 회전시켜서 넣기
    if (curP === 0) {
      // 가로일경우 위로 돌리거나 아래로 돌리거나
      // 위로 돌리는 경우
      // 대각선과 위 검사
      let ui1 = curI - 1;
      let uj1 = curJ + 1;

      let ui2 = curI - 1;
      let uj2 = curJ;
      // 위로 돌릴 수 있으면
      // 돌리고 윗좌표가 큐로
      if (!(ui1 < 0 || ui1 > N - 1 || uj1 < 0 || uj1 > N - 1
        || ui2 < 0 || ui2 > N - 1 || uj2 < 0 || uj2 > N - 1 || board[ui1][uj1] === 1 || board[ui2][uj2] === 1)) {
        if (visited[1][ui2][uj2] > curD + 1) {
          visited[1][ui2][uj2] = curD + 1;
          Q.push(LOC(ui2, uj2, 1, curD + 1));
        }
      }
      // 아래로 돌리기
      // 아래로 돌리면 지금좌표가 큐로
      let di1 = curI + 1;
      let dj1 = curJ + 1;

      let di2 = curI + 1;
      let dj2 = curJ;
      if (!(di1 < 0 || di1 > N - 1 || dj1 < 0 || dj1 > N - 1
        || di2 < 0 || di2 > N - 1 || dj2 < 0 || dj2 > N - 1 || board[di1][dj1] === 1 || board[di2][dj2] === 1)) {
        if (visited[1][curI][curJ] > curD + 1) {
          visited[1][curI][curJ] = curD + 1;
          Q.push(LOC(curI, curJ, 1, curD + 1));
        }
      }
      // 세로방향은 가로로
    } else {
      // 오른쪽회전
      let ri1 = curI + 1;
      let rj1 = curJ + 1;

      let ri2 = curI;
      let rj2 = curJ + 1;

      if (!(ri1 < 0 || ri1 > N - 1 || rj1 < 0 || rj1 > N - 1
        || ri2 < 0 || ri2 > N - 1 || rj2 < 0 || rj2 > N - 1 || board[ri1][rj1] === 1 || board[ri2][rj2] === 1)) {
        if (visited[0][curI][curJ] > curD + 1) {
          visited[0][curI][curJ] = curD + 1;
          Q.push(LOC(curI, curJ, 0, curD + 1));
        }
      }

      let li1 = curI + 1;
      let lj1 = curJ - 1;

      let li2 = curI;
      let lj2 = curJ - 1;

      if (!(li1 < 0 || li1 > N - 1 || lj1 < 0 || lj1 > N - 1
        || li2 < 0 || li2 > N - 1 || lj2 < 0 || lj2 > N - 1
        || board[li1][lj1] === 1 || board[li2][lj2] === 1)) {
        if (visited[0][li2][lj2] > curD + 1) {
          visited[0][li2][lj2] = curD + 1;
          Q.push(LOC(li2, lj2, 0, curD + 1));
        }
      }
    }

    // 다른점을 회전
    if (curP === 0) {
      // 가로일경우 위로 돌리거나 아래로 돌리거나
      // 위로 돌리는 경우
      // 대각선과 위 검사
      let pI = curI;
      let pJ = curJ+1;

      let ui1 = pI - 1;
      let uj1 = pJ - 1;

      let ui2 = pI - 1;
      let uj2 = pJ;

      // 위로 돌릴 수 있으면
      // 돌리고 윗좌표가 큐로
      if (!(ui1 < 0 || ui1 > N - 1 || uj1 < 0 || uj1 > N - 1
        || ui2 < 0 || ui2 > N - 1 || uj2 < 0 || uj2 > N - 1 || board[ui1][uj1] === 1 || board[ui2][uj2] === 1)) {
        if (visited[1][ui2][uj2] > curD + 1) {
          visited[1][ui2][uj2] = curD + 1;
          Q.push(LOC(ui2, uj2, 1, curD + 1));
        }
      }
      // 아래로 돌리기
      // 아래로 돌리면 지금좌표가 큐로
      let di1 = pI + 1;
      let dj1 = pJ - 1;

      let di2 = pI + 1;
      let dj2 = pJ ;
      if (!(di1 < 0 || di1 > N - 1 || dj1 < 0 || dj1 > N - 1
        || di2 < 0 || di2 > N - 1 || dj2 < 0 || dj2 > N - 1 || board[di1][dj1] === 1 || board[di2][dj2] === 1)) {
        if (visited[1][pI][pJ] > curD + 1) {
          visited[1][pI][pJ] = curD + 1;
          Q.push(LOC(pI, pJ, 1, curD + 1));
        }
      }
      // 세로방향은 가로로
    } else {
      let pI = curI + 1;
      let pJ = curJ;
      // 오른쪽회전
      let ri1 = pI -1;
      let rj1 = pJ + 1;

      let ri2 = pI;
      let rj2 = pJ+1;
   //   if(pI === 4&& pJ === 2&& curP === 1){
   //     console.log("OO");
  //      console.log(ri1,rj1,ri2,rj2);
 //       console.log("--")
 //     }
      if (!(ri1 < 0 || ri1 > N - 1 || rj1 < 0 || rj1 > N - 1
        || ri2 < 0 || ri2 > N - 1 || rj2 < 0 || rj2 > N - 1 || board[ri1][rj1] === 1 || board[ri2][rj2] === 1)) {
        if (visited[0][pI][pJ] > curD + 1) {
     //     if(pI === 4&& pJ === 2&& curP === 1){
     //       console.log("OO2");
      //    }
          visited[0][pI][pJ] = curD + 1;
          Q.push(LOC(pI, pJ, 0, curD + 1));
        }
      }

      let li1 = pI - 1;
      let lj1 = pJ - 1;

      let li2 = pI;
      let lj2 = pJ - 1;

      if (!(li1 < 0 || li1 > N - 1 || lj1 < 0 || lj1 > N - 1
        || li2 < 0 || li2 > N - 1 || lj2 < 0 || lj2 > N - 1
        || board[li1][lj1] === 1 || board[li2][lj2] === 1)) {
        if (visited[0][li2][lj2] > curD + 1) {
          visited[0][li2][lj2] = curD + 1;
          Q.push(LOC(li2, lj2, 0, curD + 1));
        }
      }
    }
  }
  //console.log(ans);
  return ans;
}

//solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]);
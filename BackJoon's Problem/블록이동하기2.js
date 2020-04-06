function solution(board) {

  // state 0 : 가로
  // state 1 : 세로

  let N = board.length;
  let visited = [];
  for (let k = 0; k < 2; k++) {
    let a = [];
    for (let i = 0; i < board.length; i++) {
      let b = [];
      for (let i = 0; i < board.length; i++) {
        b.push(987654321);
      }
      a.push(b);
    }
    visited.push(a);
  }

  let Di = [-1, 0, 1, 0];
  let Dj = [0, 1, 0, -1];

  const min = (a, b) => a > b ? b : a;
  const LOC = (i, j, p, depth) => {
    return {
      i, j, p, depth
    }
  };

  let Q = [];
  Q.push(LOC(0, 0, 0, 0));
  visited[0][0][0] = 0;
  while (Q.length !== 0) {
    let cur = Q.shift();
    //console.log(cur);
    //console.log(Q);
    let curI = cur.i;
    let curJ = cur.j;
    let curP = cur.p;
    let curD = cur.depth;

    // 이동
    for (let d = 0; d < 4; d++) {
      let ni = curI + Di[d];
      let nj = curJ + Dj[d];
      // console.log(ni,nj);
      // 가로방향, 인덱스, 오른쪽에 있는 친구 체크, visited 체크
      if (curP === 0 && (ni < 0 || ni > N - 1 || nj < 0 || nj + 1 > N - 1
        || board[ni][nj + 1] !== 0 || board[ni][nj] !== 0 || visited[curP][ni][nj] <= curD + 1)) continue;
      if (curP === 1 && (ni < 0 || ni + 1 > N - 1 || nj < 0 || nj > N - 1
        || board[ni + 1][nj] !== 0 || board[ni][nj] !== 0 || visited[curP][ni][nj] <= curD + 1)) continue;
      visited[curP][ni][nj] = curD + 1;
      Q.push(LOC(ni, nj, curP, curD + 1));
    }

    // 지금 방향이 가로일때 회전
    if (curP === 0) {
      // 시계 방향 회전
      if (!(curI + 1 > N - 1 || board[curI + 1][curJ + 1] === 1 || board[curI + 1][curJ] === 1
        || visited[1][curI][curJ] <= curD + 1)) {
        visited[1][curI][curJ] = curD + 1;
        Q.push(LOC(curI, curJ, 1, curD + 1));
      }
      // 반시계방향
      if (!(curI - 1 < 0 || board[curI - 1][curJ + 1] === 1 || board[curI - 1][curJ] === 1
        || visited[1][curI - 1][curJ] <= curD + 1)) {
        visited[1][curI - 1][curJ] = curD + 1;
        Q.push(LOC(curI-1, curJ, 1, curD + 1));
      }
      // 다른 친구로 부터 회전
      // 시계 방향
      if (!(curI - 1 < 0 || board[curI - 1][curJ] === 1 || board[curI - 1][curJ + 1] === 1
        || visited[1][curI - 1][curJ + 1] <= curD + 1)) {
        visited[1][curI - 1][curJ + 1] = curD + 1;
        Q.push(LOC(curI - 1, curJ + 1, 1, curD + 1));
      }
      // 반시계 방향
      if (!(curI + 1 > N - 1 || board[curI + 1][curJ] === 1 || board[curI + 1][curJ + 1] === 1
        || visited[1][curI][curJ + 1] <= curD + 1)) {
        visited[1][curI][curJ + 1] = curD + 1;
        Q.push(LOC(curI, curJ + 1, 1, curD + 1));
      }
    }
    // 지금 방향이 세로일때 회전
    if (curP === 1) {
      //시계방향 회전
      if (!(curJ - 1 < 0 || board[curI + 1][curJ - 1] === 1 || board[curI][curJ - 1] === 1
        || visited[0][curI][curJ - 1] <= curD + 1)) {
        visited[0][curI][curJ - 1] = curD + 1;
        Q.push(LOC(curI, curJ - 1, 0, curD + 1))
      }
      // 반시계 방향 회전전
      if (!(curJ + 1 > N - 1 || board[curI + 1][curJ + 1] === 1 || board[curI][curJ + 1] === 1
        || visited[0][curI][curJ] <= curD + 1)) {
        visited[0][curI][curJ] = curD + 1;
        Q.push(LOC(curI, curJ, 0, curD + 1));
      }
      // 다른 친구로부터 회전
      // 시계방향회전
      if (!(curJ + 1 > N - 1 || board[curI][curJ + 1] === 1 || board[curI + 1][curJ + 1] === 1
        || visited[0][curI + 1][curJ] <= curD + 1)) {
        visited[0][curI + 1][curJ] = curD + 1;
        Q.push(LOC(curI + 1, curJ, 0, curD + 1));
      }
      // 반시계방향 회전
      if (!(curJ - 1 < 0 || board[curI + 1][curJ - 1] === 1 || board[curI][curJ - 1] === 1
        || visited[0][curI + 1][curJ - 1] <= curD + 1)) {
        visited[0][curI + 1][curJ - 1] = curD + 1;
        Q.push(LOC(curI + 1, curJ - 1, 0, curD + 1));
      }
    }
  }
  let ans = min(visited[1][N - 2][N - 1], visited[0][N - 1][N - 2]);
  //console.log(ans);
  return ans;
}

solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]);
// 해당범위에 6개
function solution(board) {
  let Di = [[0, -1, -2, 0, -1, -2], [0, -1, 0, -1, 0, -1]];
  let Dj = [[0, 0, 0, 1, 1, 1], [0, 0, 1, 1, 2, 2]];
  let N = board.length;
  let M = board[0].length;

  function fillminusZero() {
    for (let j = 0; j < M; j++) {
      for (let i = 0; i < N; i++) {
        if (board[i][j] !== 0) break;
        board[i][j] = -1;
      }
    }
  }

  function recover() {
    for (let j = 0; j < M; j++) {
      for (let i = 0; i < N; i++) {
        if (board[i][j] === -1) board[i][j] = 0;
      }
    }
  }

  function isTrue(i, j) {

    for (let m = 0; m < 2; m++) {
      let nonZero = 0;
      let cnt = 0;
      let isthereZero = false;
      for (let d = 0; d < 6; d++) {
        let ni = i + Di[m][d];
        let nj = j + Dj[m][d];
        if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) {
          isthereZero = true;
          break;
        }
        let nextNo = board[ni][nj];
        if (nextNo === 0) {
          isthereZero = true;
          break;
        }
        // 0이아니고 -1 이 아니다
        // => 블록이다
        if (nextNo !== -1) {
          if (nonZero === 0) {
            nonZero = nextNo;
            cnt++;
          } else {
            if (nonZero !== nextNo) {
              isthereZero = true;
              break;
            } else {
              cnt++;
            }
          }
        }
      }

      if (cnt === 4 && !isthereZero) {
        for (let d = 0; d < 6; d++) {
          let ni = i + Di[m][d];
          let nj = j + Dj[m][d];
          board[ni][nj] = 0;
        }
        return true;
      }
    }
    return false;
  }

  let ans = 0;
  while (1) {
    let Find = false;
    for (let i = 0; i < M; i++) {
      for (let j = 0; j < N; j++) {
        recover();
        fillminusZero();
        if (isTrue(i, j)) {
          Find = true;
          ans++;
          break;
        }
      }
    }
    if (!Find) break;
  }
//  recover();

  //console.log(board);
  //console.log(ans);
  return ans;
}

//solution(	[[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 4, 0, 0, 0], [0, 0, 0, 0, 0, 4, 4, 0, 0, 0], [0, 0, 0, 0, 3, 0, 4, 0, 0, 0], [0, 0, 0, 2, 3, 0, 0, 0, 5, 5], [1, 2, 2, 2, 3, 3, 0, 0, 0, 5], [1, 1, 1, 0, 0, 0, 0, 0, 0, 5]]);

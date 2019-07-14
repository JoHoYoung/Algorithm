const readline = require("readline");
let rq = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


const map = [];
let row;
let col;

let count = 0;
rq.on('line', (line) => {
  if (count === 0) {
    let input = line.split(' ');
    row = input[0];
    col = input[1];
    count++;
  } else {
    let input = line.split('');
    map.push(input);
  //  console.log("COUNT", count, row, col)
    if (count == row)
      rq.close();

    count++
  }
}).on('close', () => {
 // console.log(map)
  solution(map)
});

//위 0 , 오른쪽 1, 아래 2, 왼쪽 3
const DIR = [[-1, 0], [0, 1], [1, 0], [0, -1]];


// true = stop
// false = non stop
function stop(x, y) {
  //console.log("X : ",x," Y : ", y)
  return map[y][x] === '#';
}

let result = -1;

function max(a, b) {

  if (a == -1)
    return b;

  if (b == -1)
    return a;

  if (a < b)
    return a;
  return b;
}

function move(dir, Rx, Ry, Bx, By, isRstop, isBstop, depth) {

  //console.log("DIR : ", dir)
  // 구멍에 들어갔는지 판단도 둘다 멈췄을때 해야함
  // O도 멈춤.

//  console.log("DEPTH", depth)
 // console.log("RED (", Rx, " , ", Ry, ") BLUE (", Bx, " , ", By, ") POINT", map[Ry][Rx], " : ", map[By][Bx]);
  //5번횟수 지나면

  if (depth > 10)
    return;

  // 함수로 들어오는것은 앞으로의 방향과 지금위치
  // 앞으로의 방향이 벽이다? 지금위치유지.
  let newRx = Rx + DIR[dir][1];
  let newRy = Ry + DIR[dir][0];
  let newBx = Bx + DIR[dir][1];
  let newBy = By + DIR[dir][0];

  // 둘다 해당방향으로 다음 진행사항이 없다면 재귀
  // 지금방향말고, 지금이랑 반대방향 말고.
  // 멈췄을때 빨간공, 파란공 위치판단해야함.
  if (map[By][Bx] === 'O') {
    return;
  } else if (map[Ry][Rx] === 'O') {
    if (stop(newBx, newBy)) {
  //    console.log("R REturn");
      result = max(result, depth);
      return;
    } else {
      move(dir, Rx, Ry, newBx, newBy, 0, 0, depth);
    }
  }


  // 둘다 다음방향으로 진행할 수 없을때
  if (stop(newRx, newRy) && stop(newBx, newBy)) {
  //  console.log("IS STOP TRUE", newRx, newRy);
    if (Rx === Bx && Ry === By) {
      if (isRstop === 1) {
        Bx -= DIR[dir][1];
        By -= DIR[dir][0];
      }

      if (isBstop === 1) {
        Rx -= DIR[dir][1];
        Ry -= DIR[dir][0];
      }
    }


    for (let i = 0; i <= 3; i++) {
      if (i !== dir - 2 && i !== dir + 2 && i !== dir) {
        if (!stop(Rx + DIR[i][1], Ry + DIR[i][0]) || !stop(Bx + DIR[i][1], By + DIR[i][0])) {
          move(i, Rx, Ry, Bx, By, 0, 0, depth + 1);
        }

      }
    }
  } else {
    let isRstop = 0;
    let isBstop = 0;
    if (stop(newRx, newRy)) {
      newRx = Rx;
      newRy = Ry;
      isRstop = 1;
    }

    if (stop(newBx, newBy)) {
     // console.log("HERE")
      newBx = Bx;
      newBy = By;
      isBstop = 1;
    }
    move(dir, newRx, newRy, newBx, newBy, isRstop, isBstop, depth);
  }
}


// 재귀로 뻗어나가는 조건은 둘다 멈춘 상태일때.
function solution(map) {

  let Rx, Ry, Bx, By;
  for (let i = 0; i < map.length; i++) {
    for (let j = 0; j < map[0].length; j++) {
      if (map[i][j] === 'B') {
        Bx = j;
        By = i;
      }

      if (map[i][j] === 'R') {
        Rx = j;
        Ry = i;
      }
    }
  }
  //console.log(Rx, Ry, Bx, By)
  for (let i = 0; i < 4; i++) {
    if (!stop(Rx + DIR[i][1], Ry + DIR[i][0]) || !stop(Bx + DIR[i][1], By + DIR[i][0])){
      move(i, Rx, Ry, Bx, By, 0, 0, 1);
    }
  }

  console.log(result);
}

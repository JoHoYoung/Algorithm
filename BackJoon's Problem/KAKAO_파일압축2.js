function solution(msg) {
  let max = 26;
  let dict = {
    "A":1,
    "B":2,
    "C":3,
    "D":4,
    "E":5,
    "F":6,
    "G":7,
    "H":8,
    "I":9,
    "J":10,
    "K":11,
    "L":12,
    "M":13,
    "N":14,
    "O":15,
    "P":16,
    "Q":17,
    "R":18,
    "S":19,
    "T":20,
    "U":21,
    "V":22,
    "W":23,
    "X":24,
    "Y":25,
    "Z":26,
  };
  let C = msg[0];
  let idx = 1;
  let result = [];
  while(idx<msg.length){
    while(dict[C]&& idx <msg.length){
      C += msg[idx++];
    }
    if(dict[C]){

    }else{
      dict[C] = ++max;
      result.push(dict[C.substring(0,C.length-1)]);
      C = C[C.length-1]
    }
    // C는 없는 글자.
  }
  result.push(dict[C]);
  console.log(result);
  console.log(dict);
  return result;
}
solution("KAKAO");
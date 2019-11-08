function solution(dartResult) {

  function Zone(C, upper, num) {
    switch (C) {
      case 'S' :
        return [upper, num];
      case 'D' :
        return [upper, num * num];
      case 'T' :
        return [upper, num * num * num];
      case '*':
        return [upper * 2, num * 2];
      case '#':
        return [upper, -num];
    }
  }

  let upper = 0;
  let num = 0;
  let result = 0;

  function Action(C) {
    if ((C >= '0' && C <= '9') || C === '10') {
      result += upper;
      upper = num;
      num = parseInt(C);
      console.log("NEW NUM", C, result);
    } else {
      let data = Zone(C, upper, num);
      console.log(data);
      upper = data[0];
      num = data[1];
    }
  }

  for (let i = 0; i < dartResult.length; i++) {
    if (dartResult[i] + dartResult[i + 1] === '10') {
      Action('10');
      i++
    } else {
      let C = dartResult[i];
      Action(C)
    }
  }

  result += num + upper;
  //console.log(result);
  return result;
}

//solution("1D2S#10S")
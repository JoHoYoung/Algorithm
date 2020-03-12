function getAllCombinations(arr, m) {
  const combinations = [];
  const picked = [];
  const used = [];
  for (item of arr) used.push(0);

  function find(picked) {
    if (picked.length === m) {
      const rst = [];
      for (let i of picked) {
        rst.push(arr[i]);
      }
      combinations.push(rst);
      return;
    } else {
      let start = picked.length ? picked[picked.length - 1] + 1 : 0;
      for (let i = start; i < arr.length; i++) {
        if (i === 0 || arr[i] !== arr[i - 1] || used[i - 1]) {
          picked.push(i);
          used[i] = 1;
          find(picked);
          picked.pop();
          used[i] = 0;
        }
      }
    }
  }
  find(picked);
  return combinations;
}

function isUnique(arr){
  let pivot = arr.length;
  let set = new Set();
  for(let i=0;i<arr.length;i++){
    if(arr[i] === "") {
      return false;
    }
    set.add(arr[i])
  }
  return set.size === pivot;
}

function dupCheck(A) {

  for (let i = 0; i < A.length-1; i++) {
    let pivot = A[i];
    for (let j = i + 1; j < A.length; j++) {
      if (pivot == A[j]) {
        return false;
      }
    }
  }
  return true;
}

function partCheck(A,B){
  let count = 0;
  for(let i=0;i<A.length;i++){
    let pivot = A[i];
    for(let j=0;j<B.length;j++){
      if(pivot === B[j]){
        count ++;
        break;
      }
    }
  }
  return count === A.length;
}

function concatArr(arrs) {
  let R = [];
  for (let k = 0; k < arrs[0].length; k++) {
    let TEMP = "";
    for (let i = 0; i < arrs.length; i++) {
      TEMP += ' '+arrs[i][k]
    }
    R.push(TEMP)
  }
  return R;
}

function solution(relation) {

  let Keys= [];

  let newArr = [];
  for (let k = 0; k < relation.length; k++) {
    let line = relation[k];
    for (let i = 0; i < line.length; i++) {
      if (!newArr[i]) {
        newArr[i] = [];
      }
      newArr[i].push(line[i])
    }
  }
  console.log(newArr)
  let depth = 1;
  let result = 0;

  while (1) {

    if (newArr === []){
      break;
    }

    let Indexes = [];

    for (let i = 0; i < newArr.length; i++) {
      Indexes.push(i);
    }

    let A = getAllCombinations(Indexes, depth);

    if(Indexes.length < depth){
      break;
    }

    for (let i = 0; i < A.length; i++) {
      let args = [];
      let temp = [];

      for (let j = 0; j < A[i].length; j++) {
        temp.push(A[i][j]);
        args.push(newArr[parseInt(A[i][j])])
      }

      if (args.length === 0)
        break;

      let R = concatArr(args);
      if (isUnique(R)) {
        if(depth === 1){
          Keys.push(temp)
        }else{
          console.log(Keys)
          let BB = false;

          for(let d = 0;d<Keys.length;d++){
            console.log("temp",temp)
            if(partCheck(Keys[d],temp)) {
              BB = true;
            }
          }
          BB || Keys.push(temp)
        }
      }
    }
    depth++;
  }
  console.log(Keys)
  return Keys.length;
}
//
 let a = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]
 let R = solution(a)
 console.log("RESULT", R)
function solution(n, arr1, arr2) {

  function power(n){
    if(n === 1){
      return 1;
    }
    let result = 1;
    for(let i=1;i<n;i++){
      result *=2;
    }
    return result;
  }

  function numTobin(num){

    let result = [];
    let N = power(n);


    console.log(N,num);
    while(N >= 1){
      if(num >= N){
        num -= N;
        result.push(1);
      }else{
        result.push(0);
      }
      N /= 2;
    }

    for(let i=0;i<n-result.length;i++){
      result.unshift(0);
    }
    return result;
  }

  let A = [];

  function merge(arr1,arr2){
    let temp = [];
    for(let i=0;i<arr1.length;i++){
      temp.push(arr1[i]+arr2[i]);
    }
    return temp
  }
  for(let i=0;i<arr1.length;i++){
    A.push(merge(numTobin(arr1[i]),numTobin(arr2[i])));
  }

  let answer = [];
  for(let i=0;i<A.length;i++){
    let temp =""
    for(let j=0;j<A[0].length;j++){
      if(A[i][j] === 0){
        temp += " "
      }else{
        temp += "#"
      }
    }
    answer.push(temp);
  }
  return answer;
}

solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]);
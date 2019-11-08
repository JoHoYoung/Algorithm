function solution(N, stages) {
  let arr = [];
  let arr2 = [];
  for(let i=0;i<N+1;i++){
    arr.push(0);
    arr2.push(0);
  }

  // 지나친사람
  for(let i=0;i<stages.length;i++){
    for(let j=0;j<=stages[i]-1;j++){
      arr2[j]++;
    }
  }
  console.log(arr,arr2);
  // 남아있는사람
  for(let i=0;i<stages.length;i++){
    arr[stages[i]-1]++;
  }

  console.log(arr,arr2);
  let result = [];
  for(let i=0;i<N;i++){
    if(arr2[i] === 0){
      result.push({i,n:0})
    }else{
      result.push({i,n:arr[i]/arr2[i]})
    }
  }
  result.sort((a,b) => {
    if(a.n === b.n){
      return a.i - b.i;
    }
    return b.n-a.n;
  });
//  console.log(result);
  return result.map(el => el.i+1)
}

//solution(	5, [2, 1, 2, 6, 2, 4, 3, 3])
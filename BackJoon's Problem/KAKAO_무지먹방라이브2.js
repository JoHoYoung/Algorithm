function solution(food_times, k) {
  // k 초 까지.

  let FOOD = [];
  let GG = 0;

  for (let i = 0; i < food_times.length; i++) {
    FOOD.push({IDX: i, T: food_times[i]});
    GG += food_times[i];
  }

  if (GG <= k){
    return -1;
  }

  FOOD.sort((a, b) => {
    return a.T - b.T;
  });

  let dict = {};

  for(let i=0;i<FOOD.length;i++){
    if(!dict[FOOD[i].T]){
      dict[FOOD[i].T] = 0;
    }
    dict[FOOD[i].T]++;
  }


  let remain = FOOD.length;
  let N = 1;

  // N번째 바퀴를 돈다
  //

  let upper = 0;
  for(let C=0;C<FOOD.length;C++) {
    if(FOOD[C].T !== upper){
      N = FOOD[C].T;
      if(k - (remain*(N-upper)) < 0){
        break;
      }
      k -= (remain*(N-upper));
      remain -= dict[N];
      upper = FOOD[C].T;
    }
  }

  FOOD = FOOD.filter(el => el.T > N-1);

  FOOD.sort((a, b) => {
    return a.IDX - b.IDX
  });


  return FOOD[k%remain].IDX + 1;
}

//
// console.log(solution([3, 1, 2,100000], 1))
//console.log(solution([10, 8, 3,2,5,1], 20));
// console.log(solution([3, 1, 2], 3));
// console.log(solution([3, 1, 2], 4));
// console.log(solution([3, 1, 2], 5));
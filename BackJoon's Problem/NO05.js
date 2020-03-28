function solution(stones, k) {

  let l = 0;
  let r = 200000000;

  let ans = -1;
  function max(a, b){
    return a>b ? a:b;
  }
  while (l <= r) {
    let mid = parseInt((l + r) / 2);
    let _stones = stones.slice();
    let cont = 0;
    let find = true;

    for (let i = 0; i < _stones.length; i++) {
      _stones[i] -= mid;

      if (_stones[i] < 0) cont++;
      else cont = 0;

      if (cont >= k) {
        find = false;
        break;
      }
    }
    if(!find) r = mid - 1;
    else {
      ans = max(mid, ans);
      l = mid+1;
    }
  }
  return ans;
}

solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3);
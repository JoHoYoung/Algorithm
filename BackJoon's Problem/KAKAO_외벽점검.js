function solution(n, weak, dist) {

  function swap(i, j, arr) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  let perm = [];

  function permutation(depth, end, arr) {
    if (depth === end) {
      perm.push(arr.slice());
      return;
    }
    for (let i = depth; i < arr.length; i++) {
      swap(i, depth, arr);
      permutation(depth + 1, end, arr);
      swap(i, depth, arr);
    }
  }

  for (let t = 1; t <= dist.length; t++) {
    let _friends = dist.slice(dist.length - t, dist.length);
    permutation(0, _friends.length - 1, _friends);
  }

  for (let target of perm) {
    let _weak = weak.slice();
    for (let i = 0; i < weak.length; i++) {
      let _friend = target.slice();
      if (i) {
        _weak.push(n + _weak.shift());
      }
      let offset = 0;
      let nowFriend = 0;

      while (offset < weak.length && nowFriend <= _friend.length) {
        for (let a = offset; a < weak.length; a++) {
          let dist = _weak[a + 1] - _weak[a];
          offset = a;
          if (_friend[nowFriend] >= dist) {
            _friend[nowFriend] -= dist;
          } else {
            offset++;
            nowFriend++;
            break;
          }
        }
      }
      if (offset === weak.length && nowFriend === target.length) {
        return _friend.length;
      }
    }
  }
  return -1;
}

console.log(solution(12, [1, 3, 4, 9, 10], [3, 5, 7]));
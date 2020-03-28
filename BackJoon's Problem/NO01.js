function solution(board, moves) {
  let nboard = [];
  let ans = 0;
  let st = [];
  for(let i=0;i<board.length;i++){
    let arr =[];
    for(let j=0;j<board.length;j++){
      if(board[j][i] === 0 )continue;
      arr.push(board[j][i]);
    }
    nboard.push(arr);
  }
  nboard.map((el) => el.reverse());
  console.log(nboard);
  function mv(idx){
    if(nboard[idx].length === 0) return;
    let d = nboard[idx].pop();
    if(st.length === 0 ){
      st.push(d);
    }else{
      if(st[st.length-1] === d ){
        st.pop();
        ans+=2;
      }else{
        st.push(d);
      }
    }
  }

  for(let i=0;i<moves.length;i++){
    mv(moves[i]-1);
  }
  console.log(nboard)
  //console.log(ans);
  return ans;
}

solution(	[[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]);
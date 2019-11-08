function solution(n, build_frame) {

  let Cmap = [];
  let Bmap = [];

  function getEmpty() {
    let arr = [];
    for (let i = 0; i <= n; i++) {
      arr.push(0)
    }
    return arr;
  }

  for (let i = 0; i <= n; i++) {
    Cmap.push(getEmpty());
    Bmap.push(getEmpty());
  }

  function isCorrectC(){
    for(let i=0;i<=n;i++){
      for(let j=0;j<=n;j++){

        if(Cmap[i][j] === 1) {
          if (!canInsertC(i, j)) {
            return false;
          }
        }

        if(Bmap[i][j] === 1){
          if(!canInsertB(i,j)){
            return false;
          }
        }

      }
    }
    return true;
  }

  function isCorrectB(){
    for(let i=0;i<=n;i++){
      for(let j=0;j<=n;j++){

        if(Bmap[i][j] === 1){
          if(!canInsertB(i,j)){
            return false;
          }
        }

        if(Cmap[i][j] === 1){
          if(!canInsertC(i,j)){
            return false;
          }
        }
      }
    }
    return true;
  }

  function canInsertC(i, j) {
    if (i === 0) {
      return true;
    }

    if (Cmap[i - 1][j] === 1) {
      return true;
    }

    if (Bmap[i][j - 1] === 1 || Bmap[i][j] === 1) {
      return true;
    }

    return false;
  }

  function canInsertB(i,j){

    if(Cmap[i-1][j] === 1){
      return true;
    }

    if(Cmap[i-1][j+1] === 1){
      return true;
    }

    if (Bmap[i][j-1]===1 && Bmap[i][j+1] === 1){
      return true;
    }
    return false;
  }

  function insertC(i, j) {
    Cmap[i][j] = 1
  }

  function deleteC(i, j) {
    Cmap[i][j] = 0
  }

  function insertB(i, j) {
    Bmap[i][j] = 1
  }

  function deleteB(i, j) {
    Bmap[i][j] = 0
  }

  for(let t=0;t<build_frame.length;t++){
    let i = build_frame[t][1];
    let j = build_frame[t][0];
    let a = build_frame[t][2];
    let b = build_frame[t][3];

    if(b === 1){
      if(a === 0){
        if(canInsertC(i,j)){
          insertC(i,j)
        }
      }else{
        if(canInsertB(i,j)){
          insertB(i,j)
        }
      }
    }else{
      if(a === 0){
        deleteC(i,j);
        if(!isCorrectC()){
          insertC(i,j)
        }
      }else{
        deleteB(i,j);
        if(!isCorrectB()){
          insertB(i,j)
        }
      }
    }
  }

  let result = [];
  for(let i=0;i<=n;i++){
    for(let j=0;j<=n;j++){
      if(Cmap[i][j] === 1){
        result.push([j,i,0]);
      }
      if(Bmap[i][j] === 1){
        result.push([j,i,1]);
      }
    }
  }

  result.sort((a,b) => {
    if(a[0] === b[0]){
      if(a[1] === b[1]){
        return a[2] - b[2];
      }
      return a[1] - b[1];
    }
    return a[0] - b[0];
  });
  return result;
  //0 삭제 1설치
}

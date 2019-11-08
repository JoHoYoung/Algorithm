function solution(files) {

  let FILES = [];
  // function reset(){
  //   for(let i=0;i<files.length;i++){
  //     let idx = 0;
  //     let idx2 = 0;
  //     for(let j=0;j<files[i].length;j++){
  //       let c = files[i][j];
  //       if(c >='0' && c<='9'){
  //         idx = j;
  //         break;
  //       }
  //     }
  //
  //     for(let j=idx;j<files[i].length;j++){
  //       let c = files[i][j];
  //       if(c <'0' || c>'9'){
  //         idx2 = j;
  //         break;
  //       }
  //     }
  //
  //     let HEAD = files[i].substring(0,idx).toLowerCase();
  //     let NUMBER = parseInt(files[i].substring(idx,idx2));
  //     FILES.push({HEAD,NUMBER,IDX:i,NAME:files[i]});
  //   }
  //
  // }
  //
  // reset();
  for(let i=0;i<files.length;i++){
    let numbers = files[i].match(/\d+/g).map(String);
    let number;
    for(let i=0;i<numbers.length;i++){
      if(numbers[i].length > 5){
        continue;
      }
      number = numbers[i];
      break;
    }
    let arr = files[i].split(number);
    FILES.push({IDX:i,NAME:files[i], HEAD:arr[0].toLowerCase(), NUMBER:parseInt(number), tail:arr[1]})
  }

  FILES.sort((a,b) => {
    if(a.HEAD === b.HEAD){
      if(a.NUMBER === b.NUMBER){
        return a.IDX - b.IDX
      }
      return a.NUMBER - b.NUMBER
    }
        if (a.HEAD > b.HEAD ){
          return 1;
        }
        return -1;
  });
  // FILES.sort((a,b) => {
  //   if(a.HEAD === b.HEAD){
  //     if(parseInt(a.NUMBER) === parseInt(b.NUMBER)){
  //       return a.IDX - b.IDX
  //     } else {
  //       return parseInt(a.NUMBER) - parseInt(b.NUMBER)
  //     }
  //   } else {
  //     if (a.HEAD > b.HEAD ){
  //       return 1;
  //     }
  //     return -1;
  //   }
  // });

  return FILES.map((el) => {return el.NAME});
}
//solution(	["23100.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])
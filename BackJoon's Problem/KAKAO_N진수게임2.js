function solution(n, t, m, p) {
  let dict = {
    "1":"1",
    "2":"2",
    "3":"3",
    "4":"4",
    "5":"5",
    "6":"6",
    "7":"7",
    "8":"8",
    "9":"9",
    "10":"A",
    "11":"B",
    "12":"C",
    "13":"D",
    "14":"E",
    "15":"F",
  };

  function NumToN(num){
    let pivot =1;
    let result = "";

    while(pivot<=num){
      pivot *=n;
    }

    if(pivot !== 1){
      pivot /= n;
    }
    //console.log("PIVOT",pivot,num);
    while(pivot >= 1){
      if(num>=pivot){
        let n = parseInt(num/pivot);
        result += dict[parseInt(num/pivot).toString()];
        num -= n*pivot;
      }else{
        result += '0';
      }
      pivot /= n;
    }
    return result;
  }
  let tosay = "";
  let pivot = 0;
  while(tosay.length < t*m ){
   tosay += NumToN(pivot++)
  }
  let result = "";
  let i = 0;
  while(result.length<t){
    result += tosay[m*(i)+(p-1)];
    i+=1;
  }
  return result;
}
solution(16, 16, 2, 2);
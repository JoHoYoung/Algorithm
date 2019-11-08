function solution(word, pages) {

  word = word.toLowerCase();
  function getBasic(data){
    let baseScore = 0;
    let a = data.split('<body>')[1].split('</body>')[0].split(/[^A-Za-z]/);
    for(let k=0;k<a.length;k++){
      if(a[k].toLowerCase() === word.toLowerCase()){
        baseScore++;
      }
    }
    return baseScore;
  }

  function getMeta(data){
    let a = data.split('<meta property=\"og:url\" content="');
    return (a[1].split('"/>'))[0]
  }

  function getLinks(data){
    let a = data.split("a href=\"");
    let b = [];
    for(let i=1;i<a.length;i++){
      b.push((a[i].split('">'))[0]);
    }

    return b;
  }

  let data = {};
  for(let i=0;i<pages.length;i++){
    data[getMeta(pages[i])] = {basic:getBasic(pages[i].toLowerCase()),meta:getMeta(pages[i]),link:getLinks(pages[i]),out:0,result:0};
  }

  for(let key in data){
    data[key].linkscore = data[key].link.length;
    let links = data[key].link;
    for(let i=0;i<links.length;i++){
      if(data[links[i]]){
        data[links[i]].out++
      }
    }
  }

  for(let key in data){
    let links = data[key].link;
    for(let i=0;i<links.length;i++){
      if(data[links[i]]) {
        data[links[i]].result += (data[key].basic / data[key].linkscore)
      }
    }
  }

  let max = [];
  let idx = 0;
  for(let key in data){
    max.push({idx:idx++,num:data[key].basic + data[key].result});
  }
  console.log(max);
  return (max.sort((a,b) => {
    if(a.num === b.num){
      return a.idx - b.idx
    }
    return b.num - a.num
  }))[0].idx

}
//solution("blind", ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"])
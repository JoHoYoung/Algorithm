function solution(word, pages) {
    const pageInfo = [];
    for(let i=0;i<pages.length;i++){
        let out = {};
        let outscore = 0;
        let baseScore = 0;
        let a = pages[i].split('<body>')[1].split('</body>')[0].split(/[^A-Za-z]/);
        for(let k=0;k<a.length;k++){
            if(a[k].toLowerCase() === word.toLowerCase()){
                baseScore++;
            }
        }
        let temp = pages[i].split("<meta property=\"og:url\" content=\"")[1];
        let url = temp.split("\"/>")[0];

        let temp2 = pages[i].split("<a href=\"").map((line) => line.split("\">")[0]);
        for(let j=1;j<temp2.length;j++){
            out[temp2[j]] ='T';
            outscore ++;
        }
        pageInfo.push({baseScore,url,out,outscore})
    }

    let ranks = [];
    for(let start =0;start<pageInfo.length;start++){
        let temp = 0;
        for(let i=0;i<pageInfo.length;i++){
            if(start === i){
                continue;
            }
            if(pageInfo[i].out[pageInfo[start].url]){
                temp += pageInfo[i].baseScore / pageInfo[i].outscore;
            }
        }
        ranks.push({idx:start, score:temp + pageInfo[start].baseScore});
    }
    ranks.sort((a,b) => {
        if(b.score === a.score){
            return a.idx - b.idx;
        }
        return b.score - a.score;
    });
    return ranks[0].idx;
}
//solution('Blind',["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"])
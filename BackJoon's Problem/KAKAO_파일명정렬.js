function solution(files) {
    let obj = [];
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
        obj.push({index:i,name:files[i], head:arr[0].toLowerCase(), number, tail:arr[1]})
    }

    obj.sort((a,b) => {
        if(a.head === b.head){
            if(parseInt(a.number) === parseInt(b.number)){
                return a.index - b.index
            } else {
                return parseInt(a.number) - parseInt(b.number)
            }
        } else {
            if (a.head > b.head ){
                return 1;
            }
            return -1;
        }
    });
    //console.log(obj);
    return obj.map(el => el.name);
}
let a = solution(["foo001000bar020.zip","F-5 Freedom Fighter", "a-50 Superfortress", "A-10 Thunderbolt II", "Fdsafadsfas-014 Tomcat"]);
console.log(a)
/*
스타상 : 2배
아차상 : 마이너스

싱글, 더블, 트리플 : 1,2,3 제곱
스타상 : 해당점수와, 바로전에 얻은 점수 두배.
첫스타 : 첫점수만 두배.

 */

// 점수를 스택에 넣고 팝하면듯
let stack = [];
let idx = -1;
function push(el){
    stack[++idx] = el;
}
// #은 바로앞에거 -1
// 스택에서 언제팝할것인가 : *을 만났을때.

function pop(){
    return stack[idx--];
}

function solution(dartResult) {
    let i =0;
    let temp = 0;
    while(1){
        let char = dartResult[i];
        // isDigit
        if( char >= '0' && char <='9'){
            if(i !== 0){
                push(parseInt(temp));
            }
            if(char ==='1'){
                if(dartResult[i+1] === '0'){
                    temp =10;
                    i+=2;
                    continue;
                }
                temp = 1;
            }else{
                temp = char;
            }
        }

        if(char === 'D'){
            temp = temp*temp;
        }

        if(char === 'T'){
            temp = temp*temp*temp;
        }

        if(char === '#'){
            temp *= -1;
        }

        if(char === '*'){
            temp *= 2;
            if(idx !== -1){
                let el = pop();
                push(el*2)
            }
        }
        console.log(stack)
        i++;
        if(i === dartResult.length){
            push(parseInt(temp));
            break;
        }
    }
    console.log(stack)
    let re = 0;
    for(let i=0;i<stack.length;i++){
        re += stack[i];
    }
    console.log(re);
    return re;
}
solution("10S2D*3T");

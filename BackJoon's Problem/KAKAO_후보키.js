function getAllCombinations(arr, m) {
    const combinations = [];
    const picked = [];
    const used = [];
    for (item of arr) used.push(0);

    function find(picked) {
        if (picked.length === m) {
            const rst = [];
            for (let i of picked) {
                rst.push(arr[i]);
            }
            combinations.push(rst);
            return;
        } else {
            let start = picked.length ? picked[picked.length - 1] + 1 : 0;
            for (let i = start; i < arr.length; i++) {
                if (i === 0 || arr[i] !== arr[i - 1] || used[i - 1]) {
                    picked.push(i);
                    used[i] = 1;
                    find(picked);
                    picked.pop();
                    used[i] = 0;
                }
            }
        }
    }
    find(picked);
    return combinations;
}

function dupCheck(A) {
    for (let i = 0; i < A.length; i++) {
        let pivot = A[i];
        for (let j = i + 1; j < A.length; j++) {
            if (pivot == A[j]) {
                return false;
            }
        }
    }
    return true;
}

function concatArr(arrs) {
    let R = [];
    for (let k = 0; k < arrs[0].length; k++) {
        let TEMP = "";
        for (let i = 0; i < arrs.length; i++) {
            TEMP += ' '+arrs[i][k]
        }
        R.push(TEMP)
    }
    return R;
}

function solution(relation) {
    var answer = 0
    let newArr = [];
    for (let k = 0; k < relation.length; k++) {
        let line = relation[k];
        for (let i = 0; i < line.length; i++) {
            if (!newArr[i]) {
                newArr[i] = [];
            }
            newArr[i].push(line[i])
        }
    }

    let depth = 1;
    let result = 0;

    while (1) {

        if (newArr == []){
            break;
        }

        let Indexes = [];
        let ToMark = [];

        for (let i = 0; i < newArr.length; i++) {
            Indexes.push(i);
        }

        let A = getAllCombinations(Indexes, depth);
       // console.log("A",A)
        if(A.length === 0){
            break;
        }

        for (let i = 0; i < A.length; i++) {
       //     console.log("COMB", A)
       //     console.log("단계 : ",i);
            let args = [];
            let temp = [];

            for (let j = 0; j < A[i].length; j++) {
                temp.push(A[i][j]);
                args.push(newArr[parseInt(A[i][j])])
            }

            // console.log("ARG", args);
            if (args.length === 0)
                break;

            let R = concatArr(args);
            if (dupCheck(R)) {
            //    console.log('R',R)
                result++;
                for (let i = 0; i < temp.length; i++) {
                    ToMark.push(temp);
                }
            }
        }

        let MARK =[];

        for(let i=0;i<ToMark.length;i++){
            for(let j=0;j<ToMark[i].length;j++){
                MARK[j] = true;
            }
        }

       // console.log(newArr)
        for(let i=newArr.length;i>=0;i--){
            if(MARK[i]) {
                newArr.splice(i,1);
            }
        }
        depth++;
    }
    return result;
}
//
let a = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]
let R = solution(a)
console.log("RESULT", R)
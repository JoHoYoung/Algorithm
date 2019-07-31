let preResult = [];
let postResult = [];
function preorder(pivot){
    preResult.push(pivot.idx+1);
    if(pivot.child){
        if(pivot.child.left){
            console.log("IN2")
            preorder(pivot.child.left)
        }
        if(pivot.child.right){
            preorder(pivot.child.right)
        }
    }
}

function postorder(pivot){
    if(pivot.child){
        if(pivot.child.left){
            postorder(pivot.child.left)
        }
        if(pivot.child.right){
            postorder(pivot.child.right)
        }
    }
    postResult.push(pivot.idx+1);
}

let tree = [];
function buildTree(pivot,node,side){
    if(!pivot[side]){
        console.log('GET')
        pivot[side] = node;
        return;
    }
    if(pivot[side].val[0]<node.val[0]){
        // 오른쪽에 추가
        buildTree(pivot[side].child, node, 'right')
    }else{
        // 왼쪽에 추가.
        buildTree(pivot[side].child, node, 'left')
    }
}
function solution(nodeinfo) {
    let arr= [];
    for(let i=0;i<nodeinfo.length;i++){
        arr.push({idx:i,val:nodeinfo[i],child:{left:null,right:null}});
    }
    arr.sort((a,b) => {
        if(a.val[1]===b.val[1]){
            return a.val[0]-b.val[0];
        }
        return b.val[1] - a.val[1];
    });
    tree[0] = arr[0];
    for(let i=1;i<arr.length;i++){
        if(arr[i].val[0] < arr[0].val[0]){
            buildTree(arr[0].child,arr[i], 'left')
        }else{
            buildTree(arr[0].child,arr[i], 'right')
        }
    }
    preorder(arr[0]);
    postorder(arr[0]);
    return [preResult,postResult];
}
console.log(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]));


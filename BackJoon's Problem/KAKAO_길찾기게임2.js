function solution(nodeinfo) {

  let result = [];
  for(let i=0;i<nodeinfo.length;i++){
    result.push({idx:i,data:nodeinfo[i]});
  }

  result.sort((a,b) => {
    return b.data[1] - a.data[1]
  });

  function newNode(node){
    return {
      x:node.data[0],
      num : node.idx
    }
  }

  function push(Node,newnode){
    if(newnode.x < Node.x){
      if(Node.left){
        push(Node.left,newnode)
      }else{
        Node.left = newnode
      }
    }else{
      if(Node.right){
        push(Node.right,newnode)
      }else{
        Node.right = newnode;
      }
    }
  }

  console.log(result);
  let root = newNode(result[0]);
  console.log(root);
  for(let i=1;i<result.length;i++){
    push(root,newNode(result[i]));
  }

  let preorder = [];
  function preOrder(node){
    preorder.push(node.num+1);
    if(node.left){
      preOrder(node.left)
    }
    if(node.right){
      preOrder(node.right)
    }
  }

  let postorder = [];
  function postOrder(node){
    if(node.left){
      postOrder(node.left)
    }
    if(node.right){
      postOrder(node.right)
    }
    postorder.push(node.num+1);
  }
  preOrder(root);
  postOrder(root);

  return [preorder, postorder]
}
//solution([[5, 3], [11, 5], [13, 3], [3, 5], [6, 1], [1, 3], [8, 6], [7, 2], [2, 2]]);
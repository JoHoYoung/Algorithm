function solution(record) {
  let dict = {}
  function Action(M){
    let msg = M.split(' ');
    let command = msg[0];
    let uid = msg[1];

    switch (command) {
      case "Enter":
        dict[uid] = msg[2];
        break;
      case "Change":
        dict[uid] = msg[2];
        break;
    }
  }
  let result = [];
  function Action2(M){
    let msg = M.split(' ');
    let command = msg[0];
    let uid = msg[1];
    switch (command) {
      case "Enter":
        result.push(`${dict[uid]}님이 들어왔습니다.`)
        break;
      case "Leave":
        result.push(`${dict[uid]}님이 나갔습니다.`)
        break;
    }
  }

  for(let i=0;i<record.length;i++){
    Action(record[i]);
  }
  for(let i=0;i<record.length;i++){
    Action2(record[i]);
  }
  return result;
}
function solution(cacheSize, cities) {

  if(cacheSize === 0){
    return 5*cities.length;
  }
  let cache = [];
  cities = cities.map(el => el.toLowerCase());

  function enqueue(el){
    cache.push(el);
  }

  function dequeue(){
    cache.splice(0,1);
    return cache[0];
  }

  function enCache(el){
    if(cache.length >= cacheSize){
      dequeue();
      enqueue(el)
    }else{
      enqueue(el)
    }
  }

  function match(str){
    let idx = cache.indexOf(str);
    if(idx === -1){
      enCache(str);
      return false;
    }else{
      cache.splice(idx,1);
      enCache(str);
      return true;
    }
  }

  let cost = 0;
  for(let i=0;i<cities.length;i++){
    if(match(cities[i])){
      cost += 1;
    }else{
      cost  += 5;
    }
  }
  return cost;
}
solution(2, ["Jeju", "Pangyo", "NewYork", "newyork"]);
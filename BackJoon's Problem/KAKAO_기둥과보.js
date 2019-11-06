class Variable{
  constructor(val){
    this._value = val;
  }
}

class PBV extends Variable{
   constructor(val){
     super(val);
   }
}

const pass_by_value = (variable) => {
  return variable;
};

const pass_by_result = () => {

};

const pass_by_name = () => {

};

const pass_by_reference = () => {

};

const pass_by_value_result = () => {

};

class MyClass{
  constructor(){
    this.value = 10;
  }
};

MyClass.prototype["+"] = function (operand) {
  console.log("HELL",operand);
  return this.value - operand;
};

let a = new MyClass();
let b = new MyClass();
console.log(a+b);
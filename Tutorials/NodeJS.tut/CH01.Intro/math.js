const add = (a, b) => a + b
const subtract = (a, b) => a - b
const multiply = (a, b) => a * b
const divide = (a, b) => a / b

// const add = (a, b) => a + b 
// or 
// exports.add = (a, b) => a + b

module.exports = {add, subtract, multiply, divide}
// not needed when using exports.add = (a, b) => a + b
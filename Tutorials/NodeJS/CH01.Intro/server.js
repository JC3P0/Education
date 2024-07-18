

console.log('Hello World')

// global object
// console.log(global);

// CommonJS modules instead of ES6 modules
const os = require('os')
const path = require('path')


// console.log(os.type())
// console.log(os.version())
// console.log(os.homedir())
// Hello World
// Windows_NT
// Windows 10 Home

// console.log(__dirname)
// console.log(__filename)
// C:\Users\JoshC
// C:\Users\JoshC\Desktop\Dev\Tutorials\Node.js

// console.log(path.dirname(__filename))
// console.log(path.basename(__filename))
// console.log(path.extname(__filename))


// const math = require('./math')
// or
const {add, subtract, multiply, divide} = require('./math')

// console.log(math.add(2,3))
// or
console.log(add(2,3))
console.log(subtract(2,3))
console.log(multiply(2,3))
console.log(divide(2,3))
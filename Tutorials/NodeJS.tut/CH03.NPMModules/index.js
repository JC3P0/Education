const { format } = require('date-fns')
const { v4: uuid } = require('uuid')
// or
// const uuid  = require('uuid')

console.log(format(new Date(), 'yyyyMMdd\tHH:mm:ss'))

// console.log(uuid.v4)
console.log(uuid())
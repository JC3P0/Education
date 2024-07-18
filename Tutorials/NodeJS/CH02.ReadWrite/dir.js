const fs = require('fs')

if(!fs.existsSync('./new')) {
    // mkdir = make directory
    fs.mkdir('./new', (err) => {
        if (err) throw err;
        console.log('Directory created')
    })
}

if(fs.existsSync('./new')) {
    // rmdir = remove directory
    fs.rmdir('./new', (err) => {
        if (err) throw err;
        console.log('Directory removed')
    })
}
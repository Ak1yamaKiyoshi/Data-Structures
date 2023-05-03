
function toCamelCase(str) {
    return str.replace(/([A-Z])/g, g =>'_' + g.toLowerCase()  );
}

console.log(toCamelCase('snakeCase'))

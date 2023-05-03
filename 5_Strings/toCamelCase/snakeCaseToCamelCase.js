
function toCamelCase(str) {
    return str.replace(/_([a-z])/g, g => g[1].toUpperCase());
}

console.log(toCamelCase('snake_case'))
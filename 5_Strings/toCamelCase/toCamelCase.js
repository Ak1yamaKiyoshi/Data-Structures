/* 2. Написати функцію toCamelCase(), яка перетворює назву css-стилів з дефісом у назву в стилі СamelСase,
наприклад: font-size у fontSize, background-color у backgroundColor, text-align у textAlign */
function toCamelCase(str) {
    let index = str.indexOf("-");
    str = str.replace(str.slice(index, index+2), str[index+1].toUpperCase());
    return str;
}

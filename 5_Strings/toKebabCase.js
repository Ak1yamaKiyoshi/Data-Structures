/* 3. Написати функцію toKebabCase(), обернену до toCamelCase(), наприклад: fontSize у font-size, backgroundColor у background-color */
function toKebabCase(str) {
    let upperCase = str.match(/[A-Z]/);
    let index = str.indexOf(upperCase);
    str = str.replace(str[index], "-" + str[index].toLowerCase());
    return str;
}
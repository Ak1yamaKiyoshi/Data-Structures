

// Напишіть функцію, яка приймає два аргументи - ім'я та вік. 
// Функція повинна повернути рядок у форматі 
// "Привіт, мене звати <ім'я> та мені <вік> років.", використовуючи стрілочну функцію.
// ! makes first letter of name uppercase too 
// name.charAt(0).toUpperCase() + name.slice(1)
let greeting = (name, age) => {return `Hello, my name is ${name.charAt(0).toUpperCase() + name.slice(1)}. I'm ${age}.`};
console.log(greeting('someone', 13)); // Hello, my name is Someone. I'm 13.

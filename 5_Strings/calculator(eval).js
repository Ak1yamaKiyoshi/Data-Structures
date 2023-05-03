/* 4. Написати функцію – калькулятор. Функція приймає рядок із прикладом, визначає, яку дію необхідно виконати (+ - * /), 
переводить операнди в числа, вирішує приклад і повертає результат.*/
function calculator(str) {
stack = str.match(/[-+*/]|\d+/g);
operators= str.match(/[/*]/g);
operators = operators.concat(str.match(/[+-]/g));
operators.forEach(o => {
    let i = stack.indexOf(o);
    let op1 = parseInt(stack[i-1]);
    let op2 = parseInt(stack[i+1]);
    stack.splice(i-1, 1); stack.splice(i, 1);
    let result = ((o == '*') ? op1 * op2 : (o == '/') ? op1 / op2 : (o == '+') ? op1 + op2 : op1 - op2);
    stack[i-1] = result;
});
return stack;
}   
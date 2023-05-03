

// Створіть функцію, яка приймає довільну кількість аргументів та виводить їх у консоль. 
// Потім викличте цю функцію, передавши їй кілька аргументів за допомогою spread-оператора.
function printAllParamteres() {
    for (let i = 0; i < arguments.length; i++)
    console.log(arguments[i]); 
} 
printAllParamteres(...[1, 2, ('b'+'a'+ +'a'+'a').toLowerCase()] ) // 1 2 'banana'

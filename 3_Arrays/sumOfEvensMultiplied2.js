// Створіть масив чисел і використовуйте метод filter() та стрілочну функцію, щоб відфільтрувати тільки парні числа. 
// Потім використовуйте метод map() та стрілочну функцію, щоб помножити кожне число на 2. 
// Наприкінці, використовуйте метод reduce() та стрілочну функцію, щоб отримати суму всіх чисел у масиві.
function sumOfEvenNumbersMultipliedByTwo(array) {
    array = array.filter(n => n % 2 == 0); /* filter even number */
    array = array.map(n => n *= 2); /* multiply each by 2 */
    return array.reduce((acc, element) => {return acc + element }); 
}
console.log(sumOfEvenNumbersMultipliedByTwo([1, 2, 3, 4, 5, 6, 7, 8, 10])) // 60

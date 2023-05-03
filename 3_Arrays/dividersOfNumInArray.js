/*приймає на вхід число і масив чисел. Функція повинна виводити в консоль усі числа з масиву, 
    які більші за задане число і діляться на нього без залишку. Якщо таких чисел немає, 
    функція повинна виводити повідомлення "Немає відповідних чисел".
*/
function anyDividersOfNumInArray(array, num) {
    let output = '';
    array.forEach(a => {if (a > num && a % num == 0) output += a + ' ';});
    console.log( (output === '') ? 'no prime numbers in string' : output)
}
//task3([-1, 1, 2, 4, 5, 20], 2)
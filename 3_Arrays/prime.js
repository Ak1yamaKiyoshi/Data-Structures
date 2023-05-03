/* приймає на вхід масив чисел і виводить у консоль тільки ті числа, що є простими і більшими за 5. 
Якщо таких чисел немає, функція повинна виводити повідомлення "Немає відповідних чисел". */
function isPrime(n) {
    if (n <= 1) return false;
    for (let i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}
function task1(array) {
    let output = '';
    array.forEach(a => {if (a >= 5 && isPrime(a)) output += a + ' ';});
    console.log( (output === '') ? 'no prime numbers in string' : output)
}
//task1([1, 2])
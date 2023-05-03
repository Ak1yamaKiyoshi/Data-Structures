
/* Завдання2: Об'єкти (3 завдання)
1. В об’єкті є властивість className, яка містить список «класів» (слів, розділених пробілами):
    let obj = {
    className: 'open menu'
    }
Створіть функцію addClass(obj, cls), яка додає у список класів клас cls, але тільки, якщо його там немає:
    addClass(obj, 'new');   // obj.className='open menu new'
    addClass(obj, 'open');  // без змін (клас вже існує)
    addClass(obj, 'me');    // obj.className='open menu new me'
    alert( obj.className ); // "open menu new me"
Функція addClass не повинна додавати зайвих пробілів.
*/
let task2obj = {
    className:'open menu menu'
}

function task2AddClassName(obj, str) {
    if (obj.className.indexOf(str) == -1) obj.className += ` ${str}`
}
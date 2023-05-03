/*
Об’єкт має властивість className, яка зберігає список «класів» – слів, розділених пробілами:
    let obj = {
    className: 'open menu'
    };
Напишіть функцію removeClass(obj, cls), яка видаляє клас cls, якщо він є:
    removeClass(obj, 'open');   // obj.className='menu'
    removeClass(obj, 'blabla'); // без змін (такого класу немає)
Функція повинна коректно обробляти дублювання класу в рядку:
    obj = {
    className: 'my menu menu'
    };
    removeClass(obj, 'menu');
    alert( obj.className ); // 'my'
Виконайте тестування написаного коду на сайті:

*/
function task2RemoveClassName(obj, str) {
    while (obj.className.indexOf(str) != -1) {
        let cut = [obj.className.replace(`${str} `, ''), obj.className.replace(` ${str}`, ''), obj.className.replace(str, '')];
        obj.className = cut.reduce((a, b) => a.length < b.length ? a : b);
    }
}
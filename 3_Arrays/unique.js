/* task 3 
Нехай arr – масив рядків. Напишіть функцію unique(arr), яка повертає масив, 
який містить тільки унікальні елементи arr. Наприклад:
    function unique(arr) {
        // your code 
    }

    let strings = ["C++", "C#", "C++", "C#",
    "C", "C++", "JavaScript", "C++", "JavaScript"
    ];
alert( unique(strings) ); // C++, C#, C, JavaScript
*/

let strings = ["C++", "C#", "C++", "C#", "C", "C++", "JavaScript", "C++", "JavaScript"];

function unique(array) {
    return Array.from(new Set(array));
}
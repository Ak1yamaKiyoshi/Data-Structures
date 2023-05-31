
const findHex = (str) => {
    return str.match(/#{1}[A-f]{3,6}/g)
}

console.log(findHex('some text with hex #ABCDEF colors like this #fff'))

/*
 Напишіть функцію findHexColor (text), яка знаходить у заданому тексті колір у
форматі #ABC або # ABCDEF. Якщо не знайдено, повернути null. Використати
*/
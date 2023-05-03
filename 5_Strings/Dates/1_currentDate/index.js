const numberToUAMonth = [undefined, 'січня', 'лютого', 'березня', 'квітня', 'травня', 'червня', 'липня', 'серпня','вересеня', 'жовтня', 'листопада', 'грудня'];
const numberToUADay =   [undefined, 'понеділок', 'вівторок', 'середа', 'четвер', 'п`ятниця', 'субота', 'неділя'];

$(document).ready(function() {
    $('#process').click(function() {
        $('#output').text(formattedDate())
    });
});

function formattedDate() {
    const date = new Date;
    return ``
    + `Дата: ${date.getUTCDate() } ${numberToUAMonth[date.getMonth()]} ${date.getFullYear()} року` 
    + `\nДень тижня: ${ numberToUADay[date.getDay()]}`
    + `\nЧас: ${date.getHours()}:${date.getUTCMinutes()}`
}

/*
    написати функцію, яка виводить поточну дату у вигляді:
    Дата: 12 березня 2017 року
    День тижня: неділя
    Час: 15:08
*/
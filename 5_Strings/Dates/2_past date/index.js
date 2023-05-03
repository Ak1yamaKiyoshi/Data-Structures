const numberToUAMonth = [undefined, 'січня', 'лютого', 'березня', 'квітня', 'травня', 'червня', 'липня', 'серпня','вересеня', 'жовтня', 'листопада', 'грудня'];
const numberToUADay =   [undefined, 'понеділок', 'вівторок', 'середа', 'четвер', 'п`ятниця', 'субота', 'неділя'];

$(document).ready(function() {
    $('#process').click(function() {
        $('#output').text(
            pastDateToWords(
            $('#input')
            .val() // get value from input 
            .match(/\d{2}.\d{2}.\d{4}/g)[0] // verify date to prevent errors  
            .match(/[0-9]{2,4}/g) // parse into function array with day, month and year
            )
        );

    });
});

function pastDateToWords(date) {
    /* calculate difference in days: milisecond / 1000 ( seconds ) / 60 ( minutes ) / 60 ( hours ) / 24 ( days )  */
    /* Month counts from 0 to 11, so we need to decrement value: String(+date[1]-1).padStart(2, '0') */
    /* date[2] - year; date[1] - month; date[0] - day */
    const diffInDays = ((new Date) - (new Date(date[2], String(+date[1]-1).padStart(2, '0'), date[0]))) / 86400000 
    console.log(diffInDays)
    switch(true) {  
        case ( diffInDays < 0 ):  output = 'У майбутньому'; break;
        case ( diffInDays < 1 ):   output = 'Сьогодні'; break;
        case ( diffInDays < 2 ):   output = 'Вчора'; break;
        case ( diffInDays < 6 ):   output = `${Math.floor(diffInDays)} днів тому.`; break;
        case ( diffInDays < 8 ):   output = 'Тиждень тому'; break;
        case ( diffInDays < 366 ): output = 'Рік тому'; break;
        default:                   output = `${date[2]} ${date[1]} ${date[0]}`; break;
    }
    return output;
}

/*
    Користувач вводить дату у форматі (дд.мм.рррр або дд/мм/рррр або
    дд-мм-рррр). Опублікувати цю дату у наступному вигляді:
        ● Якщо дата сьогоднішня - вивести Сьогодні
        ● Якщо вчорашня - Вчора,
        ● Якщо пройшло 2-6 днів, вивести:
    2 дні тому, 3 дні тому,... 6 днів тому
        ● Якщо пройшло 7 днів - Тиждень тому
        ● Якщо пройшов рік - Рік тому
        ● В інших випадках - вивести дату у форматі РРРР.ММ.ДД
*/
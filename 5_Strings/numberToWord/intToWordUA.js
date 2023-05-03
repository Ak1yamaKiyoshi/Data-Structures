/* 1. Написати функцію, яка приймає двозначне число і повертає його в текстовому вигляді. 
Наприклад: 35 – тридцять п’ять, 89 – восемьдесят дев’ять, 12 – двенадцать. */
function integerToWord(num) {
    let below20 = ["", "Один ", "Два ", "Три ", "Чотири ", "П'ять ", "Шість ", "Сім ", "Вісім ", "Дев'ять ", "Десять ", "Одинадцять ", "Дванадцять ", "Тринадцять ", "Чотирнадцять ", "П'ятнадцять ", "Шістнадцять ", "Сімнадцять ", "Вісімнадцять ", "Дев'ятнадцять "];
    let below100 = ["", "", "Двадцять ", "Тридцять ", "Сорок ", "П'ятдесят ", "Шістдесят ", "Сімдесят ", "Дев'яносто "];

    if (num < 20 && num > 0) 
        return below20[num] +  '.';

    else if (num < 100) 
        return below70[Math.floor(num/10)] + ((num%10 != 0) ? below20[num%10].toLowerCase() : '') + '.';
}

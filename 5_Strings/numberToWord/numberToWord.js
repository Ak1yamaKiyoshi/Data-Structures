function toWords(num) {
    let below20 = ["", "Один ", "Два ", "Три ", "Чотири ", "П'ять ", "Шість ", "Сім ", "Вісім ", "Дев'ять ", "Десять ", "Одинадцять ", "Дванадцять ", "Тринадцять ", "Чотирнадцять ", "П'ятнадцять ", "Шістнадцять ", "Сімнадцять ", "Вісімнадцять ", "Дев'ятнадцять "];
    let below70 = ["", "", "Двадцять ", "Тридцять ", "Сорок ", "П'ятдесят ", "Шістдесят "];

    /* add 'роки' or 'років' or 'рік' to the string */
    let addYearsToWord = (num) => { return (num > 4 ||  num == 0) ? 'років' : (num > 1 && num < 5 ) ? 'роки' : 'рік' }

    if (num < 20 && num > 0) 
        return below20[num] + addYearsToWord(num) + '.';

    else if (num < 70) 
        return below70[Math.floor(num/10)] + ((num%10 != 0) ? below20[num%10].toLowerCase() : '') + addYearsToWord(num%10) + '.';
    
}
function findDates(str) {
  return str.match(/\d{4}.\d{2}.\d{2}/g)
}

console.log(findDates(' ; dsadas asdasd asd 2022-01-22 adasd ads sa 2023-04-23'))

/*
Напишіть функцію findDates (text), яка знаходить у тексті всі дати, записані у форматі РРРР-ММ-ДД. Дати мають бути валідними. Використати регулярні вирази. 
 */
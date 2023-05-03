

// Створіть об'єкт Map, у якому ключами будуть імена країн, а значеннями - їхні столиці. 
// Заповніть цей об'єкт кількома парами ключ-значення і виведіть їх у консоль.
let countries = new Map; 
countries.set('Ukraine', 'Kiyv');
countries.set('England', 'London');
countries.set('France', 'Paris');
for (let country of countries) 
    console.log(`${country[0]}: ${country[1]}`) // 'Ukraine: Kiyv' 'England: London' 'France: Paris'
/*
За допомогою конструктора об'єктів створити 3 об'єкти, які будуть містити такі поля:
    1) Кличку собаки
    2) Породу
    3) Bік
Створити метод, за допомогою якого собаки будуть говорити:
    1) Тяф - якщо вік собаки менше року
    2) Гав - якщо вік собаки від року до 3
    3) Ррр-якщо вік собаки більше 3 років
    Продемонструвати роботу метода
*/
dogs = [
    {name:'dog',breed:'akita inu', age:'4'},
    {name:'dog',breed:'akita inu', age:'2'},
    {name:'dog',breed:'akita inu', age:'0.5'},     
]

function dogMakeSound(dog) {
    return((dog.age < 1) ? 'tyaf' : (dog.age < 3) ? 'gav' : 'grr');
}
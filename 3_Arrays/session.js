/*
Створити масив «Сесія». Кожен елемент масиву є об’єктом, 
який містить назву дисципліни, кількість балів, що набрав студент, та зараховано або незараховано.
Створити функції для роботи з таким масивом:
1)      Функція виведення списку дисциплін, в якому спочатку відображуються дисципліни, що зараховані, а потім – незараховані
2)      Додавання дисципліни в список – функція приймає назву дисципліни. 
При цьому потрібно враховувати, що якщо дисципліна вже ї в списку, 
то потрібно додавати лише кількість балів з цієї дисципліни. 
Якщо кількість балів більше або дорівнює 60, 
то потрібно відмічати цю дисципліну як зараховану
3)      Функція знаходження середнього балу з усіх дисциплін
4)      Функція знаходження кількості незарахованих дисциплін
5)      Функція, що знаходить з якої дисципліни найвищий бал
6)      Функція, що приймає кількість балів і виводить всі дисципліни, що здані на таку кількість балів
*/
let session = [
    {subject:'Math',grade:15,notPassed:true},
    {subject:'CS',grade:155,notPassed:false}, 
    {subject:'PE',grade:-20,notPassed:true}
];

function sessionDisplay(session) {
    return [null, ...session].reduce((acc, subject) => {
        return ((typeof(acc)==='string') ? acc : '') + `\nsubject: ${subject.subject}\ngrade: ${subject.grade}\nnotPassed: ${subject.notPassed}`
    });
}

function sessionAddSubject(session, subject, grade ) {
    let obj = session.find(e => e.subject === subject);
    if (!obj) session.push({subject:subject,grade:grade,notPassed:(grade < 60)});
    else session[session.indexOf(obj)] = {subject:subject, grade:grade, notPassed:(grade < 60)};
}

function sessionAverage(session) {
    return [null, ...session].reduce((acc, subject) => {return acc + subject.grade;}) / session.length;
}

function sessionCountNotPassed(session) {
    return [null, ...session].reduce((acc, subject) => {return acc + Number(subject.notPassed);});
}

function sessionMaxGrade(session) {
    return [null, ...session].reduce((acc, subject) => {return Math.max(acc, subject.grade);});
}

function sessionDisplayByGrade(session, grade) {
    let obj = session.filter(s => s.grade == grade);
    return sessionDisplay(obj);
}

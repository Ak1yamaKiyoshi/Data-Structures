const avl = require ("./avl tree");

let tree = new avl.AVL
let array = [50, 1, 60, 23, 23, 15, 235, 12, 5];
array.forEach(element => {
    tree.insert(element);
});

console.log(tree.print());
console.log("lenght: ", tree.lenght() == array.length);
console.log("height: ", tree.height());
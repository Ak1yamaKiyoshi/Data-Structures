const bst = require("./binary tree");

let tree = new bst.BST()
let array = [5, 10, 0, 20, 7, 5, 4, 6, 7, 5.5];//[5, 4, 6, 7, 5.5];
array.forEach(element => {
    tree.insert(element);
    console.log(tree.height(tree.binarySearch(element)))
});
tree.balanceTree();
tree.balanceTree();

console.log(tree.print());
tree.rotateLeft(tree.binarySearch(5))

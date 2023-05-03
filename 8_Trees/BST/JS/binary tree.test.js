const bst = require("./binary tree");

test("Node Tests", () => {
    let node = new bst.Node(5, null);
    expect(node.value).toEqual(5);

    node.left = new bst.Node(4, node);
    expect(node.left.value).toEqual(4);
    
    node.right = new bst.Node(6, node);
    expect(node.right.value).toEqual(6);
    
    node.right.right = new bst.Node(7, node.right);
    expect(node.right.right.value).toEqual(7);
    expect(node.right.right.parent.value).toEqual(6);
});

test("Insert Tests", () => {
    let tree = new bst.BST();
    let node = new bst.Node(5, undefined);
    tree.insert(5);
    expect(node.value).toEqual(5);
    expect(node).toEqual(tree.binarySearch(5));
    
    node.left = new bst.Node(4, node);
    tree.insert(4);
    expect(node.left.value).toEqual(4);
    expect(node).toEqual(tree.binarySearch(5));

    node.right = new bst.Node(6, node);
    tree.insert(6);
    expect(node.right.value).toEqual(6);
    expect(node).toEqual(tree.binarySearch(5));

    node.right.right = new bst.Node(7, node.right);
    tree.insert(7);
    expect(node.right.right.value).toEqual(7);
    expect(node).toEqual(tree.binarySearch(5));
    expect(node.right.right.parent.value).toEqual(6);
    expect(node).toEqual(tree.binarySearch(5));
});

test("binary Search Tests", () => {
    let tree = new bst.BST();
    tree.insert(5);
    expect(tree.binarySearch(5).value).toEqual(5);
    tree.insert(4);
    expect(tree.binarySearch(4).value).toEqual(4);
    tree.insert(6);
    expect(tree.binarySearch(6).value).toEqual(6);
    tree.insert(7);
    expect(tree.binarySearch(7).value).toEqual(7);
    
    expect(tree.binarySearch(5).left.value).toEqual(4);
    expect(tree.binarySearch(5).right.value).toEqual(6);
    expect(tree.binarySearch(6).right.value).toEqual(7);
    expect(tree.binarySearch(6).left).toEqual(undefined);
    
    tree.insert(7.5);
    tree.insert(6.5);
    expect(tree.binarySearch(7).right.value).toEqual(7.5);
    expect(tree.binarySearch(7).left.value).toEqual(6.5);

    tree = new bst.BST();
    expect(tree.binarySearch(1)).toEqual(undefined);
});

test("Remove Tests", () => {
    let tree;
    

    // one child case right
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(6); // right child
    tree.insert(7); // right child of right child 
    tree.remove(6); // tree contains: 5, 7
    expect(tree.binarySearch(6)).toEqual(undefined);
    expect(tree.binarySearch(5).right.value).toEqual(7);
    
    
    // one child case left
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(4); // left child
    tree.insert(3); // left child of left child
    tree.remove(4); 
    expect(tree.binarySearch(4)).toEqual(undefined);
    expect(tree.binarySearch(5).left.value).toEqual(3);

    // one child root right case 
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(6); // right child
    tree.remove(5); 
    expect(tree.binarySearch(5)).toEqual(undefined);
    expect(tree.binarySearch(6).value).toEqual(6);
    expect(tree.binarySearch(6).right).toEqual(undefined);
    expect(tree.binarySearch(6).left).toEqual(undefined);

    // one child root right case 
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(4); // right child
    tree.remove(5); 
    expect(tree.binarySearch(5)).toEqual(undefined);
    expect(tree.binarySearch(4).value).toEqual(4);
    expect(tree.binarySearch(4).right).toEqual(undefined);
    expect(tree.binarySearch(4).left).toEqual(undefined);
    
    // leaf node case right and left
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(7); // right 
    tree.insert(3); // left
    tree.remove(3); // del left 
    tree.remove(7); // del right
    expect(tree.binarySearch(3)).toEqual(undefined);
    expect(tree.binarySearch(7)).toEqual(undefined);
    expect(tree.binarySearch(5).left).toEqual(undefined);
    expect(tree.binarySearch(5).right).toEqual(undefined);
    expect(tree.binarySearch(5).value).toEqual(5);


    // both childs case (not root)
    tree = new bst.BST();
    tree.insert(5);  // root
    tree.insert(10); // right child
    tree.insert(6);  // left child of right child of root
    tree.insert(11); // right child of right child of root
    tree.remove(10); 
    expect(tree.binarySearch(5).right.value).toEqual(11);
    expect(tree.binarySearch(11).left.value).toEqual(6);
    expect(tree.binarySearch(10)).toEqual(undefined);
    /*
    ______>_______
             [11]
        [10]<
             [6]
    [5]<
    ______>_______
        [11]<
             [6]
    [5]<
    */


    // both childs at root
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(4); // left child
    tree.insert(6); // left child 
    tree.remove(5);
    expect(tree.binarySearch(5)).toEqual(undefined);
    expect(tree.binarySearch(6).right).toEqual(undefined);
    expect(tree.binarySearch(6).left.value).toEqual(4);


    // both childs when there is subtree at right child
    tree = new bst.BST();
    tree.insert(5); // root
    tree.insert(4); // left child
    tree.insert(6); // right child 
    tree.insert(10); // root.right.right
    tree.insert(5.5); // root.right.left
    tree.remove(6);
    expect(tree.binarySearch(5).value).toEqual(5);
    expect(tree.binarySearch(6)).toEqual(undefined);

    expect(tree.binarySearch(5).right.value).toEqual(10);
    expect(tree.binarySearch(5).left.value).toEqual(4);

    expect(tree.binarySearch(5.5).right).toEqual(undefined);
    expect(tree.binarySearch(5.5).left).toEqual(undefined);

    expect(tree.binarySearch(10).left.value).toEqual(5.5);
    expect(tree.binarySearch(10).right).toEqual(undefined);
    /*
    ______>_______
            [10]
        [6]<
            [5.5]
    [5]<
        [4]<
    ______>_______
        [10]<
            [5.5]<
    [5]<
        [4]<
    */

    // both childs when there is subtree at left child
    tree = new bst.BST();
    tree.insert(10);// root
    tree.insert(5); // root.left
    tree.insert(2); // root.left.left
    tree.insert(4); // root.left.left.right
    tree.insert(6)  // root.left.right
    tree.remove(5);
    expect(tree.binarySearch(5)).toEqual(undefined);
    expect(tree.binarySearch(6).right).toEqual(undefined);
    expect(tree.binarySearch(6).left.value).toEqual(2);
    /*
    ______>_______
    [10]<    [6]
         [5]<
             [2]<
                 [4]
    ______>_______
    [10]<    
         [6]<
             [2]<
                 [4]
    */


    // both childs when there is subtree at parent.right.right 
    tree = new bst.BST();
    tree.insert(10); // root
    tree.insert(5);  // root.left
    tree.insert(2);  // root.left.left
    tree.insert(4);  // root.left.left.right
    tree.insert(6)   // root.left.right
    tree.insert(7);  // root.left.right.right
    tree.insert(5.5);// root.left.right.left
    tree.remove(5);
    expect(tree.binarySearch(5)).toEqual(undefined);
    expect(tree.binarySearch(5.5).right.value).toEqual(6);
    expect(tree.binarySearch(5.5).left.value).toEqual(2);
    expect(tree.binarySearch(6).right.value).toEqual(7);
    expect(tree.binarySearch(6).left).toEqual(undefined);
    /*
    ______>_______
    [10]<
                   [7]    
              [6]<
                  [5.5]
         [5]<
             [2]<
                 [4]
    ______>_______
    [10]<
                   [7]    
              [6]<
         [5.5]<
             [2]<
                 [4]
    */
    
    // remove, when tree does not contain any elements
    tree = new bst.BST()
    expect(tree.remove(1)).toEqual(undefined);
});

test("Print Tests", () => {
    let tree = new bst.BST
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    expect(tree.depthFirst()).toEqual("2 6 4");


    tree = new bst.BST
    let array = [1, 5, 2, 7, 9, 1, 123, 53];
            //   1  5  2  7  9  1  123  53
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.depthFirst()).toEqual("1 2 53 123 9 7 5 1");



    tree = new bst.BST
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    expect(tree.print()).toEqual("     [6]<\n[4]<\n     [2]<\n");
})

test("In, Pre, Post order search Tests", () => {
    let tree = new bst.BST();
    tree.insert(10);    tree.insert(6);    tree.insert(11);
    // pre order
    expect(tree.preOrderSearch(6).value).toEqual(6)
    expect(tree.preOrderSearch(10).left.value).toEqual(6)
    expect(tree.preOrderSearch(10).value).toEqual(10)
    expect(tree.preOrderSearch(10).right.value).toEqual(11)
    expect(tree.preOrderSearch(11).value).toEqual(11)
    expect(tree.preOrderSearch(101111)).toEqual(undefined)
    // post order
    expect(tree.postOrderSearch(6).value).toEqual(6)
    expect(tree.postOrderSearch(10).left.value).toEqual(6)
    expect(tree.postOrderSearch(10).value).toEqual(10)
    expect(tree.postOrderSearch(10).right.value).toEqual(11)
    expect(tree.postOrderSearch(11).value).toEqual(11)
    expect(tree.postOrderSearch(101111)).toEqual(undefined)
    // in order
    expect(tree.inOrderSearch(6).value).toEqual(6)
    expect(tree.inOrderSearch(10).left.value).toEqual(6)
    expect(tree.inOrderSearch(10).value).toEqual(10)
    expect(tree.inOrderSearch(10).right.value).toEqual(11)
    expect(tree.inOrderSearch(11).value).toEqual(11)
    expect(tree.inOrderSearch(101111)).toEqual(undefined)
});

test("Height Tests", () => {
    let tree = new bst.BST();    
    let array = [10, 11, 12, 13];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.height()).toEqual(4);

    tree = new bst.BST();    
    array = [10, 4, 5, 3, 2];
    array.forEach(element => {
        tree.insert(element);
    });
    /*
    10 <
            5
        4 <
            3
                <2
    */
    expect(tree.height()).toEqual(4);

    tree = new bst.BST();    
    array = [10, 9, 8, 7];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.height()).toEqual(4);
});

test("Lenght Tests", () => {
    let tree = new bst.BST()
    let array = [10, 11, 12, 13];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.lenght()).toEqual(4);


    tree = new bst.BST()
    array = [10, 11, 12, 13, 1];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.lenght()).toEqual(5);


    tree = new bst.BST()
    array = [1];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.lenght()).toEqual(1);


    tree = new bst.BST()
    array = [13, 1];
    array.forEach(element => {
        tree.insert(element);
    });
    expect(tree.lenght()).toEqual(2);
});

class Node {
    constructor (value, parent) {
        this.parent = parent;
        this.value = value;
        this.left;
        this.right;
    }
}

class BST {
    constructor() {
        this.root = undefined;
    }    

    /*
     * Inserts node in tree
     * Creates new node with given value and links this node after respective child or on root node
     * Values in tree must be inserted only this way, otherwise search, remove, insert would not work
     * @param {value} value to insert
     * return {void}
    */
    insert(value) {
        if (!this.root) {this.root = new Node(value, undefined); return;}

        let ptr = this.root;
        while (true) 
            if (value < ptr.value && ptr.left) ptr = ptr.left;
            else if (value >= ptr.value && ptr.right) ptr = ptr.right;
            else break;
        
        if (ptr.value > value) ptr.left = new Node(value, ptr);
        else ptr.right = new Node(value, ptr);    
    }

    /*
     * Searches node with exact value {value}
     * used by remove
     * @param {value} value to search 
     * returns pointer to node with value == given value
    */
    binarySearch(value, toAdd=0, returnLast=false) {
        if (this.root) var ptr = this.root; 
        else return;

        if (ptr.value == value) return this.root;
        while (true) {
            ptr._height += toAdd;
            if (ptr.value>value && ptr.left) ptr = ptr.left;
            else if (ptr.value<value && ptr.right) ptr = ptr.right;
            else {
                if (ptr.value == value) return ptr;
                else {
                    if (!returnLast) return undefined;
                    else return ptr;
                }
            }
        }
    }

    /*
     * Removes node with exact value
     * @param {value} value to search
    */
    /*
    * Removes node with exact value
    * @param {value} value to search
    */
    remove(value) {
        var ptr = this.binarySearch(value, -1);
        if (!ptr) return;
        
        if (ptr.left && ptr.right) {// Both childs
            let pointer = ptr.right; // check right subtree
            while (pointer.left) pointer = pointer.left; // find smallest in right subtree
            ptr.value = pointer.value; // reassign smallest value to current node
            // delete previous node with smallest value in right subtree of current node
            pointer.parent[(pointer.parent.left==pointer)?"left":"right"] = undefined;
        }
        else if (ptr.left || ptr.right) { // One child
            let atr = (ptr.right) ? "right" : "left";
            if (ptr == this.root) this.root = this.root[atr] // if ptr is root, root = root[atr]
            else {
                ptr.parent[(ptr == ptr.parent.right) ? "right" : "left"] = ptr[atr] // parent.ptr = ptr.avaivable node
                ptr[atr].parent = ptr.parent
            } 
        }
        else // Leaf Node
            ptr.parent[(ptr == ptr.parent.right) ? "right" : "left"] = undefined; // remove link to leaf node 
    }

    
    // returns height of binary tree 
    height(pointer=undefined) {
        function hght(pointer, height) {
            if (!pointer) return height;
            let left = hght(pointer.left, height+1);
            let right = hght(pointer.right, height+1);
            return (left > right ? left : right);
        }
        return hght(this.root, 0);
    }

    /*
     * Searches node with exact value {value}
     * traverse starts from top of the tree 
     * @param {value} value to search
     * returns pointer to node with value == given value
    */
    preOrderSearch(value) {
        function search(value, pointer) {
            if (pointer) {
                if (pointer.value == value) return pointer;
                let buffer = search(value, pointer.left);
                if (buffer) return buffer;
                buffer = search(value, pointer.right);
                if (buffer) return buffer;
            }
        }
        return search(value, this.root);
    }

    /*
     * Searches node with exact value {value}
     * traverse starts from very bottom of the tree 
     * @param {value} value to search
     * returns pointer to node with value == given value
    */
    postOrderSearch(value) {
        function search(value, pointer) {
            if (pointer) {
                let buffer = search(value, pointer.left);
                if (buffer) return buffer;
                buffer = search(value, pointer.right);
                if (buffer) return buffer;
                if (pointer.value == value) return pointer;
            }
        }
        return search(value, this.root);
    }

    /*
     * Searches node with exact value {value}
     * traverse starts from left bottom of the tree
     * @param {value} value to search
     * returns pointer to node with value == given value
    */
    inOrderSearch(value) {
        function search(value, pointer) {
            if (pointer) {
                let buffer = search(value, pointer.left);
                if (buffer) return buffer;
                buffer = search(value, pointer.right);
                if (buffer) return buffer;
                if (pointer.value == value) return pointer;
            }
        }
        return search(value, this.root);
    }

    /* Post Order Traverse
     * traverse from bottom of tree
     * returns string with all elements of tree 
    */
    depthFirst() { // post order traversal
        function display(ptr) {
            if (ptr) {
                let out = "";
                let buffer;
                buffer = display(ptr.left);
                if (buffer) out += buffer + " ";
                buffer = display(ptr.right);
                if (buffer) out += buffer + " "; 
                return out + ptr.value;
            }
        }
        return display(this.root);
    }

    /* In Order Traverse
     * traverse from root of tree to bottom
     * returns string with all elements of tree in tree-like look 
    */
    print() {
        function display(pointer, space, level) {
            if (!pointer) return "";
            let out=""
            space += level;
            out += display(pointer.right, space, level);
            for (let i = level; i < space; i++) out+=" ";
            out += "[" + pointer.value.toString()+ "]<\n";
            out += display(pointer.left, space, level);
            return out;
        }
        return display(this.root, 0, 5);
    }

    // returns lenght of the tree
    lenght() { // post order traversal
        function len(ptr) {
            let out = 0;
            if (ptr) {
                out += len(ptr.left);
                out += len(ptr.right);
                return out + 1;
            }
            return out;
        }
        return len(this.root);
    }
}


exports.BST = BST
exports.Node = Node

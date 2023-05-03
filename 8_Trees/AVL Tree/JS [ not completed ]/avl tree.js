class Node {
    constructor (value, parent) {
        this.parent = parent;
        this.value = value;
        this.left;
        this.right;
    }
}

class AVL {
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
        this.balance(ptr);
    }

    /*
     * Searches node with exact value {value}
     * used by remove
     * @param {value} value to search 
     * returns pointer to node with value == given value 
    */
    binarySearch(value) {
        if (this.root) var ptr = this.root; 
        else return;

        if (ptr.value == value) return this.root;
        while (true) 
            if (ptr.value>value && ptr.left) ptr = ptr.left;
            else if (ptr.value<value && ptr.right) ptr = ptr.right;
            else if (ptr.value == value) return ptr;
            else break;
    }
    /*
    * Removes node with exact value
    * @param {value} value to search
    */
    remove(value) {
        var ptr = this.binarySearch(value);
        if (!ptr) return;
        let parentCheck = (r) => {return (r == r.parent.right) ? "right" : "left"};
        
        if (ptr.left && ptr.right) {// Both childs
            let pointer = ptr.right; // check right subtree
            while (pointer.left) pointer = pointer.left; // find smallest in right subtree
            ptr.value = pointer.value; // reassign smallest value to current node
            // delete previous node with smallest value in right subtree of current node
            pointer.parent[parentCheck(pointer)] = undefined;
        }
        else if (ptr.left || ptr.right) { // One child
            let atr = (ptr.right) ? "right" : "left";
            if (ptr == this.root) this.root = this.root[atr] // if ptr is root, root = root[atr]
            else {
                ptr.parent[parentCheck(ptr)] = ptr[atr] // parent.ptr = ptr.avaivable node
                ptr[atr].parent = ptr.parent
            }
        }
        else // Leaf Node
            ptr.parent[parentCheck(ptr)] = undefined; // remove link to leaf node 
    }
    
    height(pointer=undefined) {
        function hght(pointer, height) {
            if (!pointer) return height;
            let left = hght(pointer.left, height+1);
            let right = hght(pointer.right, height+1);
            return  Math.max(left, right);
        }
        if (!pointer) pointer = this.root;
        let h =  hght(pointer, 0);
        if (!h) return 0;
        else return h;
    }

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

    rotateLeft(root) {
        if (!root) return;
        this.rotate(root, "left", "right")
    }

    rotateRight(root) {
        if (!root) return;
        this.rotate(root, "right", "left")
    }   

    rotate(root, arg, argr) {
        let pivot = root[argr];
        if (!pivot) return;
        root[argr] = pivot[arg];
        if (pivot[arg]) 
            pivot[arg].parent = root;
        pivot.parent = root.parent;
        if (!root.parent) this.root = pivot;
        else if (root == root.parent[arg]) root.parent[arg] = pivot;
        else root.parent[argr] = pivot;
        pivot[arg] = root;
        root.parent = pivot;
    }


    /*
     * TODO: FIX     
    */
    /*
    balance(ptr) {
        // Calculates balance factor (root right height - root left height)
        // return: >1 right imbalance;  <-1 left imbalance
        let balanceFactor = (root) => {
            if (!root) return 0;
            if (!root.right && !root.left) return 0;
            if (!root.right) return this.height(root.left);
            if (!root.left) return this.height(root.right);
            return this.height(root.right) - this.height(root.left);
        };
        
        if (balanceFactor(ptr) > 1) {
            // If there is an imbalance in the right child's right sub-tree, perform a left rotation
            if (balanceFactor(ptr.right) > 1) this.rotateLeft(ptr);
            else  { // If there is an imbalance in the right child's left sub-tree, perform a right-left rotation
                this.rotateRight(ptr);
                this.rotateLeft(ptr);
            }
        }
        if (balanceFactor(ptr) < -1) {
            // If there is an imbalance in the left child's left sub-tree, perform a right rotation
            if (balanceFactor(ptr.left) < -1) this.rotateRight(ptr)
            else { // If there is an imbalance in the left child's right sub-tree, perform a left-right rotation 
                this.rotateLeft(ptr);
                this.rotateRight(ptr);
            }
        }
    }
    */
    balance(r) {
        // Calculates balance factor (root right height - root left height)
        // return: >1 right imbalance;  <-1 left imbalance
        let balanceFactor = (root) => {
            if (!root) return 0;
            if (!root.right && !root.left) return 0;
            if (!root.right) return -2;
            if (!root.left) return 2;
            return this.height(root.right) - this.height(root.left);
        };
        var t = this;
        function balanceTree(ptr) {
                if (!ptr) return; 
                if (balanceFactor(ptr) > 1) {
                    // If there is an imbalance in the right child's right sub-tree, perform a left rotation
                    if (balanceFactor(ptr.right) > 1) t.rotateLeft(ptr);
                    else  { // If there is an imbalance in the right child's left sub-tree, perform a right-left rotation
                        t.rotateRight(ptr);
                        t.rotateLeft(ptr);
                    }
                }
            if (balanceFactor(ptr) < -1) {
                // If there is an imbalance in the left child's left sub-tree, perform a right rotation
                if (balanceFactor(ptr.left) < -1) t.rotateRight(ptr)
                else { // If there is an imbalance in the left child's right sub-tree, perform a left-right rotation 
                    t.rotateLeft(ptr);
                    t.rotateRight(ptr);
                }
            }
            balanceTree(ptr.parent);
        }
        balanceTree(r);

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
            out += "" + pointer.value.toString()+ "<\n";
            out += display(pointer.left, space, level);
            return out;
        }
        return display(this.root, 0, 4);
    }
}

exports.AVL = AVL
exports.Node = Node

class nNode {
    constructor (value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = new nNode;
    }

    
    append(value) {
        if (this.head) {
            let tmp = this.head;
            while (tmp.next) tmp = tmp.next;
            tmp.next = new nNode(value);
        }
        else this.head = new nNode(value)
    }


    print() {
        let tmp = this.head;
        while (tmp) {
            tmp = tmp.next;
            console.log(tmp.value);
        }
    }
    
}

let list = new LinkedList;
list.append(1)
list.append(12)
list.print();

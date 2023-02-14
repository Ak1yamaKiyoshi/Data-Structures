#include <iostream>


// search by index
// search first by value, or next 
// merge two lists (append at the end)


class LinkedList
{
private:
    // structure to perform list node
    struct _Node {
        int value;           // element value
        struct _Node* next;  // next element pointer
    };
public:
    _Node* tail=NULL;
    void append(int value);
    void insert(int before, int value);
    void removeLast(int value);
    void del(int index);
    int length();
    void print(); 
    int search(int index);
};

// TODO: do for next
// adds new element to the end of the list
void LinkedList::append(int value) {
}

// TODO: do for next
// adds new element before the element with `before` index
void LinkedList::insert(int before, int value) {
    int len = this->length();
    if (before > -1 && before < len) {
        _Node* tmp = tail;
        if (!len) append(value);
        else {
            for (int i=len-1; i > before; i--, tmp=tmp->next);
            _Node* newNode = new _Node;
            newNode->value = value;
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
}

// TODO: do for next
// removes last founded element with specified value
void LinkedList::removeLast(int value)
{
    _Node* tmp = tail;
    _Node* tmp2 = tail;
    if (tail != NULL) {
        while (tmp != NULL && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp2->next = tmp->next;
            delete tmp;
        }
    }
}

// TODO: do for next
// Delete element by index
void LinkedList::del(int index) {
    int len = this->length();
    if (len == 1 && index == 0) {
        delete tail;
        tail = NULL;
    }
    if (index > -1 && index < len) {
        _Node *tmp, *tmp2;
        int i;
        for (tmp=tail, i=len-1; i>index+1; i--, tmp=tmp->next);
        tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp2;
    }
}


int LinkedList::search(int index) {
    int len = this->length();
    if (len == 1 && index == 0) 
        return tail->value;
    if (index > -1 && index < len) {
        _Node *tmp;
        int i;
        for (tmp = tail, i = 0; i < index; i++, tmp=tmp->next);
        return tmp->value;
    } 
}


int LinkedList::length() {
    int counter = 0;
    if (tail != NULL) {
        _Node* tmp = tail;
        for (; tmp != NULL; counter++, tmp=tmp->next);
    }
    return counter;
}

// TODO: do for next
void LinkedList::print() {
    _Node*tmp = tail;
    while(tmp != NULL) {
        std::cout << " " << tmp->value;
        tmp = tmp->next;
    }
}

// TODO: overload +, >>, <<, [],


int main() {

    LinkedList list;
    list.append(4);
    list.append(6);
    list.append(1);
    list.print();
    std::cout << "\n search(0) - " << list.search(0);

    return 0;
}
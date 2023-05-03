#include <iostream>


using namespace std;

class LinkedList
{
private:
    // structure to perform list node
    struct _Node {
        int value;           // element value
        struct _Node* prev;  // previous element pointer
    }; // global list variable
public:
    //LinkedList() {
    //}
    _Node* tail=NULL;

    // adds new element to the end of the list
    void append(int value) 
    {
        _Node* newNode = new _Node;
        newNode->prev = tail;
        newNode->value = value;
        tail = newNode;
    }

// adds new element before the element with `before` index
void insert(int before, int value)
{
    int len = this->length();
    if (before > -1 && before < len) {
        _Node* tmp = tail;
        if (!len) append(value);
        else {
            for (int i=len-1; i > before; i--, tmp=tmp->prev);
            _Node* newNode = new _Node;
            newNode->value = value;
            newNode->prev = tmp->prev;
            tmp->prev = newNode;
        }
    }
}

// removes last founded element with specified value
void removeLast(int value)
{
    _Node* tmp = tail;
    _Node* tmp2 = tail;
    if (tail != NULL) {
        while (tmp != NULL && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->prev;
        }
        if (tmp != NULL) {
            tmp2->prev = tmp->prev;
            delete tmp;
        }
    }
}

    void del(int index) {
        int len = this->length();
        if (len == 1 && index == 0) {
            delete tail;
            tail = NULL;
        }
        if (index > -1 && index < len) {
            _Node *tmp, *tmp2;
            int i;
            for (tmp=tail, i=len-1; i>index+1; i--, tmp=tmp->prev);
            tmp2 = tmp->prev;
            tmp->prev = tmp->prev->prev;
            delete tmp2;
        }
    }


    int length() 
    {
        int counter = 0;
        if (tail != NULL) {
            _Node* tmp = tail;
            for (; tmp != NULL; counter++, tmp=tmp->prev);
        }
        return counter;
    }
     
    void print() 
    {
        _Node*tmp = tail;
        while(tmp != NULL) {
            cout << " " << tmp->value;
            tmp = tmp->prev;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    //cout << "___" << endl;
    
    cout << " *append 1,2,3*" << endl;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    cout << " *print list* : ";
    ll.print();
    cout << endl << " *len: " << ll.length() << "*";
    ll.insert(1, 33);
    cout << endl << " *inserted 33 in the end*";
    cout << " *print list* : ";
    ll.print();
    cout << endl <<" *remove by value 33* ";
    ll.removeLast(33); 
    cout << endl << " *print list* : ";
    ll.print();
    cout << endl << " *del 0 element*"; 
    ll.del(0);
    cout << endl << " *print list* : ";
    ll.print();

    

    return 0;
}

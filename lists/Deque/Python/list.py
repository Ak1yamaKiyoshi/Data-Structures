from node import Node

class Deque:
    def __init__(self):
        self.__pointer = None
        self.__count = 0

    def push_back(self, value):
        if self.__pointer is None:
            self.__pointer = Node(value)
        else:
            self.move_last()
            new_node = Node(value, prev=self.__pointer)
            self.__pointer.next = new_node
            self.__pointer = new_node
        self.__count += 1

    def push_front(self, value):
        if self.__pointer is None:
            self.__pointer = Node(value)
        else:
            self.move_first()
            new_node = Node(value, next=self.__pointer)
            self.__pointer.prev = new_node
            self.__pointer = new_node
        self.__count += 1

    def move_last(self):
        while self.__pointer.next is not None:
            self.__pointer = self.__pointer.next

    def move_first(self):
        while self.__pointer.prev is not None:
            self.__pointer = self.__pointer.prev
            
    def pop_last(self):
        self.move_last()
        out = self.__pointer.value
        self.__pointer.prev.next = None
        self.__pointer = self.__pointer.prev
        self.__count -= 1
        return out
    
    def pop_first(self):
        self.move_first()
        out = self.__pointer.value
        self.__pointer.next.prev = None
        self.__pointer = self.__pointer.next
        self.__count -= 1
        return out
    
    def first(self):
        self.move_first()
        return self.__pointer.value
    def last(self):
        self.move_last()
        return self.__pointer.value
    
    def get(self):
        out = [0 for i in range(self.__count)]
        self.move_first()
        for i in range(self.__count-1):
            out[i] = self.__pointer.value
            self.__pointer = self.__pointer.next
        out[self.__count-1] = self.__pointer.value
        return out

    def is_empty(self):
        return self.__count == 0
    
    def __eq__(self, list1):
        if (self.get() == list1.get()):
            return True
        return False

    def __add__(self, values):
        if (type(values) == list):
            for i in range(len(values)):
                self.push_back(values[i])
        else:
            self.push_back(values)

    def __str__(self) -> str:
        return str(self.get())

    def __len__(self):
        return self.__count

    def __repr__(self):
        self.move_first()
        out = ""
        while self.__pointer.next is not None:
            out += str(self.__pointer.value) + " "
            self.__pointer = self.__pointer.next 
            

if __name__ == '__main__':
    lst = Deque()
    lst1 = Deque()
    print(f" is empty? : {lst.is_empty()}")
    lst + [1, 2, 3]
    print(f" lst + [1, 2, 3]\n    {lst}\n    len: {len(lst)}")
    lst.push_front(-0)
    lst.push_front(-1)
    lst.push_front(-2)
    print(f" push front 0, -1, -2\n    {lst}\n    len: {len(lst)}")
    lst.push_back(4)
    print(f" push back 0, -1, -2\n    {lst}\n    len: {len(lst)}")
    print(f" str(lst)\n    {str(lst)}\n    type(str(lst)): {type(str(lst))}")
    lst1 + lst.get()
    print(f" create list1\n    lst1 + lst.get()\n    {lst1}")
    print(f" lst1 == lst: {lst == lst1}")
    lst1 + "s"
    print(f" lst1 + 's':\n    {lst1}")
    print(f" lst1 == lst: {lst == lst1}")
    
    lst.pop_last()
    print(f" lst.pop_last(): \n    {lst}")
    lst.pop_last()
    print(f" lst.pop_last(): \n    {lst}")
    lst.pop_first()
    print(f" lst.lst.pop_first(): \n    {lst}")
    lst.pop_first()
    print(f" lst.lst.pop_first(): \n    {lst}")
    
    print(f" last: \n    {lst.last()}")
    print(f" first: \n    {lst.first()}")

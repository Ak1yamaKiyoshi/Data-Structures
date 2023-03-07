from node import Node

class List:
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
    
    def move_to_value(self, value):
        self.move_first()
        while self.__pointer != None and self.__pointer.value != value:
            self.__pointer = self.__pointer.next
        
    def move_to_index(self, index):
        if index >= self.__count/2:
            self.move_last()
            for i in range(0, self.__count-index-1):
                self.__pointer = self.__pointer.prev
        else: 
            self.move_first()
            for i in range(0, index-1):
                self.__pointer = self.__pointer.next
         
    def __delitem__(self, value):
        self.move_to_value(value)
        if self.__pointer.value == value:
            self.__pointer = self.__pointer.prev
            self.__pointer.next.next.prev = self.__pointer
            self.__pointer.next = self.__pointer.next.next
            self.__count -= 1
            
    def pop(self, index):
        if index >= 0:
            self.move_to_index(index)
            out = self.__pointer.value
            if (index == self.__count-1):
                self.__pointer = self.__pointer.prev
            elif (index == 0):
                self.__pointer.next.prev = None
                self.__pointer = self.__pointer.next
            else:
                self.__pointer.next.prev = self.__pointer
                self.__pointer.next = self.__pointer.next.next
            self.__count -= 1
            return out

    def insert(self, value, index):
        if index < self.__count:
            self.move_to_index(index)
            obj = Node(value, prev=self.__pointer, next=self.__pointer.next)
            self.__pointer.next.prev = obj
            self.__pointer.next = obj
            self.__count += 1
        elif index == self.__count:
            self.push_back(value)
            self.__count += 1
    
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
    
    def indexOf(self, value):
        self.move_first()
        i = 0
        while self.__pointer != None and self.__pointer.value != value:
            self.__pointer = self.__pointer.next
            i += 1
        return i

    def __eq__(self, list1):
        if (self.get() == list1.get()):
            return True
        return False
    
    def __getitem__(self, index):
        if index == self.__count-1:
            self.move_last()
            return self.__pointer.value
        elif index < self.__count:
            self.move_to_index(index)
            return self.__pointer.value

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
    lst = List() 
    lst1 = List()
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
    print(f" lst[5]: {lst[5]}")
    lst.insert(90, 4)
    print(f" insert 90 at index 5 (lst.insert(90, 4))\n    {lst}\n    len: {len(lst)}\n    lst[5]: {lst[5]}")
    lst1 + lst.get()
    print(f" create list1\n    lst1 + lst.get()\n    {lst1}")
    print(f" lst1 == lst: {lst == lst1}")
    lst1 + "s"
    print(f" lst1 + 's':\n    {lst1}")
    print(f" lst1 == lst: {lst == lst1}")
    lst1.pop(len(lst1)-1)
    print(f" lst1.pop(len(lst1)-1)\n    {lst1}")
    del lst1[90]
    print(f" del lst1[90]\n    {lst1}")
    print(f" lst.get()\n    {lst.get()}\n    type(lst.get()): {type(lst.get())}")
    print(f" indexof 4: {lst.indexOf(4)} lst len: {len(lst)} get element by index 7: {lst[7]}")
    
    
    lst.pop(0)
    print(f" lst1.pop(0)\n    {lst}")
    lst.pop(0)
    print(f" lst1.pop(0)\n    {lst}")
    lst.pop(0)
    print(f" lst1.pop(0)\n    {lst}")
    lst.pop(len(lst)-1)
    print(f" lst1.pop(len(lst1)-1)\n    {lst}")
    lst.pop(len(lst)-1)
    print(f" lst1.pop(len(lst1)-1)\n    {lst}")
    lst.pop(len(lst)-1)
    print(f" lst1.pop(len(lst1)-1)\n    {lst}")

class Node:
    def __init__(self, _value, _previous=None):
        self._value = _value
        self._prev = _previous

class Stack:
    def __init__(self):
        self.__tail = None
        self.__capacity = 7
        self.__lenght = 0

    def push(self, value):
        if self.__capacity  > self.lenght()+1: 
            self.__lenght += 1
            self.__tail = Node(value, self.__tail)
        else:
            return False

    def pop(self):
        obj = self.__tail
        self.__tail = self.__tail._prev
        self.__lenght -= 1
        return self.__tail._value

    def top(self):
        return self.__tail._value
    
    def lenght(self):
        return self.__lenght
    
    def is_empty(self):
        return self.lenght() == 0

    def __repr__(self):
        obj = self.__tail
        outString = ""
        while (obj is not None):
            outString = outString + obj._value + " " 
            obj = obj._prev
        return outString


stk = Stack()

print(f'len: {stk.lenght()}') 

stk.push("BBB")  
stk.push("FGD")
stk.push("FGч")
stk.push("FGа")
stk.push("FGр")
print(stk)
stk.pop()
stk.pop()
print(stk)
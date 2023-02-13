class Queue:
    def __init__(self):
        self.__array = []
        self.__capacity = 5

    def push(self, value):
        if self.lenght()+1 < self.__capacity:
            self.__array.append(value)

    def top(self):
        return self.__array[-1]

    def lenght(self):
        return len(self.__array)

    def is_empty(self):
        return self.lenght() == 0
    
    def pop(self):
        return self.__array.pop(0)
    

qu = Queue()
qu.push(1)
qu.push(1)
qu.push(1)
print(qu.lenght())

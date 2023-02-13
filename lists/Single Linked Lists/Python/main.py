class Node:
    def __init__(self, value, previous=None):
        self._value = value
        self._prev = previous

class List:
    def __init__(self):
        self.__tail = None
        self.__lenght = 0

    def append(self, value):
        self.__tail = Node(value, self.__tail)
        self.__lenght += 1

    def lenght(self):
        return self.__lenght

    def insert(self, value, index):
        if index and index > -1 and index < self.size():
            obj = self.__tail
            for i in range(self.size()-1-index):
                obj = obj._prev
            new_node = Node(value, obj._prev)
            obj.prev = new_node
        else:
            self.append(value)
        self.__lenght += 1

    def remove(self, value):
        if isinstance(value, str):
            value = self.indexOf(value) 
        obj = self.__tail
        if value == self.lenght()-1:
            self.__tail = obj._prev
        else:
            for i in range(self.lenght()-1, 1+value, -1):
                obj = obj._prev
            obj._prev = obj._prev._prev

        for i in range(self.lenght()-1, 1+value, -1):
            obj = obj._prev
        obj._prev = obj._prev._prev
        self.__lenght -= 1
    

    def indexOf(self, value, start=0):
        obj = self.__tail 
        for i in range(self.lenght()-1, -1+start, -1):
            if obj._value == value:
                return i
            obj = obj._prev
        
    def __repr__(self):
        strOut = ""
        obj = self.__tail
        counter = self.lenght()-1
        while (obj is not None):
            strOut+=f"{obj._value} "
            obj = obj._prev
            counter-=1
        return strOut

lst = List()
lst.append("ZXC") 
print(f' lenght:{lst.lenght()}')
lst.append("YUC") 
print(f' lenght:{lst.lenght()}')
lst.append("BSC")  
print(f' lenght:{lst.lenght()}')
lst.append("OPC") 
print(f' lenght:{lst.lenght()}')
lst.append("OTD") 
print(f' lenght:{lst.lenght()}')
lst.append("001") 
print(f' lenght:{lst.lenght()}')
lst.append("SAA")
print(f' lenght:{lst.lenght()}')
print(lst)

print("____")
print(f' indexOf: {"ZXC"} {lst.indexOf("ZXC", 0)}')
print(f' lenght:{lst.lenght()}')
lst.remove("SAA")
print(f' lenght:{lst.lenght()}')
print(lst)

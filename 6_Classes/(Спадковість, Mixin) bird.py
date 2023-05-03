
class Bird:
    def __init__(self, size=10):
        self.__size = size

    def walk(self):
        return "*walkin'*"
    
    @property
    def size(self):
        return self.__size  

    @size.setter
    def setSize(self, value):
        self.__size = value
        
class FlyMixin:
    def fly(self):
        return "*flyin'*"

class Parrot(Bird, FlyMixin):
    def __init__(self, size=10):
        super().__init__(size)
    
    def speech(self):
        return "*speaking about weapon supply to ukraine*"

class Penguin(Bird):
    def __init__(self, size=15):
        super().__init__(size)

    def swim(self):
        return "*swim*"

class Ostrich(Bird):
    def __init__(self, size=20):
        super().__init__(size)


parrot = Parrot()
penguin = Penguin()
ostrich = Ostrich()
print(parrot.size)
print(ostrich.size)
class Node:

    def __init__(self, value, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next

    @property
    def get_value(self):
        return self.__value

    def set_value(self, value):
        self.__value = value

    @property
    def get_prev(self):
        return self.__prev

    def set_prev(self, value):
        self.__prev = value

    @property
    def get_next(self):
        return self.__next

    def set_next(self, value):
        self.__next = value



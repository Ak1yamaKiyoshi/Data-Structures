class animal():
    def __init__(self):
        self.__sound = "ssssss"
        self.__legs = 0

    def get_sound(self):
        return self.__sound

    def set_sound(self, value):
        self.__sound = value

    def get_legs(self):
        return self.__legs

    def set_legs(self, value):
        self.__legs = value


snk = animal()

print(snk.get_sound())
print(snk.get_legs())

snk.set_legs(1)
print(snk.get_legs())

snk.set_sound("sSs-Ss-snake!")
print(snk.get_sound())
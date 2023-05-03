class Alive:
    def __init__(self):
        self._alive = True

class NotAlive:
    def __init__(self):
        self._alive = False

class Tree(Alive):
    def __init__(self):
        super().__init__()
    def water(self):
        return "полив під корінь"

class Bush(Alive):
    def __init__(self):
        super().__init__()
    def water(self):
        return "полив по листях"

class Rock(NotAlive):
    def __init__(self):
        super().__init__()
class Table(NotAlive):
    def __init__(self):
        super().__init__()

class Garden(Tree, Bush, Rock, Table):
    def __init__(self):
        super().__init__()
        self.garden = [Tree(), Bush(), Rock(), Table()]

    def water(self):
        return "полив"

garden = Garden()
for i in garden.garden:
    if getattr(i, '_alive') == True:
        print(i.water())
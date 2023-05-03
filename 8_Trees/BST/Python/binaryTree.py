from node import Node
import random as rd

#BST
class BinaryTree(Node): 
    def __init__(self):
        self.__root = None


    def insert(self, value):
        if (self.__root == None):
            self.__root = Node(value=value, parent=None)
            return
        pointer = self.__root
        while True:
            if value < pointer.value and pointer.left:
                pointer = pointer.left
            elif value >= pointer.value and pointer.right:
                pointer = pointer.right
            else: break

        if pointer.value > value: pointer.left = Node(value, pointer)
        else: pointer.right = Node(value, pointer)


    def remove(self, value):
        def min(pointer): 
            while pointer.left: # 
                pointer = pointer.left
            return pointer
        """
            while pointer.left: # 
                pointer = pointer.left
            return pointer
        """

        pointer = self.binarySearch(value)

        if not pointer:
            return
        
        parent = pointer.parent
        if parent:
            if parent.left and parent.left == pointer: atr = "left"
            else: atr = "right"

        """
        if pointer.left and pointer.right:
            ptr = min(pointer.right)
            pointer.value = ptr.value
            if ptr == ptr.parent.left:
                ptr.parent.left = None
            else: ptr.parent.right = None
        """
        # both childs
        if pointer.left and pointer.right:
            ptr = min(pointer.right)
            pointer.value = ptr.value
            if ptr == ptr.parent.left:
                ptr.parent.left = None 
            else: ptr.parent.right = None
        # one child
        elif pointer.left:    
            if pointer == self.__root:
                self.__root = pointer.left
            else:
                setattr(parent, atr, pointer.left)
                pointer.left.parent = parent
        elif pointer.right:
            if pointer == self.__root:
                self.__root = pointer.right
            else:
                setattr(parent, atr, pointer.right)
                pointer.right.parent = parent
        # leaf node 
        else: setattr(parent, atr, None)


    def rotateLR():
        pass
    
    
    def rotateLL():
        pass
    
    
    def rotateRR():
        pass
    
    
    def rotateRL():
        pass


    def balance():
        pass

    def pre_order_traverse_search(self, value, pointer=False): 
        if pointer == False: pointer = self.__root
        if (pointer == None): return
        
        if pointer.value == value:
            return pointer
        # Look for right child
        buffer = self.pre_order_traverse_search(value, pointer.right)
        if buffer != None: return buffer
        # Look for left child
        buffer = self.pre_order_traverse_search(value, pointer.left)
        if buffer != None: return buffer
    
    
    def post_order_traverse_search(self, value, pointer=False): 
        if pointer == False: pointer = self.__root
        if (pointer == None): return
        
        # Look for right child
        buffer = self.post_order_traverse_search(value, pointer.right)
        if buffer != None: return buffer
        # Look for left child
        buffer = self.post_order_traverse_search(value, pointer.left)
        if buffer != None: return buffer

        if pointer.value == value:
            return pointer
    
    
    def in_order_traverse_search(self, value, pointer=False): 
        if pointer == False: pointer = self.__root
        if (pointer == None): return
        
        # Look for right child
        buffer = self.in_order_traverse_search(value, pointer.right)
        if buffer != None: return buffer

        if pointer.value == value:
            return pointer

        # Look for left child
        buffer = self.in_order_traverse_search(value, pointer.left)
        if buffer != None: return buffer


    def binarySearch(self, value, pointer=False):
        if pointer==False:
            pointer = self.__root
        if pointer.value == value:
            return self.__root
        while True:
            if pointer.value>value and pointer.left!=None:
                pointer = pointer.left
            elif pointer.value<value and pointer.right != None:
                pointer = pointer.right
            else: 
                break
        if pointer.value == value:
            return pointer


    # Turn tree to array by pre order traversal
    def pre_order_to_array(self, pointer=False):
        if pointer == False: pointer = self.__root
        out = []
        
        out.append(pointer.value)        
        if pointer.left: out += self.pre_order_to_array(pointer.left) 
        if pointer.right: out += self.pre_order_to_array(pointer.right) 

        return out  


    # Turn tree to array by in order traversal
    def in_order_to_array(self, pointer=False):
        if pointer == False: pointer = self.__root
        out = []
        
        if pointer.left: out += self.in_order_to_array(pointer.left) 
        out.append(pointer.value)        
        if pointer.right: out += self.in_order_to_array(pointer.right) 

        return out  


    # Turn tree to array by post order traversal
    def post_order_to_array(self, pointer=False):
        if pointer == False: pointer = self.__root
        out = []
        
        if pointer.left: out += self.post_order_to_array(pointer.left) 
        if pointer.right: out += self.post_order_to_array(pointer.right) 
        out.append(pointer.value)        

        return out  


    def __add__(self, lst):
        for i in lst:
            self.insert(i)


    def __str__(self):
        return self.__repr__()


    def __eq__(self, __o: object) -> bool:
        return self.in_order_to_array() == __o.in_order_to_array()


    def __len__(self):
        return len(self.in_order_to_array())


    def height(self, pointer=False, height=False):
        if pointer == False: pointer = self.__root
        elif not pointer: return height
        if height == False: height = 0
        left = self.height(pointer.left, height+1)
        right = self.height(pointer.right, height+1)
        return max(left, right)


    # To clearly see which number to remove
    def display_highlight(self, to_remove=None, pointer=False, space=0, level=4):
        if pointer == False: pointer = self.__root
        if (pointer == None): return
        space += level
        self.display_highlight(to_remove, pointer.right, space)
        for i in range(level, space): print(end = '\033[92m' + ".")  
        if pointer.value != to_remove:
            print('\033[93m' + "[" + '\033[0m' + str(pointer.value) + '\033[93m' + "]<")
        else: 
            print('\033[93m' + "[" + '\033[91m' + str(pointer.value) + '\033[93m' + "]<")
        self.display_highlight(to_remove, pointer.left, space)
        print("" + '\033[0m', end="")


    # In Order Traversal Print 
    def display(self, pointer=False, space=0, level=4):
        if pointer == False: pointer = self.__root
        if not pointer: return
        space += level
        self.display(pointer.right, space)

        for i in range(level, space): print(end = ".")  
        print("[" + str(pointer.value) + "]<")
        self.display(pointer.left, space)
        print("", end="")


    def __repr__(self, pointer=False):
        if pointer == False: pointer = self.__root
        out = ""
        
        if pointer.left: out += self.__repr__(pointer.left) 
        out += str(pointer.value) + " "        
        if pointer.right: out += self.__repr__(pointer.right) 

        return out  


if __name__ == "__main__":
    tree = BinaryTree()
    tree + [30, 40, 10, 5, 15, 14, 25, 20]
    tree.display()
    print("____")
    tree.display()
    print(tree.height())
    print(tree.in_order_to_array())
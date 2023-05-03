import pytest
import binaryTree
import random as rd

""" SEARCH TESTS """

def test_binary_search_wrong_number():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert tree.binarySearch(333) == None

def test_binary_search_find_node():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert tree.binarySearch(5) != None

def test_binary_search_find_node_from_node():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    pointer = tree.binarySearch(5) 
    assert tree.binarySearch(0, pointer=pointer).value == 0 

def test_binary_search_right_value():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert tree.binarySearch(5).value == 5

def test_in_order_search_true():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.in_order_traverse_search(1).value == 1
    assert tree.in_order_traverse_search(1).parent.value == 3    

def test_post_order_search_true():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.post_order_traverse_search(1).value == 1
    assert tree.post_order_traverse_search(1).parent.value == 3

def test_pre_order_search_true():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.pre_order_traverse_search(1).value == 1
    assert tree.pre_order_traverse_search(1).parent.value == 3

def test_in_order_search_false():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.in_order_traverse_search(41414) == None
    
def test_post_order_search_false():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.post_order_traverse_search(41414) == None

def test_pre_order_search_false():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 6, 2, 99, -32]
    assert tree.pre_order_traverse_search(41414) == None

""" INSERTION TESTS """

def test_insert_left_child_of_root():
    tree = binaryTree.BinaryTree()
    tree.insert(5) 
    tree.insert(3) 
    assert tree.binarySearch(5).left.value == 3

def test_insert_right_child_of_root():
    tree = binaryTree.BinaryTree()
    tree.insert(5) 
    tree.insert(6) 
    assert tree.binarySearch(5).right.value == 6

def test_insert_left_child_of_tree():
    tree = binaryTree.BinaryTree()
    tree.insert(0) 
    tree.insert(6) 
    tree.insert(4) 
    assert tree.binarySearch(6).left.value == 4

def test_insert_right_child_of_tree():
    tree = binaryTree.BinaryTree()
    tree.insert(0) 
    tree.insert(6) 
    tree.insert(7) 
    assert tree.binarySearch(6).right.value == 7

def test_add_values_from_list_to_root():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2]
    assert tree.binarySearch(5).right.value == 7
    assert tree.binarySearch(5).left.value == 2

def test_add_values_from_list_to_tree():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert tree.binarySearch(5).right.value == 7
    assert tree.binarySearch(5).left.value == 2

""" LEN TEST"""

def test_len():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert len(tree) == len([0, 1, 5, 7, 2])

def test_len_1():
    tree = binaryTree.BinaryTree()
    tree + [0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5]
    assert len(tree) == len([0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5])

def test_len_2():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2]
    assert len(tree) == len([5, 7, 2])

""" BINARY TREE TO ARRAY TESTS """

def test_to_array_in_order():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert sorted(tree.in_order_to_array()) == [0, 1, 2, 5, 7]

def test_to_array_pre_order():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert sorted(tree.pre_order_to_array()) == [0, 1, 2, 5, 7]

def test_to_array_post_order():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert sorted(tree.post_order_to_array()) == [0, 1, 2, 5, 7]

def test_to_array_post_order_random_test():
    tree = binaryTree.BinaryTree()
    array = [rd.randint(0, 100) for i in range(1000)]
    tree + array

    assert sorted(tree.post_order_to_array()) == sorted(array)

""" BINARY TREE TO STR TESTS """

def test_str_1():
    tree = binaryTree.BinaryTree()
    tree + [3, 1, 2]
    assert str(tree) == "1 2 3 "

def test_str_2():
    tree = binaryTree.BinaryTree()
    tree + [5, 4, 3, 2, 1]
    assert str(tree) == "1 2 3 4 5 "

def test_str_3():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert str(tree) == "0 1 2 5 7 "

""" BINARY TREE EQUALS BINARY TREE TESTS """

def test_tree_eq_tree_true():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    tree1 = binaryTree.BinaryTree()
    tree1 + [5, 7, 2, 0, 1]
    assert tree1 == tree

def test_tree_eq_tree_false():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    tree1 = binaryTree.BinaryTree()
    tree1 + [5, 7, 2, 0, 5]
    assert tree1 != tree

""" HEIGHT TESTS """

def test_height_1():
    tree = binaryTree.BinaryTree()
    tree + [5, 7, 2, 0, 1]
    assert tree.height() == 4
    """
    ....[7]<
    [5]<
    ....[2]<
    ............[1]<
    ........[0]<
    """

def test_height_2():
    tree = binaryTree.BinaryTree()
    tree + [1, 2, 3, 4, 5]
    assert tree.height() == 5
    """
    ................[5]<
    ............[4]<
    ........[3]<
    ....[2]<
    [1]<
    """

def test_height_3():
    tree = binaryTree.BinaryTree()
    tree + [1, 2, 3, 2, 1, 0, -1, 4, 5]
    assert tree.height() == 5
    """
    ................[5]<
    ............[4]<
    ........[3]<
    ............[2]<
    ....[2]<
    ........[1]<
    [1]<
    ....[0]<
    ........[-1]<
    """

""" REMOVE TESTS """

def test_remove_left_leaf_node_from_root():
    tree = binaryTree.BinaryTree()
    tree + [5, 2]
    assert tree.binarySearch(5).left.value == 2
    tree.remove(2)
    assert tree.binarySearch(5).left == None

def test_remove_right_leaf_node_from_root():
    tree = binaryTree.BinaryTree()
    tree + [5, 7]
    assert tree.binarySearch(5).right.value == 7
    tree.remove(7)
    assert tree.binarySearch(5).right == None

def test_remove_left_leaf_node_from_tree():
    tree = binaryTree.BinaryTree()
    tree + [5, 60, 70, 65]
    assert tree.binarySearch(70).left.value == 65
    tree.remove(65)
    assert tree.binarySearch(70).left == None

def test_remove_right_leaf_node_from_tree():
    tree = binaryTree.BinaryTree()
    tree + [4, 4, 4, 5, 7]
    assert tree.binarySearch(5).right.value == 7
    tree.remove(7)
    assert tree.binarySearch(5).right == None

def test_remove_when_right_child():
    tree = binaryTree.BinaryTree()
    tree + [1, 2, 3, 4, 5, 6, 7]
    assert tree.binarySearch(5).right.value == 6
    tree.remove(6)
    assert tree.binarySearch(5).right.value == 7

def test_remove_when_left_child():
    tree = binaryTree.BinaryTree()
    tree + [7, 6, 5, 4, 3, 2, 1]
    assert tree.binarySearch(6).left.value == 5
    tree.remove(5)
    assert tree.binarySearch(6).left.value == 4

def test_remove_node_when_both_childs_and_no_smaller_value_in_right_subtree():
    tree = binaryTree.BinaryTree()
    tree + [50, 56, 57, 58, 49, 48, 49, 47, 59]
    
    # REMOVE parent with both childs when right subtrees dont have value smaller than removable value 
    tree.remove(50)
    assert sorted(tree.in_order_to_array()) == sorted([56, 57, 58, 49, 48, 49, 47, 59])

def test_remove_when_both_childs_2():
    tree = binaryTree.BinaryTree()
    tree + [30, 40, 10]
     
    tree.remove(30)
    assert sorted(tree.in_order_to_array()) == sorted([40, 10])
    assert tree.binarySearch(40).left.value == 10

def test_remove_when_both_childs_3():
    tree = binaryTree.BinaryTree()
    tree + [30, 40, 10, 5, 15, 14, 25, 20]
    """
    ....[40]<
    [30]<
    ............[25]<
    ................[20]<
    ........[15]<
    ............[14]<
    ....[10]<
    ........[5]<
    """
    tree.remove(10)
    assert sorted(tree.in_order_to_array()) == [5, 14, 15, 20, 25, 30, 40]
    assert tree.binarySearch(30).left.value == 14


""" ROTATE TESTS """
    
def test_rotateLR():
    pass


def test_rotateLL():
    pass


def test_rotateRR():
    pass


def test_rotateRL():
    pass


def test_balance():
    pass

pytest.main()

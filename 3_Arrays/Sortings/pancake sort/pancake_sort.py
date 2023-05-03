from random import randint

def pancake_sort(lst):
    for i in range(len(lst)-1, 0, -1):
        k = lst[0:i+1].index(max(lst[0:i+1]))
        print(k)
        if k != i:
            lst = lst[k::-1]+lst[k+1::]
            print(lst)
            lst = lst[i::-1]+lst[i+1::]
        print(lst)
    return lst

a = [randint(0,20) for i in range(10)]
print(a)
print(pancake_sort(a))

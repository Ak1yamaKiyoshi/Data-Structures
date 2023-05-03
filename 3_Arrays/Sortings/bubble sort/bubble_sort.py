def bubble_sort(array):
    for i in range(len(array)-1):
        flag = False
        for x in range(len(array)-1-i):
            if array[x] > array[x+1]:
                array[x], array[x+1] = array[x+1], array[x]
                flag = True
        if not flag:
            break
            
# Driver code 
to_sort = [3, 2, 1, 5, 4]
print(bubble_sort(to_sort))

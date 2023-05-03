# 5. Індекс (розташування, номер по порядку введення) мінімального та максимального числа послідовності 


number = None
max = None
maxIndex = None
min = None
minIndex = None
counter = -1
while number != 0:
    if max is None or number > max:
        max = number
        maxIndex = counter
    if min is None or number < min:
        min = number  
        minIndex = counter  
    counter += 1
    number = int(input(" enter num: ")) 
print(f" max, index: {max}, {maxIndex} min \n min, index: {min}, {minIndex}")

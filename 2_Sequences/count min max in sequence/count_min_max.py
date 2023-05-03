# 6. Кількість максимальних та мінімальних чисел у послідовності


number = None
max = None
min = None
while number != 0:
    if max is None or number >= max:
        if number is not None and number == max:
            maxCounter += 1
        else: 
            max = number
            maxCounter = 1
            
    if min is None or number <= min:
        if number is not None and number == min:
            minCounter += 1
        else: 
            min = number  
            minCounter = 1
    number = int(input(" enter num: ")) 
print(f" max, count: {max}, {maxCounter} \n min, count: {min}, {minCounter}")

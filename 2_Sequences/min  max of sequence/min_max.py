# 4. Мінімальне та максимальне числа послідовності

number = None
max = None
min = None
while number != 0:
    if max is None or number > max:
        max = number
    if min is None or number < min:
        min = number  
    number = int(input(" enter num: ")) 
print(f" max number in sequence: {max} min number in sequence: {min}")

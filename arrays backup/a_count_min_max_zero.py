""" 

array = [ -1, -1, 1, 2, 3, 4, 5, 0, 0, 0, 5, 5, 1, 2 ]
nMax = None
nMin = None
zero_counter= 0
min_counter = 0
max_counter = 0

# find min and max numbers in array 
for i in array:
    
    # MIN and MIN COUNTER 
    if nMin is None or i <= nMin:
        # if current number and max number are equal update counter 
        if nMin == i: min_counter += 1 
        # if current number is smaller than min number (nMin)
        # update min number and set it's counter to 1 
        else: nMin = i; min_counter = 1
        
    # MAX and MAX COUNTER 
    if nMax is None or i >= nMax:
        # if current number and max number are equal update counter 
        if nMax == i: max_counter += 1
        # if current number is bigger than max number (nMax)
        # update max number and set it's counter to 1 
        else: nMax = i; max_counter = 1
        
    # ZERO counter 
    # if current item is zero update counter 
    if i == 0: zero_counter += 1

print(array)
print(f"\n -> max: {nMax} \n -> max_counter: {max_counter} \n -> min: {nMin} \n -> min_counter: {min_counter} \n -> zero_counter: {zero_counter}")
"""

print(len(str(123123)))
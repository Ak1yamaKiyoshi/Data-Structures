
number = 11
is_prime = True 
for i in range(2, number):
    if (number % i == 0):
        is_prime = False

if not is_prime: 
    print(f" {number} number is not prime ")      
elif is_prime: 
    print(f" {number} number is prime ")      
    

def rev(lst):
    for i in range(int(len(lst)/2)):
        lst[i], lst[-i-1] = lst[-i-1], lst[i]  

s = ["o","l","l","e","h"]
rev(s)
print(s)
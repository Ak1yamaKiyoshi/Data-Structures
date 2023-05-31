def count_letters(string):
    uppercase = [0]*26
    lowercase = [0]*26
    # for i in filtered list (without special charachters)
    for i in [j for j in list(string) if j.isalpha()]:
        if i.isupper():
            uppercase[ord(i)-65] += 1
        elif i.islower():
            lowercase[ord(i)-97] += 1
    
    for i in range(26):
        if uppercase[i]!=0:
            print(f"{chr(i+65)} -> {uppercase[i]}")
        if lowercase[i]!=0:
            print(f"{chr(i+97)} -> {lowercase[i]}")
    
    
def count_letters_2(string):
    letters = set([j for j in list(string) if j.isalpha()])
    for i in sorted(list(letters)):
        print(f"{i} :{string.count(i)}")
     

str1 = "abbcdejduiPONyanudBEBRAga____DADtfyoagZZZZzzzzzwwwwwWW"
count_letters(str1)
count_letters_2(str1)

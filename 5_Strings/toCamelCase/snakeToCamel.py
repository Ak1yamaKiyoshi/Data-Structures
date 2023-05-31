def snakeToCamel(string):
    for i in range(len(string)):
        if string[i].isupper():
            string = string[:i] + "_" + string[i].lower() + string[i+1:] 
    return string  

str1 = "someTextInSnakeNotation"
print(snakeToCamel(str1))
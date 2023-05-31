""" - Переробити рядок знизу у рядок "алфАвІт, кОпчений, веснЯнИй, перенестИ"
"""

def cut_accents(string):
    output = ""
    for j in string.replace("\n", " ").split(" "):
        if len(j) > 3: 
            output += j + ", "
    return output

def cut_accents_1(string):
    return ", ".join([i for i in string.replace("\n", " ").split(" ") if len(i) > 3])
    
str1 = """ 
алфАвІт 

ц

кОпчений 12

т

веснЯнИй  п

в

перенестИ в

1
"""
print(cut_accents(str1))
print(cut_accents_1(str1))

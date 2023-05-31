def numToWord(num):
    below20 = ["zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "] 
    below100 = ["", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "]
    if num < 20: 
        output = below20[num]
    elif num < 100:
        output = (below100[num//10] 
        + below20[num%10])
    elif num < 1000:
        output = below20[(num%1000)//100] + "hundred " + below100[(num%100)//10] + below20[num%10]
    return output

print( numToWord(899) )
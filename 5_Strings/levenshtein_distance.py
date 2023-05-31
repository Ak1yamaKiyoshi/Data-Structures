knownWords = ["teapot", "teammate", "teamster", "teamwork", "tear", "tear gas"] #Known Words
for x in range(len(knownWords)): # x - Index for knownWords
    i = 1 #String INDEX
    inputWord = "teamwork" #String 
    distanceLev = abs(len(inputWord) - len(knownWords[x]))#counts distanceLev if string is smaller or bigger then knownWords string 
    while i < len(inputWord) + 1:
        if inputWord[:i] not in knownWords[x][:i]:
            if inputWord[i-1:i] in knownWords[x][i:i+1]:
                inputWord = inputWord[:i-1] + knownWords[x][i-1:i+1] + inputWord[i:] #INCERT  
            if inputWord[i-1:i] not in knownWords[x][i:i+1]:
                if inputWord[i:i+1] in knownWords[x][i-1:i]:
                    inputWord = inputWord[:i-1] + inputWord[i:] #DELETE
                else:
                    inputWord = inputWord[:i-1] + knownWords[x][i-1:i] + inputWord[i:] #REPLACEMENT
            distanceLev += 1 #EDIT COST for any operation, 1 cycle - 1 operation
        i += 1
    if x == 0 or minDistanceLev > distanceLev:# saves min levenshtein distance
        minDistanceLev = distanceLev
        minIndex = x 
print(f' knownWords = {knownWords[minIndex]} \n len = {minDistanceLev}') #min lev word
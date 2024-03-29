nestedDict = {
    1: {"a": "UMV"},
    2: {"DDD": {"b": "DDD", "d": 789}, "x": "123"},
    3: {"c": True},
    4: {"m": {"b": "DDD", "d": "BNF"}, "x": "123"}
}


def find(nDict, target):
    for e in nDict.keys():
        if nDict[e] == target:
            return e # Recursion Bottom
        if type(nDict[e]) is dict:
            out = find(nDict[e], target)
            if out != None: # Path
                return str(out) + "." + str(e)

# Driver code
print(find(nestedDict, True)[::-1])
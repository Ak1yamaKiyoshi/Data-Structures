def wayFind(index, y, list):
    x = index
    num = list[y][x] 
    while x < index+3 :
        if list[y][x] == 0 and list[y][x-1] != 0:
            y += 1
            x -= 2
        if list[y][x] == num+1:
            return [x, y]
        x+=1

list = [[1,2,0,0,0], [0,0,3,0,0], [0,4,5,6,0], [0,0,0,7,0], [0,0,0,0,8]]
way = []
x = 0
y = 0
if list[y][x] == 1:
    way.append(f'x={x},y={y},num={list[y][x]}')

for i in range(len(list)+2):
    x, y = wayFind(x, y, list)[0], wayFind(x, y, list)[1]
    way.append(f'x={x},y={y},num={list[y][x]}')

print(way)

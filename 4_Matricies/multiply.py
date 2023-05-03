def multiply(array, rows, cols, array1, rows1, cols1):
    if cols == rows1:
        print(f"\n result Matrix {cols1}x{rows} :");
        colsR = cols1;
        rowsR = rows;
        arrR = [
            [".", ".",  ".",  ".",],
            [".", ".",  ".",  ".",]
        ]
        for y1 in range(rowsR): # 2
            for x1 in range(colsR): # 4
                element = ""
                for x in range(cols): # 3
                    element += array[y1][x] + array1[x][x1] + "|"
                arrR[y1][x1] = element
        for y1 in range(rowsR):
            print(" ")
            for x1 in range(colsR):
                print(arrR[y1][x1], end=" ")
arr = [
    ["a1", "a2", "a3"],
    ["a4", "a5", "a6"],
    ["a7", "a8", "a9"]
]
cols = 3
rows = 2

arr1 = [
    ["b1", "b2",  "b3",  "b4",],
    ["b5", "b6",  "b7",  "b8",],
    ["b9", "b10", "b11", "b12"]
]
cols1 = 4 
rows1 = 3

multiply(arr, rows, cols, arr1, rows1, cols1)
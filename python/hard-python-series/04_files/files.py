
def print_4th_row():
    with open("data/file_01.txt", "r") as file1:
        print(file1.readlines()[3])
        

def join_row_reverse_order():
    file1_rows = []
    with open("data/file_03_1.txt", "r") as file1:
        file1_rows = file1.readlines()

    file2_rows = []
    with open("data/file_03_2.txt", "r") as file2:
        file2_rows = file2.readlines()
    
    inverted_size = len(file1_rows) - (len(file1_rows) * 2) 
    i = -1
    with open("data/file_03_3.txt", "w") as file3:
        while i >= inverted_size:
            for row2 in file2_rows:
                if file1_rows[i] == row2:
                    file3.write(file1_rows[i])
            i -= 1
   
    with open("data/file_03_3.txt", "r") as file3:
        print(file3.read())

def diagonal():
    list_a = []
    list_b = []
    with open("data/2_rows_file.txt", "r") as file1:
        rows = file1.readlines()
        list_a = rows[0].split(",")
        list_b = rows[1].split(",")

    list_a = [int(num) for num in list_a]
    list_b = [int(num) for num in list_b]

    matrix = [ [0 for col in range(len(list_a))] for row in range(len(list_b)) ]
    
    for row in range(len(list_a)):
        for col in range(len(list_b)):
            if row == col:
                matrix[row][col] = list_a[row] + list_b[col]
    
    with open("data/matrix.txt", "w") as matrix_file:
        for row in range(len(matrix)):
            for col in range(len(matrix[row])):
                
                matrix_file.write(str(matrix[row][col])) 
                if col == len(matrix[row]) - 1:
                    matrix_file.write("\n")
                else:
                    matrix_file.write(" ")
    
    with open("data/matrix.txt", "r") as matrix_file:
        print(matrix_file.read())    


#print_4th_row()
#join_row_reverse_order()
diagonal()

# This method uses DFS, count islands just consider islands in row and cols no need to consider diagonals


def visit(row, col):
    if matrix[row][col] == 1:
        matrix[row][col] = -1
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dr, dc in directions:
            n_row = row + dr
            n_col = col + dc
            if -1 < n_col < wd and -1 < n_row < ht:
                visit(n_row, n_col)

def count(matrix):
    count_tmp = 0
    for row in range(ht):
        for col in range(wd):
            if(matrix[row][col] == 1):
                visit(row, col)
                count_tmp += 1
    return count_tmp

matrix = [[1,1,1,1],[0,0,0,0],[1,0,0,1]]
ht = len(matrix)
wd = len(matrix[0])


print(count(matrix))
class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    for k in range(9):
                        if k != i and board[k][j] == board[i][j]:
                            return False
                        if k != j and board[i][k] == board[i][j]:
                            return False
                    sx = i // 3
                    sy = j // 3
                    for x in range(3):
                        for y in range(3):
                            tx = sx * 3 + x
                            ty = sy * 3 + y
                            if tx != i or ty != j:
                                if board[tx][ty] == board[i][j]:
                                    return False
        return True

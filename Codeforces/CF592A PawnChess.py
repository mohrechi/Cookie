board = []
for i in xrange(8):
    board.append(raw_input())
minW, minB = 8, 8
for j in xrange(8):
    for i in xrange(8):
        if board[i][j] != '.':
            if board[i][j] == 'W':
                minW = min(minW, i)
            break
    for i in xrange(7, -1, -1):
        if board[i][j] != '.':
            if board[i][j] == 'B':
                minB = min(minB, 7 - i)
            break
if minW <= minB:
    print 'A'
else:
    print 'B'

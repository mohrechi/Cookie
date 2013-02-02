map = [[0 for i in range(4)] for j in range(4)]
max = 0
n = 0
stepX = [1,0,-1,0]
stepY = [0,1,0,-1]

def dfs(depth, position):
    global max
    if depth > max:
        max = depth
    while position < n * n:
        i = int(position / n)
        j = int(position % n)
        if map[i][j] == 0:
            flag = True
            for k in range(4):
                tx = i
                ty = j
                while flag:
                    tx += stepX[k]
                    ty += stepY[k]
                    if tx < 0 or ty < 0 or tx >=n or ty >= n:
                        break
                    if map[tx][ty] == 1:
                        break
                    if map[tx][ty] == 2:
                        flag = False
                        break
            if flag:
                map[i][j] = 2
                dfs(depth = depth + 1, position = i * n + j + 1)
                map[i][j] = 0
        position += 1

while True:
    n = int(raw_input())
    if n == 0:
        break
    for i in range(n):
        s = raw_input()
        for j in range(n):
            if s[j] == 'X':
                map[i][j] = 1
            else:
                map[i][j] = 0
    max = 0
    dfs(depth = 0, position = 0)
    print(max)
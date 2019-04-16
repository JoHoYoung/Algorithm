T = int(input())

U = 1
D = 2
R = 3
L = 4

Gscore = 0
list = []
result = []
initx = 0
intiy = 0
score = 0

def max(a, b):
    if a<b:
        return b
    return a

def changeDirection(x,y,direction, block):
    global map

    if direction == U:
        if block == 1:
            direction = D
        elif block == 2:
            direction = R
        elif block == 3:
            direction = L
        elif  block == 4:
            direction = D
        elif block == 5:
            direction = D
        else:
            direction = U
    elif direction == D:
        if block == 1:
            direction = R
        elif block == 2:
            direction = U
        elif block == 3:
            direction = U
        elif block == 4:
            direction = L
        elif block == 5:
            direction = U
        else:
            direction = D
    elif direction == R:
        if block == 1:
            direction = L
        elif block == 2:
            direction = L
        elif block == 3:
            direction = D
        elif  block == 4:
            direction = U
        elif block == 5:
            direction = L
        else:
            direction = R
    elif direction == L:
        if block == 1:
            direction = U
        elif block == 2:
            direction = D
        elif block == 3:
            direction = R
        elif  block == 4:
            direction = R
        elif block == 5:
            direction = R
        else:
            direction = L

    if direction == U:
        return (x-1,y,direction)
    if direction == D:
        return (x+1,y,direction)
    if direction == R:
        return (x, y+1, direction)
    if direction == L:
        return (x, y-1, direction)

def move(x,y,direction):
    global initx, inity, score, map

    if x == initx and y == inity and score != 0:
        return

    if map[x][y] == -1:
        return

    if map[x][y] >=6 and map[x][y] <=10:
        for i in range(len(map)):
            for j in range(len(map[0])):
                if map[i][j] == map[x][y]:
                    if i != x or j != y:
                        if direction == U:
                            move(i - 1, j,U)
                            return
                        if direction == D:
                            move(i+1,j,D)
                            return
                        if direction == R:
                            move(i,j+1,R)
                            return
                        if direction == L:
                            move(i,j-1,L)
                            return

    if map[x][y] != 0:
        score +=1
    (x, y, newDir) = changeDirection(x, y, direction, map[x][y])
    move(x,y,newDir)
    return

for k in range(0,T):
    N = int(input())
    list = []
    map = [[0 for cols in range(N+2)] for rows in range(N+2)]

    for i in range(0,N+2):
        for j in range(0,N+2):
            map[i][j] = 0

    for i in range(0, N):
        line = input().split()
        list.append(line)

    initx = 0
    inity = 0
    for i in range(0,N+2):
        for j in range(0, N+2):
            if i == 0 or j==0 or i == N+1 or j == N+1:
                map[i][j] = 5
            else:
                map[i][j] = int(list[i-1][j-1])

    for i in range(1,N+1):
        for j in range(1,N+1):
            if map[i][j] == 0:
                for d in range(1,5):
                    initx = i
                    inity = j
                    x = i
                    y = j
                    score = 0
                    move(x,y,d)
                    Gscore = max(Gscore,score)

    result.append("#" + str(k+1)+" "+str(Gscore))
    Gscore = 0
    score = 0

for i in range(len(result)):
    if(i == len(result)-1):
        print(result[i], end=" ")
    else:
        print(result[i])


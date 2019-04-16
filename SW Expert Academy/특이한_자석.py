# 4013. [모의 SW 역량테스트] 특이한 자석

import math

T = int(input())

print(math.pow(2,3))
def changeArr(list, direction):
    if direction == 1:
        temp = list[0]
        for i in range(0, len(list)):
            if i == len(list) - 1:
                list[0] = temp
            else:
                temp2 = list[i + 1]
                list[i+1] = temp
                temp = temp2
    if direction == -1:
        temp = list[len(list)-1]
        for i in range(len(list)-1, -1,-1):
            if i == 0:
                list[len(list)-1]= temp
            else:
                temp2 = list[i-1]
                list[i-1]= temp
                temp = temp2

def checkRight(myList, rightList, mydir):
    if myList[2] != rightList[6]:
        return -mydir
    return mydir

def checkLeft(myList, leftList, mydir):
    if myList[6] != leftList[2]:
        return -mydir
    return mydir

def rotate(idx,mydir,LR,list):
    if LR == -1 and idx != 0:
        newdir = checkLeft(list[idx],list[idx-1],mydir)
        if mydir != newdir:
            # print(1)
            # print(mydir,newdir)
            rotate(idx-1, newdir, -1,list)
            changeArr(list[idx-1],newdir)
    if LR == 1 and idx != len(list)-1:
        newdir = checkRight(list[idx],list[idx+1],mydir)
        if mydir != newdir:
           # print(2)
           # print(mydir,newdir,"INDEX : ",idx)
            rotate(idx+1,newdir,1,list)
            changeArr(list[idx + 1], newdir)

for k in range(0,T):
    K = int(input())
    map = [[0 for cols in range(8)] for rows in range(4)]
    for i in range(0, 4):
        list = input().split()
        # print(list)
        for j in range(0, 8):
            map[i][j] = int(list[j])

    for i in range(0, K):
        list = input().split()
        # print(list)
        num = int(list[0])-1
        dir = int(list[1])
        rotate(num,dir,-1,map)
        rotate(num,dir,1,map)
        changeArr(map[num],dir)

    result = 0
    for i in range(0,4):
        if map[i][0] == 1:
            result += int(math.pow(2,i))

    #for i in range(0,4):
       # print(map[i])

    print("#"+str(k+1)+" " + str(result))


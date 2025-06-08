from copy import deepcopy
import numpy as np

startTemp = 30
endTemp = 0.5
alpha = 0.99
steps = 1000

class Solution:
    board: int
    energy: int
    
    def __init__(self, board, energy):
        self.board = board
        self.energy = energy

def SwitchRows(board):
    x = np.random.randint(0, n)
    y = np.random.randint(0, n)
    while (x == y):
        y = np.random.randint(0, n)
    board[[x, y]] = board[[y, x]]
    
def CountEnergy(sol):
    n = len(sol.board)
    energy = 0
    
    for i in range(n):
        d = 1
        for j in range(n):
            if (sol.board[i, j] == 1):
                item0 = j
                break
        
        for k in range(i):
            for l in range(n):
                if (sol.board[k, l] == 1):
                    if (abs(item0 - l) == abs(i - k)): d = 0
        energy += d
 
    sol.energy = energy

def PrintBoard(board):
    for i in range (len(board)):
        print(" _", end="")
    print()
    for i in range (len(board)):
        for j in range (len(board)):
            if (board[i, j] == 0): print("|_", end="")
            else: print("|Q", end="")
        print("|")

def InputNum(n):
    print("Введите количество ферзей (4 и более): ", end="")
    n = input()
    try:
        n = int(n)
    except ValueError:
        n = 0
    return n

n = 4
while (n > 3):
    n = InputNum(n)
    
    while (n < 3): n = InputNum(n)

    curSol = Solution(np.zeros((n, n)), 0.0)

    # изначальная расстановка ферзей по диагонали
    # позволяет избежать конфликтов по горизонтали и вертикали
    for i in range (n):
        curSol.board[i, i] = 1

    for i in range(n): SwitchRows(curSol.board)
    CountEnergy(curSol)

    temp = startTemp
    bestSol = deepcopy(curSol)

    while (temp > endTemp):
        for step in range(steps):
            SwitchRows(curSol.board)
            CountEnergy(curSol)
            if (curSol.energy > bestSol.energy):
                p = np.exp((curSol.energy - bestSol.energy) / temp)
                test = np.random.rand()
                if (p > test and curSol.energy > bestSol.energy): bestSol = deepcopy(curSol)
                else: curSol = deepcopy(bestSol)
            temp *= alpha

    PrintBoard(bestSol.board)
    print(bestSol.energy)
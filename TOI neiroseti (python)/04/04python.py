# http://sereja.me/a/annealing.html
import math
import random

# Эти библиотеки будут нужны, чтобы рисовать графики:
import matplotlib.pyplot as plt

def fitness(p):
    s = 0
    for i in range(len(p)):
        d = 1
        for j in range(i):
            if abs(i-j) == abs(p[i]-p[j]): # ферзи стоят на одной диагонали
                d = 0
        s += d
    return s
n = 100 # кол-во ферзей
k = 1000 # кол-во итераций
p = list(range(n)) # исходная перестановка

scores = []

t = 1
for i in range(k):
    # уменьшаем температуру
    t *= 0.99 # этот параметр лучше перебрать руками
    
    # копируем перестановку и делаем небольшое изменение
    q = p[:]
    a, b = random.sample(range(n), 2)
    q[a], q[b] = q[b], q[a]
    
    # считаем разницу fitness и решаем, нужно ли переходить в новое состояние
    d = fitness(q) - fitness(p)
    if d > 0 or random.random() < math.exp(d/t):
        p = q[:]
    scores += [fitness(q)]
    print(p)

print('Best score:', max(scores))
plt.plot(scores)
plt.show()
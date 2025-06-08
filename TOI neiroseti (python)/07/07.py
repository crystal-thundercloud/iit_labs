from cmath import sqrt
import numpy as np
import matplotlib.pyplot as plt

def train(weights, data):
    for i in range(len(weights)):
        weights[i] += data[i] * data[i]
    normalize(weights)
        
def normalize(weights):
    sum = 0
    for i in range(len(weights)):
        sum += weights[i] * weights[i]
    
    magnitude = sqrt(sum)
    
    for i in range(len(weights)):
        weights[i] /= magnitude
        
def output(weights, data):
    out = 0
    for i in range(len(data)):
        out += data[i] * weights[i]
    
    return out

weights = np.zeros((2), dtype=np.float64)

data = np.array((
    [1, 0],
    [0, 1],
    [1, 1]
))
for data in data:
    train(weights, data)

plt.figure("Distribution")

colors = np.array(["violet", "darkorchid", "indigo", "blue", "dodgerblue", "cyan", "lightseagreen", "green", "limegreen", "lime", "greenyellow", "yellow", "orange", "red", "magenta", "pink", "gray", "black"])
stepsx = np.arange(0, 20.6, 0.5)
stepsy = np.arange(0, 4.1, 0.1)
for x in stepsx:
    for y in stepsy:
        vector = np.array([x, y])
        out = round(output(weights, vector))
        
        plt.plot(x, y, "o", color = colors[out]) # в разы быстрее, чем scatter
        # o значит маркер, а не линия
        
        # print(f"Vector: {vector} - length claster: {out}")

plt.show()
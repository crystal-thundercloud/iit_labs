import numpy as np
import matplotlib.pyplot as plt
import networkx as nx

cities = 5

d = np.zeros((cities,cities))

for i in range (cities):
    for j in range(i, cities):
        if (i == j): d[i, j] = 0;
        else:
            rand = np.random.randint(1, 20)
            d[i, j] = rand
            d[j, i] = rand

G = nx.from_numpy_array(d, create_using=nx.DiGraph)
layout = nx.spring_layout(G)

plt.figure("Исходный граф")
plt.title("Исходный граф")

nx.draw(G, layout, edge_color = 'blue', with_labels=True, font_color="white")
labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos=layout, edge_labels=labels)

class GeneticAlgorithm:
    cities: int
    maxGenerationsNum: int
    mutationRate: float
    populationSize: int
    printStep: int
    population: int
    
    def __init__(self, cities, maxGenerationsNum, mutationRate, populationSize, printStep = 0):
        self.cities = cities
        self.maxGenerationsNum = maxGenerationsNum
        self.mutationRate = mutationRate
        self.populationSize = populationSize
        self.printStep = printStep
        self.population = np.zeros((populationSize, len(cities)))
        
        for i in range(populationSize):
            # массив из идущих подряд значений от 0 до x с шагом n (по умолчанию 1) 
            row = np.arange(0, len(cities), dtype=int)
            # перетасовка элементов созданного массива
            np.random.shuffle(row)
            self.population[i] = row

    def FindBestSolution(self):
        for gen in range (self.maxGenerationsNum + 1):
            # сортировка строк массива по значению, получнному при применении функции к каждой строке
            self.population = np.array(sorted(self.population, key = lambda x: self.RoutLength(x)))
            newPopulation = np.zeros((len(self.population), len(self.population[0])))
            for i in range (self.populationSize):
                child = self.Recombinate(self.SelectParent(self.population), self.SelectParent(self.population))
                child = self.Mutate(child)
                newPopulation[i] = child
            self.population = newPopulation
            if (self.printStep != 0 and gen % self.printStep == 0): self.PrintCurrentState(gen)
        
        bestRoute = sorted(self.population, key = lambda x: self.RoutLength(x))[0]
        # в конце возврат в исходную вершину
        bestRoute = np.append(bestRoute, bestRoute[0])
        return(bestRoute, self.RoutLength(bestRoute))

    def SelectParent(self, population):
        sliceSize = 10
        selection = np.zeros((sliceSize, len(population[0])))
        for i in range (sliceSize):
            selection[i] = population[np.random.randint(0, self.populationSize)]
        
        sortedSelection = sorted(selection, key = lambda x: self.RoutLength(x))
        return sortedSelection[0]

    def Recombinate(self, parent1, parent2):
        child = np.zeros((len(parent1)))
        startPos = np.random.randint(0, len(parent1) - 1)
        endPos = np.random.randint(startPos, len(parent1))
        
        for i in range (startPos, endPos):
            child[i] = parent1[i]
        
        curPos = endPos % len(parent1)
        for gen in parent2:
            if (gen not in child):
                child[curPos] = gen
                curPos = (curPos + 1) % len(parent1)
        
        return child

    def Mutate(self, chromosome):
        if (np.random.rand() < self.mutationRate):
            index1 = np.random.randint(0, len(chromosome))
            index2 = np.random.randint(0, len(chromosome))
            chromosome[index1], chromosome[index2] = chromosome[index2], chromosome[index1]
        return chromosome

    def RoutLength(self, route):
        length = 0
        for i in range (len(route)):
            if (i == len(route) - 1): length += self.cities[int(route[i]), int(route[0])]
            else: length += self.cities[int(route[i]), int(route[i+1])]
        return length
    
    def PrintCurrentState(self, generationsNum):
        bestRoute = sorted(self.population, key = lambda x: self.RoutLength(x))[0]
        # в конце возврат в исходную вершину
        bestRoute = np.append(bestRoute, bestRoute[0])
        print("Поколение ", generationsNum, ": Лучший маршрут = ", bestRoute, " длины ", self.RoutLength(bestRoute))

ga = GeneticAlgorithm(d, 2000, 0.15, 20, 500)
best = ga.FindBestSolution()
bestRoute = best[0]

print("Лучший маршрут = ", bestRoute, " длины ", best[1])

result = np.zeros((cities, cities))

for i in range (cities):
    result[int(bestRoute[i]), int(bestRoute[i+1])] = d[int(bestRoute[i]), int(bestRoute[i+1])]

G = nx.from_numpy_array(result, create_using=nx.DiGraph)
plt.figure("Наилучший путь") # новое окно с заголовком
plt.title("Наилучший путь")

color_map = []
for i in range (len(result)):
    if (i == bestRoute[0]): color_map.append("green") # стартовая позиция
    else: color_map.append("blue")

nx.draw(G, layout, node_color=color_map, edge_color = 'blue', with_labels=True, font_color="white")
labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos=layout, edge_labels=labels)

plt.show()
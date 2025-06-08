from copy import copy
import numpy as np

def sigmoid(x): # функция активации - сигмоид
    return 1 / (1 + np.exp(-x)) # f(x) = 1 / (1 + e^(-x))

def psigmoid(x): # производная сигмоида
    fx = sigmoid(x)
    return fx * (1 - fx) # f'(x) = f(x) * (1 - f(x))

def mse_loss(y_true, y_pred):
    # y_true и y_pred - массивы numpy одинаковой длины.
    return ((y_true - y_pred) ** 2).mean()

class Neuron:
    def __init__(self, weights, bias):
        self.weights = weights # массив весов, его длина = количество входов
        self.bias = bias # смещение
        self.sum = 0 # сумма до применение функции
        self.out = 0 # выходное значение

    def feedforward(self, inputs): # процесс передачи входов вперёд, чтобы получить выход
        sum = np.dot(self.weights, inputs) + self.bias # (x1*w1) + (x2*w2) + b
        self.sum = sum
        self.out = sigmoid(sum)
        return sigmoid(sum)
    
    def updateWeights(self, x, plypred, learnRate, outputNeuron, curNeuronNum):
        pypredh = outputNeuron.weights[curNeuronNum] * psigmoid(outputNeuron.sum)
        for i in range(len(self.weights)):
            weight = weights[i]
            phpw = x[i] * psigmoid(self.sum)
            weight += learnRate * plypred * pypredh * phpw
        
        phpb = psigmoid(self.sum)
        self.bias += learnRate * plypred * pypredh * phpb
        
        

class NeuralNetwork:
    def __init__(self, hiddenLayers, outputLayer):
        self.hiddenLayers = hiddenLayers
        self.outputLayer = outputLayer
        
    def feedforward(self, inputArray):
        values = inputArray
        for layer in self.hiddenLayers:
            for i in range (len(layer)):
                neuron = layer[i]
                values[i] = neuron.feedforward(values)
        
        result = self.outputLayer.feedforward(values)
        return result
    
    def train(self, inputArrayOrig, correctAnswers):
        learnRate = 0.1 # скорость обучения
        epochs = 1000 # количество циклов прохождения по входящим данным
        
        for epoch in range (epochs):
            inputArray = copy(inputArrayOrig)
            for x, correctAnswer in zip(inputArray, correctAnswers):
                o1 = self.feedforward(x)
                ypred = o1
                p_L_p_ypred = -2 * (correctAnswer - ypred)
                for layer in self.hiddenLayers:
                    for i in range (len(layer)):
                        neuron = layer[i]
                        pypredpw = neuron.out * psigmoid(self.outputLayer.sum)
                        neuron.updateWeights(x, p_L_p_ypred, learnRate, self.outputLayer, i)
                        self.outputLayer.weights[i] += learnRate * p_L_p_ypred * pypredpw
                pypredb = psigmoid(self.outputLayer.sum)
                self.outputLayer.bias += learnRate * p_L_p_ypred * pypredb
                        
            if epoch % 10 == 0:
                y_preds = np.apply_along_axis(self.feedforward, 1, inputArray)
                loss = mse_loss(correctAnswers, y_preds)
                print("Epoch %d loss: %.3f" % (epoch, loss))  
                
    
############################################################### СОЗДАНИЕ ОДНОГО НЕЙРОНА
weights = np.array([0, 1], dtype=np.float64) # w1 = 0, w2 = 1
bias = 4                   # b = 4
n = Neuron(weights, bias)

x = np.array([2, 3], dtype=np.float64)       # x1 = 2, x2 = 3
# f для печати переменных внутри строки
# 0.9990889488055994
print(f"работа одного нейрона с весами {weights} и смещением {bias}: ", n.feedforward(x))

############################################################### СОЗДАНИЕ НЕЙРОСЕТИ ИЗ ДВУХ СКРЫТЫХ НЕЙРОНОВ И ОДНОГО ВЫХОДНОГО
nn0 = NeuralNetwork(np.array([np.full(2, Neuron(weights, 0))]), Neuron(weights, 0))
# 0.7216325609518421
print(f"работа нейронной сети из двух нейронов с весами {weights} и смещением 0: ", nn0.feedforward(x))

############################################################### ФУНКЦИЯ КВАДРАТИЧНОЙ ОШИБКИ
y_true = np.array([1, 0, 0, 1])
y_pred = np.array([0, 0, 0, 0])
# 0.5
print("работа функции подсчёта средней квадратичной ошибки: ", mse_loss(y_true, y_pred))

############################################################### ОБУЧЕНИЕ НЕЙРОСЕТИ ИЗ ДВУХ СКРЫТЫХ НЕЙРОНОВ И ОДНОГО ВЫХОДНОГО
neurons = np.empty((2), dtype=Neuron) # 2 нейрона в слое
weights = np.empty((2), dtype=np.float64) # 2 входа в нейроне

for i in range (len(neurons)): #каждому нейрону случайные веса и смещения
    for j in range (len(weights)):
        weights[j] = np.random.normal()
    neurons[i] = Neuron(weights, np.random.normal())

layers = np.array([neurons])

for weight in weights:
    weight = np.random.normal()
outputNeuron = Neuron(weights, np.random.normal())

nn1 = NeuralNetwork(layers, outputNeuron)

data = np.array([
  [-2, -1],  # Alice
  [25, 6],   # Bob
  [17, 4],   # Charlie
  [-15, -6], # Diana
], dtype=np.float64)

all_y_trues = np.array([
  1, # Alice
  0, # Bob
  0, # Charlie
  1, # Diana
])

nn1.train(data, all_y_trues)
emily = np.array([-7, -3]) # 128 pounds, 63 inches
frank = np.array([20, 2])  # 155 pounds, 68 inches
print("Emily: %.3f" % nn1.feedforward(emily)) # 0.951 - F
print("Frank: %.3f" % nn1.feedforward(frank)) # 0.039 - M

# test = np.array([Neuron(weights, 0)]*5) # одинаковые объекты
# test2 = np.full(5, Neuron(weights, 0)) # одинаковые объекты?
# test3 = np.array([np.full(5, 2), np.full(5, 2)]) # массив из массивов из одинаковых объектов
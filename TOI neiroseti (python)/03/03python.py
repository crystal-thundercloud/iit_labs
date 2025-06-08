import numpy as np
from numpy import inf
import matplotlib.pyplot as plt
import networkx as nx

#задаем значения.
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

iteration = 100
n_ants = cities
n_cities = cities

# инициализация
m = n_ants
n = n_cities
#скорость испарения
e = .5

#коэффициент феромона (феромон относится к оставшейся информации на каждом пути, по которому проходят муравьи)
alpha = 1
#коэффициент видимости (видимость обозначает обратное расстояние между узлами)
beta = 2

#вычисление видимости следующего города visibility(1,3)=1/d(1,3)
visibility = 1/d
visibility[visibility == inf ] = 0

#инициализация феромона на дорожках, ведущих в города
pheromne = .1*np.ones((m, n))

#инициализация маршрута муравьев с длиной пути (n_ants,n_citys+1
#добавляем 1, потому что планируем вернуться в исходный город

rute = np.ones((m,n+1))
for ite in range(iteration):
    #начальное и конечное положение каждого муравья '1', то есть города "1"
    rute[:,0] = 1
    
    for i in range(m):
        #создание копии видимости (обратного расстояния между узлами)
        temp_visibility = np.array(visibility)
        
        for j in range(n-1):
            
            #обнуляем массив вероятностей com_prob
            combine_feature = np.zeros(5) 
            
            #обнуляем массив характеристик combine feature
            com_prob = np.zeros(5)
            
            #текущий город муравья
            cur_loc = int(rute[i,j]-1)
            
            #обнуляем видимость текущего города
            temp_visibility[:, cur_loc] = 0
            
            #вычисление характеристик феромона
            p_feature = np.power(pheromne[cur_loc,:], beta)
            
            #вычисление характеристик видимости
            v_feature = np.power(temp_visibility[cur_loc,:], alpha)
            
            #добавление оси для получения длины [cities,1]
            p_feature = p_feature[:, np.newaxis]
            
            #добавление оси для получения длины [cities,1]
            v_feature = v_feature[:, np.newaxis]
            
            #вычисление комбинированной функции
            combine_feature = np.multiply(p_feature,v_feature)
            
            #сумма всех характеристик
            total = np.sum(combine_feature)
            
            #нахождение вероятности элемента probs(i) - comine_feature(i)/total
            probs = combine_feature/total
            
            #вычисление общей суммы.
            com_prob = np.cumsum(probs)
            
            #случайное число в [0,1)
            r = np.random.random_sample()
            
            #поиск следующего города с вероятностью выше случайной random(г)
            city = np.nonzero(com_prob>r)[0][0]+1
            
            #добавление города в маршрут
            rute[i,j+1] = city
            
    #поиск последнего непройденного города в общем маршруте
    left = list(set([i for i in range(1,n+1)])-set(rute[i,:-2]))[0]
    
    #добавление непройденного города в маршрут
    rute[i,-2] = left
    
#инициализация оптимального маршрута
rute_opt = np.array(rute)

#обнуление total_distance_of_tour
dist_cost = np.zeros((m,1))

for i in range(m):
    s = 0
    
    for j in range(n-1):
        #вычисление общей длины маршрута
        s = s + d[int(rute_opt[i,j])-1,int(rute_opt[i,j+1])-1]
        
        #сохранение длины дистанции для 'i'-го муравья в позиции 'i'
        dist_cost[i] = s
        
    #нахождение позиции минимума dist_cost
    dist_min_loc = np.argmin(dist_cost)
    
    #определение минимального значения dist_cost
    dist_min_cost = dist_cost[dist_min_loc]
    
    #выбор текущего пройденного маршрута как наилучшего #испарение феромона путем (1-е)
    best_route = rute[dist_min_loc,:]
    
    # исправение феромона (1 - e)
    pheromne = (1-e)*pheromne

    for i in range(m):
        for i in range(n-1):
            dt = 1/dist_cost[1]
            pheromne[int(rute_opt[i,j])-1,int(rute_opt[i,j+1])-1] = pheromne[int(rute_opt[i,j])-1,int(rute_opt[i,j+1])-1] + dt
            #обновление феромона с помощью delta_distance
            #delta_distance увеличится с min_dist, т.е. добавит больше веса этому маршруту на единицу пути

result = np.zeros((cities,cities))

for i in range (cities):
    result[int(best_route[i]-1), int(best_route[i+1]-1)] = d[int(best_route[i]-1), int(best_route[i+1]-1)]
    # result[int(best_route[i+1]-1), int(best_route[i]-1)] = d[int(best_route[i+1]-1), int(best_route[i]-1)] # чтобы граф не был двунаправленным

# plt.clf() # очистка окна

G = nx.from_numpy_array(result, create_using=nx.DiGraph)
plt.figure("Наилучший путь") # новое окно с заголовком
plt.title("Наилучший путь")

color_map = []
for i in range (len(result)):
    if (i == 0): color_map.append("green") # стартовая позиция
    else: color_map.append("blue")

nx.draw(G, layout, node_color=color_map, edge_color = 'blue', with_labels=True, font_color="white")
labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos=layout, edge_labels=labels)

print("Наилучший путь:", best_route)
print("Стоимость наилучшего пути",int(dist_min_cost[0]) + d[int(best_route[-2])-1,0])

plt.show() # один раз в конце, чтобы показать все окна одновременно

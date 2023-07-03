import networkx as nx
import random
import time
import matplotlib.pyplot as plt

vertex_counts = [500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 10000]  # Cписок количества вершин
time_records = []

#Cоздание списка ребер для графа без петель и кратных ребер, вследствие чего временная сложность удаления 1 ребра будет квадратичной
for vertex_count in vertex_counts:
    edge_list = [(i, j) for i in range(vertex_count) for j in range(i + 1, vertex_count)]
    random.shuffle(edge_list)

    G = nx.Graph()  # Создаем граф
    G.add_edges_from(edge_list)

    print(edge_list[0:20])

    while True:
        print("Введите ребро для удаления из грфара с числом вершин: ", vertex_count)
        edge_to_remove = tuple(map(int, input().split(" ")))

        if nx.has_path(G, edge_to_remove[0], edge_to_remove[1]):
            break
        else:
            print("Такого ребра не существует")

    start_time = time.time()
    G.remove_edge(edge_to_remove[0], edge_to_remove[1]) # Удаляем выбранное ребро и замеряем время
    end_time = time.time()
    node_removal_time = end_time - start_time
    print(end_time)

    start_time = time.time()
    sorted_vertices = sorted(G.nodes(), key=lambda x: G.degree(x), reverse=False) # сортируем по возрастанию
    end_time = time.time()
    sorting_time = end_time - start_time
    print(sorting_time)
    total_time = sorting_time + node_removal_time
    time_records.append(total_time)  # Добавляем общее время выполнения в список

plt.plot(vertex_counts, time_records) # Построим график времени выполнения в зависимости от количества вершин
plt.xlabel('Кол-во вершин')
plt.ylabel('Время в секундах')
plt.title('Зависимость времени от количества')
plt.show()
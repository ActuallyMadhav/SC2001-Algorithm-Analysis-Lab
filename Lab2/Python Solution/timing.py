import time
import random
import sys
from tabulate import tabulate
import dijkstraA as partA
import dijkstraB as partB

# Graph generators
def generate_adj_matrix(V, edge_prob=0.2, max_weight=10):
    INF = sys.maxsize
    matrix = [[INF] * V for _ in range(V)]
    for i in range(V):
        matrix[i][i] = 0
        for j in range(V):
            if i != j and random.random() < edge_prob:
                matrix[i][j] = random.randint(1, max_weight)
    return matrix

def generate_adj_list(V, edge_prob=0.2, max_weight=10):
    adjList = [[] for _ in range(V)]
    for u in range(V):
        for v in range(V):
            if u != v and random.random() < edge_prob:
                weight = random.randint(1, max_weight)
                adjList[u].append((v, weight))
    return adjList

# Benchmarking
def benchmark():
    results = []
    for V in [100, 200, 400, 800]:
        adjMatrix = generate_adj_matrix(V)
        adjList = generate_adj_list(V)

        start = time.time()
        partA.dijkstra_AdjMat(adjMatrix, 0)
        adjmat_time = time.time() - start

        start = time.time()
        partB.dijkstra_MinHeap(adjList, 0)
        minheap_time = time.time() - start

        results.append([V, f"{adjmat_time:.5f}", f"{minheap_time:.5f}"])

    headers = ["Vertices (V)", "AdjMatrix Time (s)", "MinHeap Time (s)"]
    print(tabulate(results, headers=headers, tablefmt="grid"))


benchmark()
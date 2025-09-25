import sys
import heapq

def dijkstra_MinHeap(adjList, source):
    INF = sys.maxsize
    V = len(adjList)
    dist = [INF] * V
    dist[source] = 0

    # priority queue
    pq = [(0, source)]

    while pq:
        d_u, u = heapq.heappop(pq)

        if d_u > dist[u]:
            continue
        for v, weight in adjList[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))
    
    for i in range(V):
        print(f"Distance to {i}: {dist[i]}")
###########################################################

if __name__ == "__main__":
    # Define infinity
    INF = float('inf')

    # Sample graph as adjacency list
    # Each entry adj_list[u] contains (v, weight) pairs for edges u → v
    adj_list = [
        [(1, 4), (7, 8)],              # Node 0
        [(0, 4), (2, 8), (7, 11)],     # Node 1
        [(1, 8), (3, 7), (5, 4), (8, 2)],  # Node 2
        [(2, 7), (4, 9), (5, 14)],     # Node 3
        [(3, 9), (5, 10)],             # Node 4
        [(2, 4), (3, 14), (4, 10), (6, 2)],  # Node 5
        [(5, 2), (7, 1), (8, 6)],      # Node 6
        [(0, 8), (1, 11), (6, 1), (8, 7)],  # Node 7
        [(2, 2), (6, 6), (7, 7)]       # Node 8
    ]

    source_node = 0
    print(f"Running Dijkstra from source node {source_node}:\n")
    dijkstra_MinHeap(adj_list, source_node)

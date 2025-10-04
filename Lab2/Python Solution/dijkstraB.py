import sys
import heapq
import visualisation as vs

def dijkstra_MinHeap(adjList, source):
    INF = sys.maxsize
    V = len(adjList)
    dist = [INF] * V
    pi = [-1] * V
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
                pi[v] = u
                heapq.heappush(pq, (dist[v], v))
    
    # for i in range(V):
    #     print(f"Distance to {i}: {dist[i]}")
    
    return dist, pi
###########################################################

if __name__ == "__main__":
    adj_list = [
        [(1, 4), (7, 8)],
        [(0, 4), (2, 8), (7, 11)],
        [(1, 8), (3, 7), (5, 4), (8, 2)],
        [(2, 7), (4, 9), (5, 14)],
        [(3, 9), (5, 10)],
        [(2, 4), (3, 14), (4, 10), (6, 2)],
        [(5, 2), (7, 1), (8, 6)],
        [(0, 8), (1, 11), (6, 1), (8, 7)],
        [(2, 2), (6, 6), (7, 7)]
    ]

    source = 0
    dist, prev = dijkstra_MinHeap(adj_list, source)
    vs.visualize_graphB(adj_list, dist, prev, source)


    for target in range(len(adj_list)):
        path = vs.reconstruct_path(prev, target)
        print(f"Shortest path to {target}: {' -> '.join(map(str, path))} (Distance: {dist[target]})")


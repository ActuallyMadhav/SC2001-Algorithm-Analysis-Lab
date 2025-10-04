import sys
import visualisation as vs

def dijkstra_AdjMat(adjMatrix, source):
    INF = sys.maxsize
    V = len(adjMatrix)
    dist = [INF] * V
    visited = [False] * V
    pi = [-1] * V  

    dist[source] = 0

    for _ in range(V - 1):
        u = -1
        for j in range(V):
            if not visited[j] and (u == -1 or dist[j] < dist[u]):
                u = j 

        if u == -1:
            break  

        visited[u] = True

        for v in range(V):
            if not visited[v] and adjMatrix[u][v] != INF:
                if dist[u] + adjMatrix[u][v] < dist[v]:
                    dist[v] = dist[u] + adjMatrix[u][v]
                    pi[v] = u  

    # for k in range(V):
    #     print(f"Distance to {k}: {dist[k]}")

    return dist, pi

###########################################################################

if __name__ =="__main__":
    INF = float('inf')
    graph = [
        [0, 4, INF, INF, INF, INF, INF, 8, INF],
        [4, 0, 8, INF, INF, INF, INF, 11, INF],
        [INF, 8, 0, 7, INF, 4, INF, INF, 2],
        [INF, INF, 7, 0, 9, 14, INF, INF, INF],
        [INF, INF, INF, 9, 0, 10, INF, INF, INF],
        [INF, INF, 4, 14, 10, 0, 2, INF, INF],
        [INF, INF, INF, INF, INF, 2, 0, 1, 6],
        [8, 11, INF, INF, INF, INF, 1, 0, 7],
        [INF, INF, 2, INF, INF, INF, 6, 7, 0]
    ]
    source = 0
    dist, prev = dijkstra_AdjMat(graph, source)
    vs.visualize_graphA(graph, dist, prev, source)


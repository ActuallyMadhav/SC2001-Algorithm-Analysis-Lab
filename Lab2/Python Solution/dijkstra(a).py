import sys

def dijkstra_AdjMat(adjMatrix, source):
    V = len(adjMatrix)
    dist = [sys.maxsize] * V
    visited = [False] * V

    dist[source] = 0

    for i in range(V-1):
        u = -1
        for j in range(V):
            if not visited[j] and (u == -1 or dist[j] < dist[u]):
                u = i
        
        visited[u] =  True

        for v in range(V):
            if not visited[v] and adjMatrix[u][v] != sys.maxsize:
                dist[v] = min(dist[v], dist[u] + adjMatrix[u][v])
    
    for k in range(V):
        print(f"Distance to {k}: {dist[k]}")
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
    dijkstra_AdjMat(graph, source = 0)



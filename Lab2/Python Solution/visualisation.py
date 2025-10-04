import networkx as nx
import matplotlib.pyplot as plt
import sys

def reconstruct_path(prev, target):
    path = []
    while target != -1:
        path.append(target)
        target = prev[target]
    return path[::-1]  # reverse the path
#######################################################################################

def visualize_graphA(adjMatrix, dist, prev, source):
    V = len(adjMatrix)
    G = nx.DiGraph()

    # Add all edges with weights
    for u in range(V):
        for v in range(V):
            if adjMatrix[u][v] != float('inf') and u != v:
                G.add_edge(u, v, weight=adjMatrix[u][v])

    pos = nx.spring_layout(G, seed=42)

    # Draw base graph
    nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=800, font_size=10)
    edge_labels = {(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

    # Collect all shortest path edges
    shortest_edges = []
    for target in range(V):
        if target == source or dist[target] == float('inf'):
            continue
        path = reconstruct_path(prev, target)
        shortest_edges += list(zip(path[:-1], path[1:]))

    # Draw shortest path edges in red
    nx.draw_networkx_edges(G, pos, edgelist=shortest_edges, edge_color='red', width=2)

    plt.title(f"Shortest Paths from Node {source}")
    plt.show()
#######################################################################################

def visualize_graphB(adj_list, dist, prev, source):
    G = nx.DiGraph()

    # Add edges from adjacency list
    for u, edges in enumerate(adj_list):
        for v, weight in edges:
            G.add_edge(u, v, weight=weight)

    pos = nx.spring_layout(G, seed=42)  # layout for consistent positioning

    # draw nodes and edges
    nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=800, font_size=10)
    edge_labels = {(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

    # highlight shortest paths from source
    for target in range(len(adj_list)):
        if target == source or dist[target] == sys.maxsize:
            continue
        path = reconstruct_path(prev, target)
        path_edges = list(zip(path[:-1], path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=2)

    plt.title(f"Shortest Paths from Node {source}")
    plt.show()
#######################################################################################

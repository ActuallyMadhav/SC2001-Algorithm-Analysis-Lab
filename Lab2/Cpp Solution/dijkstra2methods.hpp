#ifndef DIJKSTRA2METHODS_HPP
#define DIJKSTRA2METHODS_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <fstream>
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////
// part (a) - using adjacency matrix

std::pair<std::vector<int>, std::vector<int>> dijkstra_AdjMatrix(const std::vector<std::vector<int>>& adjMatrix, int source){
    int V = adjMatrix.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false); 
    std::vector<int> pi(V, -1); // predecessor array

    dist[source] = 0;

    for(int count = 0; count < V - 1; count++){
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!visited[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }

        if (u == -1) break; // All remaining nodes are unreachable

        visited[u] = true;

        for(int v = 0; v < V; v++){
            if(!visited[v] && adjMatrix[u][v] != INT_MAX){
                if(dist[u] + adjMatrix[u][v] < dist[v]){
                    dist[v] = dist[u] + adjMatrix[u][v];
                    pi[v] = u;
                }
            }
        }
    }

    for(int i = 0; i < V; i++){
        printf("Distance to %d: %d\n", i, dist[i]);
        std::vector<int> path;
        for(int v = i; v != -1; v = pi[v])
            path.push_back(v);
        std::reverse(path.begin(), path.end());
        printf("Path: ");
        for(int v : path)
            printf("%d ", v);
        printf("\n");
    }

    return {dist, pi};
}

///////////////////////////////////////////////////////////////////////////////
// part (b) - using min heap and adjacency list

std::pair<std::vector<int>, std::vector<int>> dijkstra_MinHeap(const std::vector<std::vector<std::pair<int, int>>>& adjList, int source){
    int V = adjList.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<int> pi(V, -1); // predecessor array

    // this is the min heap
    std::priority_queue<
        std::pair<int,int>,     // type of elements stored
        std::vector<std::pair<int, int>>,       // underlying container (vector)
        std::greater<>      // comparison function
    > pq; // name of the priority queue

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if(d_u > dist[u]){
            continue;
        }

        //for( auto [v, weight] : adjList[u]){     // this feature is only C++17 and up (structured binding)
        for(const auto& edge : adjList[u]){        // for C++14 and below, need to declare using .first and .second
            int v = edge.first;
            int weight = edge.second;
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < V; i++){
        printf("Distance to %d: %d\n", i, dist[i]);
        std::vector<int> path;
        for(int v = i; v != -1; v = pi[v])
            path.push_back(v);
        std::reverse(path.begin(), path.end());
        printf("Path: ");
        for(int v : path)
            printf("%d ", v);
        printf("\n");
    }

    return {dist, pi};
}

///////////////////////////////////////////////////////////////////////////////
// visualisation for part(A)
void exportToDot_AdjMatrix(const std::vector<std::vector<int>>& adjMatrix, const std::vector<int>& pi, const std::string& filename) {
    std::ofstream out(filename);
    out << "digraph G {\n";
    out << "  node [shape=circle, style=filled, fillcolor=lightblue];\n";

    int V = adjMatrix.size();
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (adjMatrix[u][v] != INT_MAX && u != v) {
                bool isShortestEdge = (pi[v] == u);
                out << "  " << u << " -> " << v << " [label=\"" << adjMatrix[u][v] << "\"";
                if (isShortestEdge) out << ", color=red, penwidth=2.0";
                out << "];\n";
            }
        }
    }

    out << "}\n";
    out.close();
}

///////////////////////////////////////////////////////////////////////////////
// visualisation for part(B)
void exportToDot_AdjList(const std::vector<std::vector<std::pair<int, int>>>& adjList, const std::vector<int>& pi, const std::string& filename) {
    std::ofstream out(filename);
    out << "digraph G {\n";
    out << "  node [shape=circle, style=filled, fillcolor=lightblue];\n";

    int V = adjList.size();
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            bool isShortestEdge = (pi[v] == u);
            out << "  " << u << " -> " << v << " [label=\"" << weight << "\"";
            if (isShortestEdge) out << ", color=red, penwidth=2.0";
            out << "];\n";
        }
    }

    out << "}\n";
    out.close();
}


#endif
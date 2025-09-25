#ifndef DIJKSTRA2METHODS_HPP
#define DIJKSTRA2METHODS_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// part (a) - using adjacency matrix

void dijkstra_AdjMatrix(const std::vector<std::vector<int>>& adjMatrix, int source){
    int V = adjMatrix.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false); 

    dist[source] = 0;

    for(int count = 0; count < V - 1; count++){
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!visited[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }
        visited[u] = true;

        for(int v = 0; v < V; v++){
            if(!visited[v] && adjMatrix[u][v] != INT_MAX){
                dist[v] = std::min(dist[v], dist[u] + adjMatrix[u][v]);
            }
        }

    }

    for(int i = 0; i < V; i++){
        printf("Distance to %d: %d\n", i, dist[i]);
    }
}

// part (b) - using min heap and adjacency list

void dijkstra_MinHeap(const std::vector<std::vector<std::pair<int, int>>>& adjList, int source){
    int V = adjList.size();
    std::vector<int> dist(V, INT_MAX);

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
    }
}


#endif
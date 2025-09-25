#include "dijkstra2methods.hpp"
#include <iostream>

int main(){
    const int INF = INT_MAX;

    //////////////// PART (A) ////////////////////////
    std::vector<std::vector<int>> adjMatrix = {
        {0, 2, INF, 1},
        {2, 0, 3, INF},
        {INF, 3, 0, 4},
        {1, INF, 4, 0}
    };

    int source1 = 0;

    dijkstra_AdjMatrix(adjMatrix, source1);

    //////////////// PART (B) ////////////////////////
    std::vector<std::vector<std::pair<int, int>>> adjList = {
        {{1, 2}, {3, 1}},     // Node 0
        {{0, 2}, {2, 3}},     // Node 1
        {{1, 3}, {3, 4}},     // Node 2
        {{0, 1}, {2, 4}}      // Node 3
    };

    int source2 = 0;

    dijkstra_MinHeap(adjList, source2);

    return 0;
}
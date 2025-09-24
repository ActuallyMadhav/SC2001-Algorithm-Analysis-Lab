#include "dijkstra2methods.hpp"
#include <iostream>

int main(){
    const int INF = INT_MAX;
    std::vector<std::vector<int>> adjMatrix = {
        {0, 2, INF, 1},
        {2, 0, 3, INF},
        {INF, 3, 0, 4},
        {1, INF, 4, 0}
    };

    int source = 0;

    dijkstra_AdjMatrix(adjMatrix, source);
    return 0;
}
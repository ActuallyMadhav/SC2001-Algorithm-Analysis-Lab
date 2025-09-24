#include "dijkstra2methods.hpp"
#include <iostream>

int main(){
    const int INF = INT_MAX;
    std::vector<std::vector<int>> graph = {
        {0, 4, INF, INF, INF, INF, INF, 8, INF},
        {4, 0, 8, INF, INF, INF, INF, 11, INF},
        {INF, 8, 0, 7, INF, 4, INF, INF, 2},
        {INF, INF, 7, 0, 9, 14, INF, INF, INF},
        {INF, INF, INF, 9, 0, 10, INF, INF, INF},
        {INF, INF, 4, 14, 10, 0, 2, INF, INF},
        {INF, INF, INF, INF, INF, 2, 0, 1, 6},
        {8, 11, INF, INF, INF, INF, 1, 0, 7},
        {INF, INF, 2, INF, INF, INF, 6, 7, 0}
    };

    int source = 0;

    dijkstra_AdjMatrix(graph, source);
    return 0;
}
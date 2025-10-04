#include "dijkstra2methods.hpp"
#include <iostream>

int main() {
    int source = 0;

    // -------------------- Adjacency Matrix --------------------
    std::vector<std::vector<int>> adjMatrix = {
        {0, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX},
        {4, 0, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX},
        {INT_MAX, 8, 0, 7, INT_MAX, 4, INT_MAX, INT_MAX, 2},
        {INT_MAX, INT_MAX, 7, 0, 9, 14, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 9, 0, 10, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 4, 14, 10, 0, 2, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2, 0, 1, 6},
        {8, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, 0, 7},
        {INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX, 6, 7, 0}
    };

    auto [distMatrix, piMatrix] = dijkstra_AdjMatrix(adjMatrix, source);
    exportToDot_AdjMatrix(adjMatrix, piMatrix, "adjMatrix.dot");

    // -------------------- Adjacency List --------------------
    std::vector<std::vector<std::pair<int, int>>> adjList = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {2, 8}, {7, 11}},
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}},
        {{2, 7}, {4, 9}, {5, 14}},
        {{3, 9}, {5, 10}},
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
        {{5, 2}, {7, 1}, {8, 6}},
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
        {{2, 2}, {6, 6}, {7, 7}}
    };

    auto [distHeap, piHeap] = dijkstra_MinHeap(adjList, source);
    exportToDot_AdjList(adjList, piHeap, "adjList.dot");

    return 0;
}

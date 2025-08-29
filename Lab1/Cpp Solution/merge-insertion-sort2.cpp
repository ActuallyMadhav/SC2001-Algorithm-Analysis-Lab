#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::vector<int> generateArray(int size);
void insertionSort(std::vector<int>& arr, int n, int m);
void mergeSort(std::vector<int> arr, int n, int m);
void merge(std::vector<int>& arr, int n, int m);
void hybridSort(std::vector<int>& arr, int n, int m, int S);
int compare(int a, int b);
void printArray(std::vector<int>& arr, int size);


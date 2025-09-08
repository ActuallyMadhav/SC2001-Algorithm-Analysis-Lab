#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>

static long long comparisons = 0;

std::vector<int> generateRandomArray(int size, int max);
void printArr(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void mergeSort(std::vector<int>& arr, int left, int right);
void hybridSort(std::vector<int>& arr, int left, int right, int S);

int main(){

    srand(time(NULL));

    return 0;
}

// generate random array
std::vector<int> generateRandomArray(int size, int max){
    std::vector<int> randArr(size);
    for(int i = 0; i < size; i++){
        randArr[i] = rand() % max + 1;
    }
    return randArr;
}

void printArr(std::vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << '\n';
    }
}

///////////////////////////// SORTING FUNCTIONS /////////////////////////////
void insertionSort(std::vector<int>& arr, int left, int right){
    for(int i = left + 1; i <= right; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= left && arr[j] > key){
            comparisons++;
            arr[j+1] = arr[j];
            j--;
        }
        if(j >= left){
            comparisons++;
        }
        arr[j+1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right){
    
}
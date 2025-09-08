#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>

// global variable to track across all functions
static long long comparisons = 0;

std::vector<int> generateRandomArray(int size, int max); // works
void printArr(std::vector<int>& arr); // works
void insertionSort(std::vector<int>& arr, int left, int right); // works
void merge(std::vector<int>& arr, int left, int mid, int right); // works
void mergeSort(std::vector<int>& arr, int left, int right); // works
void hybridSort(std::vector<int>& arr, int left, int right, int S); // works

int main(){

    srand(time(NULL));

    int size, maxVal, threshold;

    std::cout << "Enter array size: ";
    std::cin >> size;
    std::cout << "Enter max value: ";
    std::cin >> maxVal;
    std::cout << "Enter hybrid-sort threshold value: ";
    std::cin >> threshold;

    std::vector<int> arr = generateRandomArray(size, maxVal);
    printArr(arr);

    //clock start when sorting starts
    auto start = std::chrono::high_resolution_clock::now();
    hybridSort(arr, 0, arr.size()-1, threshold);
    
    //clock ends after sorting completed
    auto end = std::chrono::high_resolution_clock::now();

    // calculating time taken
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double timeTaken = duration.count() / 1000000.0;

    std::cout << '\n' << '\n';
    printArr(arr);

    std::cout << '\n';
    std::cout << "Time taken: " << timeTaken << '\n';
    std::cout << "# of comparisons: " << comparisons << '\n';

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
        std::cout << arr[i] << ' ';
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

void mergeSort(std::vector<int>&arr, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid); // recursive mergesort on left half
    mergeSort(arr, mid+1, right); // recursive mergesort on right half
    merge(arr, left, mid, right); // merging sorted halves
}

// merge function using temp array
void merge(std::vector<int>& arr, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);

    // building the left and right sub arrays

    for(int i = 0; i < leftSize; i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < rightSize; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    // sorting left and right sub arrays, then building them back into a completely sorted array
    int i = 0;
    int j = 0;
    int k = left;

    while(i < leftSize && j < rightSize){
        comparisons++;
        if(leftArr[i] <= rightArr[j]){
            arr[k++] = leftArr[i++];
        }
        else{
            arr[k++] = rightArr[j++];
        }
    }

    while(i < leftSize){
        arr[k++] = leftArr[i++];
    }

    while(j < rightSize){
        arr[k++] = rightArr[j++];
    }
}

void hybridSort(std::vector<int>& arr, int left, int right, int S){
    if(left >= right) return; // arr is empty or single element -> alr sorted

    int size = right - left + 1;

    if(size <= S){
        insertionSort(arr, left, right); // size < threshold -> insertion sort
    }
    else{
        int mid = left + (right - left) / 2;
        
        hybridSort(arr, left, mid, S);      // recursively hybrid sorted -> same logic as merge sort
        hybridSort(arr, mid+1, right, S);
        merge(arr, left, mid, right);
    }
}
#include <iostream>
#include "hybridSort.hpp" // see hybridSort.hpp for implementations of each function

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

    // test input (to compare with python)
    // [845, 13, 235, 608, 423, 467, 659, 698, 445, 457]
    // int threshold = 2;

    // std::vector<int> arr = {845, 12, 235, 608, 423, 467, 659, 698, 445, 457};

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

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <bits/stdc++.h>

void insertionSort(std::vector<int>& arr); // works
void mergeSort(std::vector<int>& arr);
void merge(std::vector<int>& leftArr, std::vector<int>& rightArr, std::vector<int>& arr);
std::vector<int> generateArr(int size);

int main(){
    


    return 0;
}


void insertionSort(std::vector<int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
}

void mergeSort(std::vector<int>& arr){
    
}

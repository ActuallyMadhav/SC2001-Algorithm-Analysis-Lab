#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void insertionSort(std::vector<int>& arr); // works
void mergeSort(std::vector<int>& arr);
void merge(std::vector<int>& leftArr, std::vector<int>& rightArr, std::vector<int>& arr);
std::vector<int> generateArr(int size);
void hybridSort(std::vector<int>& arr, int threshold);

int main(){
    


    return 0;
}

void hybridSort(std::vector<int>& arr, int threshold){
    int length = arr.size();
    int mid = length / 2;

    if(length <= 1){
        return;
    }
    else if(length > threshold){
        mergeSort(arr);
    }
    else{
        insertionSort(arr);
    }
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
    int length = arr.size();
    if(length <= 1) return;

    int middle = length / 2;

    std::vector<int> leftArr;
    std::vector<int> rightArr;

    for(int i = 0; i < length; i++){
        if(i < middle){
            leftArr[i] = arr[i];
        }
        else{
            rightArr[i-middle] = arr[i];
        }
    }

    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, arr);
}

void merge(std::vector<int>& leftArr, std::vector<int>& rightArr, std::vector<int>& arr){
    int leftSize = leftArr.size();
    int rightSize = rightArr.size();

    //indices
    int i = 0;
    int l = 0;
    int r = 0;

    while(l < leftSize && r < rightSize){
        if(leftArr[l] < rightArr[r]){
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        else{
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }

    while(l < leftSize){
        arr[i] = leftArr[l];
        i++;
        l++;
    }

    while(r < rightSize){
        arr[i] = rightArr[r];
        i++;
        r++;
    }
}

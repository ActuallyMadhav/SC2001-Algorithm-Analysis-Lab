import time

comparisons = 0

def compare(a, b):
    comparisons += 1
    if a > b:
        return 1
    elif a < b:
        return -1
    else:
        return 0
#end of function

def insertionSort(arr):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j] < arr[j-1]:
                arr[j] , arr[j-1] = arr[j-1], arr[j]
            else:
                break
    return
# end of function
 
def mergeSort(arr, n, m):
    mid = (n + m) // 2
    if (m-n) <= 0:
        return
    else:
        mergeSort(arr, n, mid)
        mergeSort(arr, mid + 1, m)
        merge(arr, n, m)
    return
# end of function

def merge(arr, n, m):
    mid = (n + m) // 2
    a = n
    b = mid + 1

    if (m - n) <= 0:
        return
    while a <= mid and b <= m:
        comp = compare(arr[a], arr[b])
        if comp > 0:
            b += 1
            temp = arr[b]
            mid += 1
            for i in range(mid, a, -1):
                arr[i] = arr[i-1]
            a += 1
            arr[a] = temp
        elif comp < 0:
            a += 1
        else:
            if a == mid and b == m:
                break
            b += 1
            temp = arr[b]
            a += 1
            mid += 1
            for i in range(mid, a, -1):
                arr[i] = arr[i-1]
            a += 1
            arr[a] = temp

def hybridSort(arr, n, m, S):
    return

if __name__ == '__main__':
    print("HI")
    for i in range(10, 5, -1):
        print(i)
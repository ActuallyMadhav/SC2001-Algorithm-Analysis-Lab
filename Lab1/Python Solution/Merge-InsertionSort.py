import random
import time

# Global variable for counting comparisons
comparisons = 0

# Sorting functions
def insertion_sort(arr):
    global comparisons
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            comparisons += 1 
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
            else:
                break

def merge_sort(arr, n, m):
    if m - n <= 0:
        return
    mid = (n + m) // 2
    merge_sort(arr, n, mid)
    merge_sort(arr, mid + 1, m)
    merge(arr, n, m)

def merge(arr, n, m):
    global comparisons
    mid = (m + n) // 2
    a = n
    b = mid + 1
    
    if m - n <= 0:
        return
    
    while a <= mid and b <= m:
        comp = compare(arr[a], arr[b])
        if comp > 0:
            temp = arr[b]
            b += 1
            for i in range(mid, a, -1):
                arr[i] = arr[i-1]
            arr[a] = temp
            a += 1
            mid += 1
        elif comp < 0:
            a += 1
        else:
            if a == mid and b == m:
                break
            temp = arr[b]
            b += 1
            a += 1
            for i in range(mid, a, -1):
                arr[i] = arr[i-1]
            arr[a] = temp
            mid += 1
            a += 1

def hybrid_sort(arr, n, m, S):
    if m - n <= 0:
        return
    mid = (n + m) // 2
    if m - n > S:
        hybrid_sort(arr, n, mid, S)
        hybrid_sort(arr, mid + 1, m, S)
        merge(arr, n, m)
    else:
        # Create a subarray for insertion sort
        sub_arr = arr[n:m+1]
        insertion_sort(sub_arr)
        # Copy back sorted subarray
        for i in range(n, m+1):
            arr[i] = sub_arr[i-n]

# Array generation functions
def generate_arr(size, max_val):
    return [random.randint(1, max_val) for _ in range(size)]

def print_arr(arr):
    for num in arr:
        print(num)

def compare(a, b):
    global comparisons
    comparisons += 1
    if a > b:
        return 1
    elif a < b:
        return -1
    else:
        return 0

def main():
    max_val = 10000000
    
    # Get user input
    try:
        size = int(input("Enter size of data (max 10e7): "))
        if size > max_val:
            print("Error: Exceeded Maximum Size Limit")
            return
        S = int(input("Threshold value: "))
    except ValueError:
        print("Error: Please enter valid integer values")
        return

    # Generate random array
    random.seed(time.time())
    test_data = generate_arr(size, max_val)
    print()

    # Sorting begins
    start = time.time()
    
    hybrid_sort(test_data, 0, len(test_data)-1, S)
    
    print()
    
    end = time.time()
    
    time_taken = end - start
    
    print(f"Time taken: {time_taken:.6f} seconds")
    print(f"Number of comparisons: {comparisons}")

if __name__ == "__main__":
    main()
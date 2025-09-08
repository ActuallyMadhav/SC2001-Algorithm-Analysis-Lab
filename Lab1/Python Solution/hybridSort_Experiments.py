import random
import time
import math
import matplotlib.pyplot as plt

# Global variable for counting comparisons
comparisons = 0

def compare(a, b):
    global comparisons
    comparisons += 1
    if a > b:
        return 1
    elif a < b:
        return -1
    else:
        return 0

def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and compare(arr[j], key) > 0:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, low, mid, high):
    left_size = mid - low + 1
    temp = arr[low:high + 1]
    i = 0
    j = left_size
    k = low
    while i < left_size and j < len(temp):
        if compare(temp[i], temp[j]) <= 0:
            arr[k] = temp[i]
            i += 1
        else:
            arr[k] = temp[j]
            j += 1
        k += 1
    while i < left_size:
        arr[k] = temp[i]
        i += 1
        k += 1
    while j < len(temp):
        arr[k] = temp[j]
        j += 1
        k += 1

def hybrid_sort(arr, low, high, S):
    if low >= high:
        return
    mid = (low + high) // 2
    if high - low + 1 > S:
        hybrid_sort(arr, low, mid, S)
        hybrid_sort(arr, mid + 1, high, S)
        merge(arr, low, mid, high)
    else:
        insertion_sort(arr, low, high)

def generate_arr(size, max_val):
    return [random.randint(1, max_val) for _ in range(size)]

# Experiments
random.seed(42)  # For reproducibility
max_val = 10000000
s_list = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]  # Values of S to test
n_list = [1000, 10000, 100000, 1000000]  # Add 10000000 if possible

# (c)i: Fixed S=32, vary n, record comparisons
fixed_s = 32
data_ci_comps = []
data_ci_theo = []
for n in n_list:
    arr = generate_arr(n, max_val)
    comparisons = 0
    hybrid_sort(arr, 0, n-1, fixed_s)
    data_ci_comps.append((n, comparisons))
    theo = n * math.log2(n)  # Approximate theoretical O(n log n)
    data_ci_theo.append((n, theo))

# Plot (c)i
plt.figure()
plt.plot([x[0] for x in data_ci_comps], [x[1] for x in data_ci_comps], label='Empirical')
plt.plot([x[0] for x in data_ci_theo], [x[1] for x in data_ci_theo], label='Theoretical (n log2 n)')
plt.xlabel('Input Size n')
plt.ylabel('Key Comparisons')
plt.title('Key Comparisons vs n (Fixed S=32)')
plt.legend()
plt.savefig('ci_plot.png')
plt.close()

print("Data for (c)i:")
print("n\tEmpirical Comps\tTheoretical Approx")
for i in range(len(n_list)):
    print(f"{data_ci_comps[i][0]}\t{data_ci_comps[i][1]}\t{data_ci_theo[i][1]:.0f}")

# (c)ii: Fixed n=1000000, vary S, record comparisons
fixed_n = 1000000  # Change to 10000000 if needed
arr_base = generate_arr(fixed_n, max_val)
data_cii_comps = []
for S in s_list:
    arr = arr_base.copy()
    comparisons = 0
    hybrid_sort(arr, 0, fixed_n-1, S)
    data_cii_comps.append((S, comparisons))

# Plot (c)ii
plt.figure()
plt.plot([x[0] for x in data_cii_comps], [x[1] for x in data_cii_comps])
plt.xlabel('Threshold S')
plt.ylabel('Key Comparisons')
plt.title('Key Comparisons vs S (Fixed n=1,000,000)')
plt.savefig('cii_plot.png')
plt.close()

print("\nData for (c)ii:")
print("S\tComps")
for x in data_cii_comps:
    print(f"{x[0]}\t{x[1]}")

# (c)iii: Optimal S for different n (based on CPU time)
optimal_s = {}
for n in n_list:
    arr_base = generate_arr(n, max_val)
    min_time = float('inf')
    best_s = 0
    for S in s_list:
        arr = arr_base.copy()
        comparisons = 0
        start = time.time()
        hybrid_sort(arr, 0, n-1, S)
        time_taken = time.time() - start
        if time_taken < min_time:
            min_time = time_taken
            best_s = S
    optimal_s[n] = (best_s, min_time)

print("\nData for (c)iii:")
print("n\tOptimal S\tMin Time (s)")
for n, (s, t) in optimal_s.items():
    print(f"{n}\t{s}\t{t:.6f}")

# (d): Compare original vs hybrid on n=1000000 (or 10000000)
compare_n = 1000000
best_s = optimal_s.get(compare_n, 32)  # Use optimal from (c)iii or default
arr_base = generate_arr(compare_n, max_val)

# Original (S=0)
arr = arr_base.copy()
comparisons = 0
start = time.time()
hybrid_sort(arr, 0, compare_n-1, 0)
time_orig = time.time() - start
comps_orig = comparisons

# Hybrid
arr = arr_base.copy()
comparisons = 0
start = time.time()
hybrid_sort(arr, 0, compare_n-1, best_s)
time_hyb = time.time() - start
comps_hyb = comparisons

print("\nData for (d):")
print("Algorithm\tComps\tTime (s)")
print(f"Original Mergesort\t{comps_orig}\t{time_orig:.6f}")
print(f"Hybrid (S={best_s})\t{comps_hyb}\t{time_hyb:.6f}")
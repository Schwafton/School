import random
import matplotlib.pyplot as plt
import math
from tabulate import tabulate

def merge_sort(arr):
    count = 0  # Counter to track actual complexity

    def merge(arr, left, right):
        nonlocal count
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
            count += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)

        merge(arr, left, right)

    return count

def generate_real_numbers(n):
    return [random.uniform(0, 100) for _ in range(n)]

def main():
    N_values = [12, 18, 24, 30, 36, 42, 48, 54, 60, 72]
    actual_counts = []
  
    for N in N_values:
        real_numbers = generate_real_numbers(N)
        sorted_numbers = real_numbers.copy()
        merge_count = merge_sort(sorted_numbers)
        actual_counts.append(merge_count)

        print(f"N={N}")
        print(f"Unsorted: {real_numbers}")
        print(f"Sorted: {sorted_numbers}")
        print(f"Actual Count: {merge_count}")
        print()

    # Plotting graph
    theoretical_counts = [n*(math.log2(n)) for n in N_values]
    plt.plot(N_values, theoretical_counts, label='Theoretical cost (T(N))')
    plt.plot(N_values, [actual_counts[x] for x in range(10)], label='Actual')
    plt.xlabel('N')
    plt.ylabel('Count')
    plt.legend()
    plt.title('Worst Case Complexity vs Actual')
    plt.show()

    #create data
    data = [[ N_values[0], actual_counts[0], theoretical_counts[0]],
            [ N_values[1], actual_counts[1], theoretical_counts[1]],
            [ N_values[2], actual_counts[2], theoretical_counts[2]],
            [ N_values[3], actual_counts[3], theoretical_counts[3]],
            [ N_values[4], actual_counts[4], theoretical_counts[4]],
            [ N_values[5], actual_counts[5], theoretical_counts[5]],
            [ N_values[6], actual_counts[6], theoretical_counts[6]],
            [ N_values[7], actual_counts[7], theoretical_counts[7]],
            [ N_values[8], actual_counts[8], theoretical_counts[8]],
            [N_values[9], actual_counts[9], theoretical_counts[9]]]
      
    #define header names
    col_names = ["N", "Actual", "T(N)"]
      
    #display table
    print(tabulate(data, headers=col_names))

if __name__ == "__main__":
    main()

import random
import math

def quicksort(arr, low, high, count):
    if low < high:
        pivot, count_partition = partition(arr, low, high)
        count[0] += count_partition
        quicksort(arr, low, pivot, count)
        quicksort(arr, pivot + 1, high, count)

def partition(arr, low, high):
    pivot = arr[low]
    i, j = low - 1, high + 1
    count = 0  # Counter to track the number of comparisons
    while True:
        i += 1
        while arr[i] < pivot:
            i += 1
            count += 1
        j -= 1
        while arr[j] > pivot:
            j -= 1
            count += 1
        if i >= j:
            print("partitioned array: ", arr)
            return j, count
        arr[i], arr[j] = arr[j], arr[i]

def generate_data(n):
    return [random.randint(1, 100) for _ in range(n)]

def main():
    n_values = [10, 25]
    actual_count = []
    for n in n_values:
        data = generate_data(n)
        count = [0]
        print(f"n={n}")
        print(f"Beginning Array Input: {data}")
        quicksort(data, 0, n - 1, count)
        actual_count.append(count[0])
        print(f"Ending Array Output: {data}")
        print(f"Actual Count for T({n}): {count[0]}")
        print()
    # Display the table
    print("n\tActual Count\tT(n) = Theta(n*log(n))")
    for x in range(2):
        theoretical_count = n_values[x]*math.log2(n_values[x])
        print(f"{n_values[x]}\t{actual_count[x]}\t\t\t\t{theoretical_count}")

if __name__ == "__main__":
    main()

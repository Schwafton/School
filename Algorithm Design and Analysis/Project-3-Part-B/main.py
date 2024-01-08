import random
import math

def quicksort(arr, low, high, count):
    if low < high:
        pivot, count_partition = partition(arr, low, high)
        count[0] += count_partition
        quicksort(arr, low, pivot - 1, count)
        quicksort(arr, pivot + 1, high, count)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    count = 0  # Counter to track the number of comparisons
    for j in range(low, high):
        count += 1
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    print("Partitioned array: ", arr)
    return i + 1, count

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
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

def main():
    n_values = [[10, 10, 10, 10, 10, 10, 10, 10, 10, 10], 
                [25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]]
    actual_count = []
    for n in n_values:
        count = [0]
        print(f"n={len(n)}")
        print(f"Beginning Array Input: {n}")
        quicksort(n, 0, len(n) - 1, count)
        actual_count.append(count[0])
        print(f"Ending Array Output: {n}")
        print(f"Actual Count for T({len(n)}): {count[0]}")
        print()
    # Display the table
    print("n\tActual Count\tT(n) = Theta(n^2)")
    for x in range(2):
        theoretical_count = len(n_values[x])**2
        print(f"{len(n_values[x])}\t{actual_count[x]}\t\t\t\t{theoretical_count}")

if __name__ == "__main__":
    main()

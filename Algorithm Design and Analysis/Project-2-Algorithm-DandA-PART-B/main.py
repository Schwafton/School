import random
import math
import matplotlib.pyplot as plt

def max_subarray_bruteforce(arr):
    max_sum = float('-inf')
    start_idx = end_idx = 0
    count = 0 

    for i in range(len(arr)):
        current_sum = 0
        for j in range(i, len(arr)):
            current_sum += arr[j]
            count += 1

            if current_sum > max_sum:
                max_sum = current_sum
                start_idx = i
                end_idx = j

    return max_sum, start_idx, end_idx, count

def generate_data(n):
    return [random.uniform(-100, 100) for _ in range(n)]

def main():
    N_values = [15, 20, 25, 30, 40, 45, 49]
    actual_counts = []

    for N in N_values:
        data = generate_data(N)
        max_sum, start_idx, end_idx, count = max_subarray_bruteforce(data)
        actual_counts.append(count)
        max_subarr = data[start_idx:end_idx + 1]

        print(f"N={N}")
        print(f"Original Array: {data}")
        print(f"Maximum Subarray: {max_subarr}")
        print(f"Starting Index: {start_idx}")
        print(f"Ending Index: {end_idx}")
        print(f"Maximum Subarray Sum: {max_sum}")
        print(f"Actual Count: {count}")
        print(f"Theoretical Count: {N**2}")
        print()

# Plotting graph
    theoretical_counts = [n**2 for n in N_values]
    plt.plot(N_values, theoretical_counts, label='Theoretical')
    plt.plot(N_values, [actual_counts[x] for x in range(7)], label='Actual')
    plt.xlabel('N')
    plt.ylabel('T(N)')
    plt.legend()
    plt.title('Theoretical Complexity vs Actual')
    plt.show()

if __name__ == "__main__":
    main()
import random
import timeit
import matplotlib.pyplot as plt

def max_subarray(arr, low, high):
    if low == high:
        return low, high, arr[low]

    mid = (low + high) // 2

    left_low, left_high, left_sum = max_subarray(arr, low, mid)
    right_low, right_high, right_sum = max_subarray(arr, mid + 1, high)
    cross_low, cross_high, cross_sum = max_crossing_subarray(arr, low, mid, high)

    if left_sum >= right_sum and left_sum >= cross_sum:
        return left_low, left_high, left_sum
    elif right_sum >= left_sum and right_sum >= cross_sum:
        return right_low, right_high, right_sum
    else:
        return cross_low, cross_high, cross_sum

def max_crossing_subarray(arr, low, mid, high):
    left_sum = float("-inf")
    max_left = mid
    current_sum = 0

    for i in range(mid, low - 1, -1):
        current_sum += arr[i]
        if current_sum > left_sum:
            left_sum = current_sum
            max_left = i

    right_sum = float("-inf")
    max_right = mid + 1
    current_sum = 0

    for i in range(mid + 1, high + 1):
        current_sum += arr[i]
        if current_sum > right_sum:
            right_sum = current_sum
            max_right = i

    return max_left, max_right, left_sum + right_sum

def generate_data(n):
    return [random.uniform(-100, 100) for _ in range(n)]

def main():
    N_values = [15, 20, 25, 30, 40, 45, 49]
    actual_counts = []

    for N in N_values:
        data = generate_data(N)
        start_time = timeit.default_timer()
        low, high, max_sum = max_subarray(data, 0, N - 1)
        end_time = timeit.default_timer()
        max_subarr = data[low:high + 1]

        print(f"N={N}")
        print(f"Original Array: {data}")
        print(f"Maximum Subarray: {max_subarr}")
        print(f"Starting Index: {low}")
        print(f"Ending Index: {high}")
        print(f"Maximum Subarray Sum: {max_sum}")
        print(f"Execution Time: {end_time - start_time} seconds")
        print()
        
        actual_counts.append(end_time - start_time)

    # Plotting the time complexity
    theoretical_counts = [N * (N - 1) // 2 for N in N_values]
    plt.plot(N_values, theoretical_counts, label='Theoretical Time Complexity (N^2)')
    plt.plot(N_values, actual_counts, label='Actual Execution Time')
    plt.xlabel('N')
    plt.ylabel('Time (seconds)')
    plt.legend()
    plt.title('Time Complexity Comparison')
    plt.show()

if __name__ == "__main__":
    main()

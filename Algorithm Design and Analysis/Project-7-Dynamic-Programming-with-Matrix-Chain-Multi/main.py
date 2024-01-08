import sys

def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * n for _ in range(n)]
    s = [[0] * n for _ in range(n)]

    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return m, s

def print_matrices_dimensions(matrices):
    print("Matrix Dimensions:")
    for i in range(len(matrices) - 1):
        print(f"Matrix {i + 1}: {matrices[i]} x {matrices[i + 1]}")

def display_upper_triangle(matrix, label):
    print(f"\n{label}:")
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if j >= i:
                print(matrix[i][j], end=" ")
            else:
                print("", end=" ")
        print()

def matrixChain(p, i, j):
  if(i == j):
    return 0
  if(dp[i][j] != -1):
    return dp[i][j]
  dp[i][j] = sys.maxsize
  for k in range(i,j):
    ops[i][j] = ops[i][j] + (p[i - 1] * p[k] * p[j])
    dp[i][j] = min(dp[i][j], matrixChain(p, i, k) + matrixChain(p, k + 1, j)+ p[i - 1] * p[k] * p[j])
    maxops[i][j] = maxops[i][j] + matrixChain(p, i, k) + matrixChain(p, k + 1, j)+ p[i - 1] * p[k] * p[j]
  return dp[i][j]

def MatrixChainOrder(p,n):
  i = 1
  j = n - 1
  return matrixChain(p, i, j)
  
# Example matrix dimensions
matrices_set = [[30, 35, 15, 5], [5, 10, 3, 12, 5, 2], [2, 7, 3, 6, 10, 1, 5], [4, 2, 3], [1, 2, 3, 4, 5]]

# Loop through the sets of matrix chains
for index, matrices in enumerate(matrices_set, start=1):
    print(f"\nSet {index}:")
    print_matrices_dimensions(matrices)
    m, s = matrix_chain_order(matrices)
    display_upper_triangle(m, "m[i, j]")
    display_upper_triangle(s, "s[i, j]")
    dp = [[-1 for i in range(10)] for j in range(10)]
    ops = [[0 for i in range(10)] for j in range(10)]
    maxops = [[0 for i in range(10)] for j in range(10)]
    n = len(matrices)
    print("Minimum number of multiplications is",MatrixChainOrder(matrices, n))
    print("Scalar multiplications using dynamic programming: ", sum(sum(ops,[])) )
    print("Scalar multiplications not using dynamic programming: ", sum(sum(maxops,[])))


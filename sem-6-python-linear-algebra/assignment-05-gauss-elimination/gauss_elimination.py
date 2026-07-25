import numpy as np

# Create augmented matrix
A = np.array([
    [4, 3, -5, 2],
    [-2, -4, 5, 5],
    [8, 8, 0, -3]
], dtype=float)

print("Augmented Matrix =\n")
print(A)

# Step 1: make the first pivot 1
A[0] = A[0] / A[0][0]
print("\nAfter R1 = R1 / 4\n")
print(A)

# Step 2: eliminate the first column below the pivot
A[1] = A[1] + 2 * A[0]
A[2] = A[2] - 8 * A[0]
print("\nAfter making first column zero\n")
print(A)

# Step 3: make the second pivot 1
A[1] = A[1] / A[1][1]
print("\nAfter making second pivot 1\n")
print(A)

# Step 4: eliminate the second column below the pivot
A[2] = A[2] - A[2][1] * A[1]
print("\nAfter making second column zero\n")
print(A)

# Step 5: make the third pivot 1
A[2] = A[2] / A[2][2]
print("\nAfter making third pivot 1\n")
print(A)

# Back substitution: solve from the last row upward, since by this
# point the matrix is in row echelon form (upper triangular with 1s on
# the diagonal), each row only introduces one new unknown
x3 = A[2][3]
x2 = A[1][3] - A[1][2] * x3
x1 = A[0][3] - A[0][1] * x2 - A[0][2] * x3

print("\nSolution using Gauss Elimination")
print("x1 =", x1)
print("x2 =", x2)
print("x3 =", x3)

# Verification using NumPy's own solver, as a sanity check that the
# manual elimination above landed on the right answer
C = np.array([
    [4, 3, -5],
    [-2, -4, 5],
    [8, 8, 0]
], dtype=float)
B = np.array([2, 5, -3], dtype=float)

solution = np.linalg.solve(C, B)
print("\nSolution using np.linalg.solve()")
print(solution)

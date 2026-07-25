from sympy import Matrix

# Create augmented matrix
A = Matrix([
    [1, 1, 1, 6],
    [2, 3, 1, 10],
    [1, 2, 2, 9]
])

print("Original Augmented Matrix =\n")
print(A)

# ---------- Gaussian Elimination ----------
A[1, :] = A[1, :] - 2 * A[0, :]
A[2, :] = A[2, :] - A[0, :]
print("\nAfter First Elimination =\n")
print(A)

A[2, :] = A[2, :] - A[1, :]
print("\nAfter Second Elimination =\n")
print(A)

# Back Substitution
z = A[2, 3] / A[2, 2]
y = (A[1, 3] - A[1, 2] * z) / A[1, 1]
x = A[0, 3] - y - z

print("\nSolution using Gaussian Elimination")
print("x =", x)
print("y =", y)
print("z =", z)

# ---------- Gauss-Jordan ----------
B = Matrix([
    [1, 1, 1, 6],
    [2, 3, 1, 10],
    [1, 2, 2, 9]
])

rref_matrix, pivot = B.rref()
print("\nReduced Row Echelon Form =\n")
print(rref_matrix)

# A system is inconsistent if the RREF has a row that's all zeros on
# the coefficient side but non-zero on the right-hand side, that would
# mean "0 = something nonzero", which is impossible
consistent = True
for row in rref_matrix.tolist():
    if row[0] == 0 and row[1] == 0 and row[2] == 0 and row[3] != 0:
        consistent = False

if consistent:
    print("\nSystem is Consistent")
else:
    print("\nSystem is Inconsistent")

print("\nSolution using Gauss-Jordan Method")
print("x =", rref_matrix[0, 3])
print("y =", rref_matrix[1, 3])
print("z =", rref_matrix[2, 3])

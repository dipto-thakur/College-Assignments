from sympy import Matrix

# Define the vectors
v1 = [1, 1, 0]
v2 = [0, 1, 1]
v3 = [1, 2, 1]

print("v1 =", v1)
print("v2 =", v2)
print("v3 =", v3)

# Create matrix using vectors as columns
A = Matrix([
    [1, 0, 1],
    [1, 1, 2],
    [0, 1, 1]
])

print("\nMatrix A =")
print(A)

# Find rank
r = A.rank()
print("\nRank of Matrix =", r)

# Check linear independence: 3 vectors in R3 are linearly independent
# only if the matrix they form has full rank (3). A lower rank means
# at least one vector can be written as a combination of the others.
if r == 3:
    print("\nVectors are Linearly Independent")
else:
    print("\nVectors are Linearly Dependent")

# Reduced Row Echelon Form
rref_matrix, pivot_columns = A.rref()
print("\nRREF of Matrix =")
print(rref_matrix)
print("\nPivot Columns =", pivot_columns)

# Find basis: the original columns at the pivot positions form a basis
# for the column space (the subspace spanned by v1, v2, v3)
basis = []
for i in pivot_columns:
    basis.append(A.col(i))

print("\nBasis for the Subspace =")
for b in basis:
    print(b)

# Find dimension
dimension = len(basis)
print("\nDimension of the Subspace =", dimension)

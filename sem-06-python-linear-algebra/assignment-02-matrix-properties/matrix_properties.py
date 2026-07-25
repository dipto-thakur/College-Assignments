import numpy as np

# Input order of square matrix
n = int(input("Enter the order of square matrix: "))

# Input matrix elements
print("Enter the elements of matrix row wise:")
A = []
for i in range(n):
    row = []
    for j in range(n):
        value = float(input(f"A[{i}][{j}] = "))
        row.append(value)
    A.append(row)
A = np.array(A)

while True:
    print("\n========== MENU ==========")
    print("1. Determinant")
    print("2. Inverse")
    print("3. Transpose")
    print("4. Scalar Multiplication")
    print("5. Adjoint")
    print("6. Rank")
    print("7. Diagonal Elements")
    print("8. Trace")
    print("9. Eigen Values and Eigen Vectors")
    print("10. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("\nDeterminant =", np.linalg.det(A))
    elif choice == 2:
        det = np.linalg.det(A)
        if np.isclose(det, 0):
            print("\nInverse does not exist.")
        else:
            print("\nInverse Matrix =")
            print(np.linalg.inv(A))
    elif choice == 3:
        print("\nTranspose Matrix =")
        print(A.T)
    elif choice == 4:
        s = float(input("Enter scalar value: "))
        print("\nResult =")
        print(s * A)
    elif choice == 5:
        det = np.linalg.det(A)
        if np.isclose(det, 0):
            print("\nAdjoint cannot be found.")
        else:
            # adj(A) = det(A) * inv(A), a standard identity relating the
            # two, rounded here since floating-point inverse/determinant
            # math rarely lands on a perfectly clean integer
            adj = det * np.linalg.inv(A)
            print("\nAdjoint Matrix =")
            print(np.round(adj))
    elif choice == 6:
        print("\nRank =", np.linalg.matrix_rank(A))
    elif choice == 7:
        print("\nDiagonal Elements =", np.diag(A))
    elif choice == 8:
        print("\nTrace =", np.trace(A))
    elif choice == 9:
        values, vectors = np.linalg.eig(A)
        print("\nEigen Values =")
        print(values)
        print("\nEigen Vectors =")
        print(vectors)
    elif choice == 10:
        print("\nProgram Ended")
        break
    else:
        print("\nInvalid Choice!")

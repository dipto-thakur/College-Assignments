import numpy as np

# Input number of rows
r = int(input("Enter number of rows: "))

# Input number of columns
c = int(input("Enter number of columns: "))

# -------- Matrix A --------
print("\nEnter elements of Matrix A")
A = []
for i in range(r):
    row = []
    for j in range(c):
        value = float(input(f"A[{i}][{j}] = "))
        row.append(value)
    A.append(row)
A = np.array(A)

# -------- Matrix B --------
print("\nEnter elements of Matrix B")
B = []
for i in range(r):
    row = []
    for j in range(c):
        value = float(input(f"B[{i}][{j}] = "))
        row.append(value)
    B.append(row)
B = np.array(B)

while True:
    print("\n========== MENU ==========")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("\nAddition =")
        print(np.add(A, B))
    elif choice == 2:
        print("\nSubtraction =")
        print(np.subtract(A, B))
    elif choice == 3:
        if A.shape[1] == B.shape[0]:
            print("\nMultiplication =")
            print(np.matmul(A, B))
        else:
            print("\nMatrix multiplication not possible.")
    elif choice == 4:
        # "Division" of matrices isn't a standard operation, this treats
        # it as A * inverse(B), which is the closest matrix analogue to
        # dividing by B, and only makes sense for square matrices with a
        # non-zero determinant (i.e. B must actually be invertible)
        if r == c:
            det = np.linalg.det(B)
            if np.isclose(det, 0):
                print("\nDivision not possible.")
            else:
                invB = np.linalg.inv(B)
                print("\nDivision =")
                print(np.matmul(A, invB))
        else:
            print("\nDivision possible only for square matrices.")
    elif choice == 5:
        print("\nProgram Ended")
        break
    else:
        print("\nInvalid Choice!")

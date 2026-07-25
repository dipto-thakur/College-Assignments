import numpy as np

print("Enter 3 values for Vector u")
u = np.array([
    float(input("u1 = ")),
    float(input("u2 = ")),
    float(input("u3 = "))
])

print("\nEnter 3 values for Vector v")
v = np.array([
    float(input("v1 = ")),
    float(input("v2 = ")),
    float(input("v3 = "))
])

while True:
    print("\n========== MENU ==========")
    print("1. Vector Addition")
    print("2. Scalar Multiplication")
    print("3. Dot Product")
    print("4. Cross Product")
    print("5. Orthogonality Check")
    print("6. Parallelism Check")
    print("7. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("\nVector Addition =", u + v)
    elif choice == 2:
        s = float(input("Enter scalar value: "))
        print("\nScalar Multiplication of u =", s * u)
        print("Scalar Multiplication of v =", s * v)
    elif choice == 3:
        print("\nDot Product =", np.dot(u, v))
    elif choice == 4:
        print("\nCross Product =", np.cross(u, v))
    elif choice == 5:
        if np.isclose(np.dot(u, v), 0):
            print("\nVectors are Orthogonal")
        else:
            print("\nVectors are Not Orthogonal")
    elif choice == 6:
        if np.isclose(np.linalg.norm(np.cross(u, v)), 0):
            print("\nVectors are Parallel")
        else:
            print("\nVectors are Not Parallel")
    elif choice == 7:
        print("\nProgram Ended")
        break
    else:
        print("\nInvalid Choice! Try Again.")

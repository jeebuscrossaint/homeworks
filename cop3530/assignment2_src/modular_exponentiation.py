def binary_k(k):
    K = []
    while k > 0:
        K.append(k % 2)
        k = k // 2
    return K

def modular_expo(a, K, n):
    if n == 1:
        return 0
    b = 1
    A = a

    if K[0] == 1:
        b = a

    for i in range(1, len(K)):
        A = (A * A) % n
        if K[i] == 1:
            b = (A * b) % n

    return b

def main():
    a = int(input("Enter the base (a): "))
    k = int(input("Enter the exponent (k): "))
    n = int(input("Enter the modulus (n): "))

    K = binary_k(k)
    result = modular_expo(a, K, n)

    print(f"Result of {a}^{k} mod {n} is: {result}")

if __name__ == "__main__":
    main()
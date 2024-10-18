# Function to convert an integer 'k' to binary representation as a list of 0s and 1s
def binary_k(k):
    K = []
    while k > 0:
        K.append(k % 2)
        k = k // 2
    return K

# Function to perform Modular Exponentiation using square and multiply approach
def modular_exponentiation(a, K, n):
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

# Main function to get user input and call the modular exponentiation
def main():
    # Get user inputs
    a = int(input("Enter the base (a): "))
    k = int(input("Enter the exponent (k): "))
    n = int(input("Enter the modulus (n): "))
    
    # Convert k to binary representation
    K = binary_k(k)
    
    # Perform modular exponentiation
    result = modular_exponentiation(a, K, n)
    
    # Display the result
    print(f"{a}^{k} mod {n} = {result}")

# Call main function to execute the program
if __name__ == "__main__":
    main()

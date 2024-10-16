def two_largest(A):
    large_1 = 0
    large_2 = 0

    for num in A:
        if num > large_1:
            large_2 = large_1
            large_1 = num
        elif num > large_2:
            large_2 = num

    print(f"The two largest numbers are: {large_1} and {large_2}")

def main():
    n = int(input("Enter the size of the list: "))
    A = []

    print("Enter the elements of the list: ")
    for _ in range(n):
        A.append(int(input()))

    two_largest(A)

if __name__ == "__main__":
    main()
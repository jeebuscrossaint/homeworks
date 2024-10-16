def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        max_index = i
        for j in range(i + 1, n):
            if arr[j] > arr[max_index]:
                max_index = j
        arr[i], arr[max_index] = arr[max_index], arr[i]

def main():
    n = int(input("Enter the size of the array: "))

    arr = []
    print("Enter the elements of the array: ")
    for _ in range(n):
        arr.append(int(input()))

    print("Unsorted array: ", end="")
    print(" ".join(map(str, arr)))

    selection_sort(arr)

    print("Sorted array: ", end="")
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    main()
def qsort(arr):
    if len(arr) < 2:
        return arr

    pivot = arr[0]
    arr = arr[1:]
    left = []
    right = []
    for i in arr:
        if i <= pivot:
            left += [i]
        else:
            right += [i]
        arr = qsort(left) + [pivot] + qsort(right)
    return arr


if __name__ == "__main__":
    arr = [8, 2, 3, 1, 5, 7, 4, 6]
    print(qsort(arr))

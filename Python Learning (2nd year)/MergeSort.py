def mergeSort(arr, l, r):
    global count  # For recursion count
    count += 1
    if r - l <= 1:  # Base case, when there is only one element left in the list passed through recursion
        return (arr[l:r])
    if r - l > 1:
        mid = (l + r) // 2
        a = mergeSort(arr, l, mid)
        b = mergeSort(arr, mid, r)
        return (merge(a, b))


def merge(a, b):
    (c, m, n) = ([], len(a), len(b))
    (i, j) = (0, 0)
    while i + j < m + n:
        if i == m:
            c.append(b[j])
            j = j + 1
        elif j == n:
            c.append(a[i])
            i = i + 1
        elif a[i] > b[j]:
            c.append(b[j])
            j = j + 1
        elif a[i] <= b[j]:
            c.append(a[i])
            i = i + 1
    return (c)


arr = list(range(500, 0, -1))
count = 0
mergeSort(arr, 0, len(arr))
print(arr, count)

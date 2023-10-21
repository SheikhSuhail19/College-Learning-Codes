def quick(arr, l, r) :
    global count  # For recursion count
    count += 1
    if r - l <= 1:  # Base case, when there is only one element left in the list passed through recursion
        return ()
    yellow_back = l + 1 # Yellow pointer which is always behind Green pointer
    pivot = arr[l]  # Choosing the first element as pivot
    for green_fwd in range(l + 1, r):
        if arr[green_fwd] <= pivot:
            (arr[yellow_back], arr[green_fwd]) = (arr[green_fwd], arr[yellow_back])
            yellow_back += 1
    (arr[l], arr[yellow_back - 1]) = (arr[yellow_back - 1], arr[l])
    quick(arr, l, yellow_back - 1)
    quick(arr, yellow_back, r)

arr = list(range(500, 0, -1))
count = 0
print(arr)
quick(arr, 0, len(arr))
print(arr, count)

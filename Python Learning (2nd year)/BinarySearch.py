def binary(list,f,l,val):
    if f > l:
        print('Element not found')
        exit(1)
    mid = (f+l)//2
    if list[mid] > val:
        binary(list, f, mid - 1, val)

    elif list [mid] == val:
        print('Element found at',mid+1,'position')
        exit(0)
    elif list[mid] < val:
        binary(list, mid + 1, l, val)

list = [1,2,3,0,4,5,6,7,8,9]
list.sort()
print(list)
binary(list,0,len(list),0)
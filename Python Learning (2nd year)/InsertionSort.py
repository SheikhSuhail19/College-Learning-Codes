def insertion(list1):
    for i in range(1,len(list1)):
        pos = i
        while pos>0 and list1[pos] < list1[pos-1]:
            (list1[pos],list1[pos-1]) = (list1[pos-1],list1[pos])
            pos -= 1
    print(list1)

list1 = list(range(500,0,-1))
print(list1)
insertion(list1)
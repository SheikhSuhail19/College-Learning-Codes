def selection(list2):
    for i in range(0,len(list2)-1):
        for j in range(i+1,len(list2)):
            if list2[i] > list2[j]:
                (list2[i],list2[j]) = (list2[j],list2[i])
    print(list2)


list1 = list(range(500,0,-1))
print(list1)
selection(list1)
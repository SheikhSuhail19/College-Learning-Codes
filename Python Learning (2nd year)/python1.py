list = ["Suhail", 'Aamir', 4,5,6,True, False]
list.append("Javaid")
list.extend(list)
list.insert(4,234556)
list.remove(4)
list.pop(2)
list.reverse()
print(list.count('Suhail'))
print(list)

thislist = list.copy()
print(thislist)
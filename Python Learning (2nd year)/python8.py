def square(x):
    return x ** 2


list1 = [1, 2, 3, 4, 5]
sq = map(square, list1)
print(list(sq))

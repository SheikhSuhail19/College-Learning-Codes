def square(x):
    return (x * x)


def iseven(x):
    return (x % 2 == 0)


l = [(x, y, z) for x in range(1, 100) for y in range(x, 100) for z in range(y, 100) if x * x + y * y == z * z]      #W/o duplicates
print(l)
print('\n')
lst = [square(x) for x in range(100) if iseven(x)]
print(lst)

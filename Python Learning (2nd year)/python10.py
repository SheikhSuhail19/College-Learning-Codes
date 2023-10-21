def myfunc(x):
    return lambda a : a*x

double = myfunc(2)
triple = myfunc(3)

print(double(11))
print(triple(11))
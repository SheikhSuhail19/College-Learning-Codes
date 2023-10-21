def fib(x):
    if x <= 1 :
        return x
    return fib(x-1)+fib(x-2)

x = int(input())
print("Series is : \n")
for i in range(x):
    print(fib(i))
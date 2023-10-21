stack = [1, 2, 3, 4, 5, 6, 7]
for i in range(50):
    stack.append(i)
print(stack)
for i in range(7):
    stack.pop()
print(stack)
s = stack.copy()
print(sorted(s))
print(stack)

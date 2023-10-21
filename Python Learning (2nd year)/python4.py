import random

x=random.randint(1,10)
y=random.randint(1,15)
print('Value of ' + str(x) + ' * ' +  str(y) + '  is :')
result = input()

print('Yes') if result == str(x*y) else print('No')

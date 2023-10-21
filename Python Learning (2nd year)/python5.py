x = int(input())
if x < 2:
    print("NotPrime")
    exit()

flag = True
for i in range(2,x):
    if x%i==0:
        flag = False

if flag:
        print("Prime")
else:
    print("NotPrime")
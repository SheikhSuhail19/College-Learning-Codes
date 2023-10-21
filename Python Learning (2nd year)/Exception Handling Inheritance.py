def h():
    print('Hey')
    g()


def g():
    print('HI')
    k()


def k():
    l = 5 * x


try:
    l = 5
    h()
except NameError:
    print('This is a name error')
else:
    print('This is the else statement of Try block')

class Human:
    def __init__(self,name,age):
        self.name=name
        self.age=age

    def greet(self):
        print("Hey there, my name is " + self.name + ', and My age is ' + str(self.age))

h1 = Human("Suhail",21)
h1.greet()
h1.age = 27
'''
del h1.age
del h1
'''
h1.greet()
class Tree:
    def __init__(self, initval=None):
        self.value = initval
        if self.value:
            self.left = Tree()
            self.right = Tree()
        else:
            self.left = None
            self.right = None
        return

    def isempty(self):
        return (self.value == None)

    def preorder(self):
        if self.isempty():
            return ([])
        else:
            return ([self.value] + self.left.preorder() + self.right.preorder())

    def __str__(self):
        return (str(self.preorder()))

    def inorder(self):
        if self.isempty():
            return ([])
        else:
            return (self.left.inorder() + [self.value] + self.right.inorder())

    def __str__(self):
        return (str(self.inorder()))

    def postorder(self):
        if self.isempty():
            return ([])
        else:
            return (self.left.postorder() + self.right.postorder() + [self.value])

    def __str__(self):
        return (str(self.postorder()))

    def find(self, v):
        if self.isempty():
            return (False)
        if self.value == v:
            return (True)
        if v < self.value:
            return (self.left.find(v))
        if v > self.value:
            return (self.right.find(v))

    def minval(self):
        if self.left == None:
            return self.value
        else:
            return self.left.minval()

    def maxval(self):
        if self.right.isempty():
            return(self.value)
        else:
            return (self.right.maxval())

    def insert(self, v):
        if self.isempty():
            self.value = v
            self.left = Tree()
            self.right = Tree()
        if self.value == v:
            return
        if v > self.value:
            self.right.insert(v)
            return
        if v < self.value:
            self.left.insert(v)
            return

    def delete(self, v):
        if self.isempty():
            return
        if v > self.value:
            self.right.delete(v)
            return
        if v < self.value:
            self.left.delete(v)
            return
        if v == self.value:
            if self.isleaf():
                self.makeempty()
            elif self.left.isempty():
                self.copyright()
            else:
                self.value = self.left.maxval()
                self.left.delete(self.left.maxval())
            return

    def isleaf(self):
        return(self.right.isempty() and self.left.isempty())

    def makeempty(self):
        self.value = None
        self.right = None
        self.left = None
        return

    def copyright(self):
        self.value = self.right.value
        self.left = self.right.left
        self.right = self.right.right
        return

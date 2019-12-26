class Tree:
    def __init__(self, data, parent=None):
        self.data = data
        self.parent = parent
        self.visited = False
        self.children = []

    def __str__(self):
        return str(self.data)

    def add_child(self, tree):
        self.children.append(tree)

    def find_node(self, data):
        for child in self.children:
            if child.data == data and not child.visited:
                return child
        return None

    def traverse(self, spaces=0):
        print(f'{" "*spaces}{self.data}')
        for i in range(len(self.children)-1, -1, -1):
            child = self.children[i]
            child.traverse(spaces+2)

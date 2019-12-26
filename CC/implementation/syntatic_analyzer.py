from predictive_table import PredictiveTable
from tree import Tree

class SyntaticAnalyzer():
    def __init__(self, lexical_analyzer, debug=False):
        self.PT = PredictiveTable()
        self.LA = lexical_analyzer
        self.terminals = ['programa', 'inicio', 'fim', 'id', ';', 'int', 'char', 'real', 'se', '(', ')',
        'enquanto', '==', '<>', '<', '<=', '>', '>=', '+', '-', '*', '/', '=', '$', 'numero']
        self.debug = debug

    def analyze(self):
        queue = ['S']
        root = Tree('S')
        node = root

        parent = None
        prox_token, value = self.LA.get_next_token()

        if not prox_token:
            return self.error()

        while len(queue) > 0:
            x = queue[-1]

            self.debug_message('')
            self.debug_message(f'Queue: {queue}')
            self.debug_message(f'x: {x} prox_token: {prox_token}')
            self.debug_message('')

            if self.is_terminal(x):
                self.debug_message(f'{x} is terminal')

                if x == prox_token:
                    self.debug_message('Match')
                    _ = queue.pop()
                    prox_token, value = self.LA.get_next_token()
                else:
                    self.debug_message('Error')
                    return self.error()
            else:
                if x != 'S' and node.data == 'S':
                    parent = node
                    node = parent.find_node(x)
                    node.visited = True
                elif node.parent:
                    if node.find_node(x):
                        parent = node
                        node = parent.find_node(x)
                    else:
                        node = node.parent
                        while not node.find_node(x):
                            node = node.parent
                        parent = node
                        node = parent.find_node(x)
                    node.visited = True

                prod_id = self.PT.move(x, prox_token)
                self.debug_message(f'{x} not terminal and got prod {prod_id}')
                if prod_id == -1:
                    return self.error()
                else:
                    _ = queue.pop()
                    prod = self.PT.get_production_by_id(prod_id)
                    self.debug_message(prod)
                    for i in range(len(prod)-1, -1, -1):
                        token = prod[i]
                        node.add_child(Tree(token, node))
                        if token != 'e':
                            queue.append(token)

        if not prox_token and len(queue) == 0:
            print('Code Accepted')
            return root
        else:
            return self.error()

    def is_terminal(self, x):
        return True if x in self.terminals else False

    def debug_message(self, message):
        if self.debug:
            print(message)

    def error(self):
        print('Code not correct')
        return None

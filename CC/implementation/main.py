from lexical_analyzer import LexicalAnalyzer
from syntatic_analyzer import SyntaticAnalyzer

INPUT_FILE = 'input'

if __name__ == '__main__':
    LA = LexicalAnalyzer(INPUT_FILE)
    SA = SyntaticAnalyzer(LA, debug=True)
    ast = SA.analyze()
    if ast: ast.traverse()

    # token, value = LA.get_next_token()
    # while token:
    #     print(f'Token: {token} - value: {value}')
    #     token, value = LA.get_next_token()

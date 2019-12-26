from transition_table import TransitionTable

class LexicalAnalyzer():
    def __init__(self, input_file):
        self.TT = TransitionTable()
        self.buffer = []
        self.position_buffer = 0

        with open(input_file) as fi:
            for line in fi:
                if line != '\n':
                    aux = line.strip().split(' ')
                    self.buffer.extend(aux)

        self.buffer = " ".join(self.buffer)

    def get_next_token(self):
        state = 0
        tmp = ''

        c = self.get_prox_char()
        while(c != 'EOF'):
            tmp += c

            state = self.TT.move(state, c)
            if not state:
                print(f'Token Unrecognised {c}')
                return None, None

            finish = True
            if self.TT.is_final_state(state) and not self.check_lookahead(state) \
                or not self.TT.is_final_state(state) and state != -1:
                finish = False

            if finish:
                break

            c = self.get_prox_char()
            if c == ' ':
                break

        if self.TT.is_final_state(state):
            type = self.TT.get_token_type(state)
            if type:
                return type, tmp
            else:
                return tmp, None
        else:
            return None, None

    def get_prox_char(self):
        if self.position_buffer >= len(self.buffer):
            return 'EOF'

        char = self.buffer[self.position_buffer]
        self.position_buffer += 1
        while char == ' ':
            if self.position_buffer >= len(self.buffer):
                return 'EOF'
            char = self.buffer[self.position_buffer]
            self.position_buffer += 1
        return char

    def check_lookahead(self, state):
        aux_position = self.position_buffer
        if aux_position >= len(self.buffer):
            return True

        char = self.buffer[aux_position]
        if char == ' ':
            return True

        aux_state = self.TT.move(state, char)
        if not aux_state:
            return None
        elif aux_state == -1:
            return True
        else:
            return False

    def get_token_position(self, ):
        pass

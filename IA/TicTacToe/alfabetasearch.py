class alfabeta:
    def searchMoveComputer1(self, initialState):
        alfa = -250000
        beta = 250000
        (v, (line, column)) = self.maxim(initialState, alfa, beta)
        return (line, column)

    def searchMoveComputer2(self, initialState):
        alfa = -250000
        beta = 250000
        (v, (line, column)) = self.minim(initialState, alfa, beta)
        return (line, column)

    def printState(self, state):
        for i in range(0, 3):
            for j in range(0, 3):
                print(state[i][j], end = " ")
            print("")

    def maxim(self, state, alfa, beta):
        """
        print('maxi')
        print("{} {}".format(alfa, beta))
        self.printState(state)
        """

        utility = self.isTerminal(state)
        if utility != None:
            return (utility, (-1, -1))

        v = -250000
        lineV = -1
        columnV = -1

        for i in range(0, 3):
            for j in range(0, 3):
                if state[i][j] == None:
                    auxState = [x[:] for x in state]
                    auxState[i][j] = 'X'

                    (auxV, (auxLine, auxColumn)) = self.minim(auxState, alfa, beta)
                    if auxV > v:
                        v = auxV
                        lineV = i
                        columnV = j

                    if v >= beta: return (v, (i, j))
                    alfa = max(alfa, v)
        return (v, (lineV, columnV))

    def minim(self, state, alfa, beta):
        """
        print('mini')
        print("{} {}".format(alfa, beta))
        self.printState(state)
        """

        utility = self.isTerminal(state)
        if utility != None:
            return (utility, (-1, -1))

        v = 250000
        lineV = -1
        columnV = -1

        for i in range(0, 3):
            for j in range(0, 3):
                if state[i][j] == None:
                    auxState = [x[:] for x in state]
                    auxState[i][j] = 'O'

                    (auxV, (auxLine, auxColumn)) = self.maxim(auxState, alfa, beta)
                    if auxV < v:
                        v = auxV
                        lineV = i
                        columnV = j

                    if v <= alfa: return (v, (i, j))
                    beta = min(beta, v)
        return (v, (lineV, columnV))

    def isTerminal(self, state):

        #Verify Lines
        for i in range(0, 3):
            if ((state[i][0] == state[i][1] == state[i][2]) and state[i][0] != None):
                if state[i][0] == 'X': return 10
                elif state[i][0] == 'O': return -10

        #Verify Columns
        for i in range(0, 3):
            if ((state[0][i] == state[1][i] == state[2][i]) and state[0][i] != None):
                if state[0][i] == 'X': return 10
                elif state[0][i] == 'O': return -10

        #Verify Diagonals
        if ((state[0][0] == state[1][1] == state[2][2]) and state[i][0] != None):
            if state[0][0] == 'X': return 10
            elif state[0][0] == 'O': return -10

        if ((state[0][2] == state[1][1] == state[2][0]) and state[0][2] != None):
            if state[0][2] == 'X': return 10
            elif state[0][2] == 'O': return -10

        #Verify if is full
        for i in range(0, 3):
            for j in range(0, 3):
                if state[i][j] == None:
                    return None

        return 0

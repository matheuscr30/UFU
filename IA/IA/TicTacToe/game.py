from alfabetasearch import alfabeta
import pygame
import os
import sys

"""
X - computer
O - user
"""

posImages = {(0, 0) : (55, 45),  (0, 1) : (255, 45),  (0, 2) : (455, 45),
             (1, 0) : (55, 212), (1, 1) : (255, 212), (1, 2) : (455, 212),
             (2, 0) : (55, 370), (2, 1) : (255, 370), (2, 2) : (455, 370)}

class Game:
    def __init__(self):
        self.board = [[None, None, None], [None, None, None], [None, None, None]]
        self._image_library = {}
        self.player = None
        self.screen = None
        self.done = False

    def startGame(self):
        self.player = self.menuGame()
        self.screen = self.buildGame()

        while not self.done:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.done = True
                elif event.type == pygame.MOUSEBUTTONDOWN and self.player == 'O':
                    self.clickScreen()

            winner = self.checkWinner()
            if winner != None:
                return self.finishGame(winner)

            if self.player == 'X':
                self.computerMovement()

            pygame.display.flip()

    def finishGame(self, winner):
        print("Game Over")
        self.done = True

    def computerMovement(self):
        afbeta = alfabeta()
        (line, column) = afbeta.searchMove(self.board)

        if line == -1 and column == -1: return

        self.board[line][column] = 'X'
        self.drawX0(line, column, True)
        self.player = 'O'

    def clickScreen(self):
        (x, y) = pygame.mouse.get_pos()
        (line, col) = self.getBoardPosition(x, y)

        if self.board[line][col] != None:
            return

        self.board[line][col] = 'O'
        self.drawX0(line, col, False)
        self.player = 'X'

    def drawX0(self, line, col, flag):
        if flag: picture = self.get_image('x.png')
        else: picture = self.get_image('o.png')

        (x, y) = posImages[(line, col)]
        picture = pygame.transform.scale(picture, (100, 100))
        self.screen.blit(picture, (x, y))
        pygame.display.flip()

    def menuGame(self):
        screen = pygame.display.set_mode((600, 521))
        screen.fill((255, 255, 255))
        font = pygame.font.SysFont("comicsansms", 36)
        text = font.render("Aperte a tecla y se deseja começar jogando", True, (0, 128, 0))
        text2 = font.render("Ou aperte a tecla n caso contrário", True, (128, 0, 0))
        screen.blit(text,(300 - text.get_width() // 2, 200 - text.get_height() // 2))
        screen.blit(text2,(300 - text.get_width() // 2, 250 - text.get_height() // 2))

        player = ' '
        done = False
        while not done:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    done = True
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_y:
                        player = 'O'
                        done = True
                    elif event.key == pygame.K_n:
                        player = 'X'
                        done = True

            pygame.display.flip()
        return player

    def buildGame(self):
        #Build the screen game
        screen = pygame.display.set_mode((600, 521))
        screen.fill((255, 255, 255))

        #Insert lines
        pygame.draw.rect(screen, (35, 35, 35), pygame.Rect(10, 167, 580, 5))
        pygame.draw.rect(screen, (35, 35, 35), pygame.Rect(10, 334, 580, 5))

        #Insert Columns
        pygame.draw.rect(screen, (35, 35, 35), pygame.Rect(200, 25, 5, 460))
        pygame.draw.rect(screen, (35, 35, 35), pygame.Rect(400, 25, 5, 460))
        pygame.draw.rect(screen, (35, 35, 35), pygame.Rect(600, 25, 5, 460))
        return screen

    def get_image(self, path):
        image = self._image_library.get(path)
        if image == None:
                canonicalized_path = path.replace('/', os.sep).replace('\\', os.sep)
                image = pygame.image.load(canonicalized_path)
                self._image_library[path] = image
        return image

    def getBoardPosition(self, x, y):
        if (x < 200): column = 0
        elif (x < 400): column = 1
        else: column = 2

        if (y < 167): line = 0
        elif (y < 334): line = 1
        else: line = 2

        return (line, column)

    def drawVictoryLine(self, opt, ind):
        """
        Arguments:
            opt = 0  -> ind = number of the victory line
            opt = 1  -> ind = number of the victory column
            opt = 2  -> ind = 0 -> principal diagonal
                        ind = 1 -> secondary diagonal
        """

        if opt == 0:
            if ind == 0:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(10, 100, 580, 5))
            elif ind == 1:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(10, 250, 580, 5))
            else:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(10, 400, 580, 5))
        elif opt == 1:
            if ind == 0:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(100, 25, 5, 460))
            elif ind == 1:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(300, 25, 5, 460))
            elif ind == 2:
                pygame.draw.rect(self.screen, (255, 0, 0), pygame.Rect(500, 25, 5, 460))
        elif opt == 2:
            if ind == 0:
                pygame.draw.lines(self.screen, (255, 0, 0), False, [(24, 27), (575,479)], 7)
            elif ind == 1:
                pygame.draw.lines(self.screen, (255, 0, 0), False, [(25, 479), (564,27)], 7)

        pygame.display.flip()

    def checkWinner(self):
        """
        Returns:
            None if don't have a winner
            O if user won
            X if computer won
        """
        winner = None

        #Verify Lines
        for i in range(0, 3):
            if ((self.board[i][0] == self.board[i][1] == self.board[i][2]) and self.board[i][0] != None):
                winner = self.board[i][0]
                self.drawVictoryLine(0, i)
                return winner

        #Verify Columns
        for i in range(0, 3):
            if ((self.board[0][i] == self.board[1][i] == self.board[2][i]) and self.board[0][i] != None):
                winner = self.board[0][i]
                self.drawVictoryLine(1, i)
                return winner

        #Verify Diagonals
        if ((self.board[0][0] == self.board[1][1] == self.board[2][2]) and self.board[0][0] != None):
            winner = self.board[0][0]
            self.drawVictoryLine(2, 0)
            return winner

        if ((self.board[0][2] == self.board[1][1] == self.board[2][0]) and self.board[0][2] != None):
            winner = self.board[0][2]
            self.drawVictoryLine(2, 1)
            return winner

        #Verify Draw Game
        cont = 0
        for i in range(0, 3):
            for j in range(0, 3):
                if self.board[i][j] != None:
                    cont += 1

        if cont == 9:
            print("Draw Game")
            font = pygame.font.SysFont("comicsansms", 80)
            text = font.render("Draw Game", True, (0, 128, 0))
            self.screen.blit(text,(300 - text.get_width() // 2, 250 - text.get_height() // 2))
            pygame.display.flip()
            return 'N'

        return None

if __name__ == "__main__":
    pygame.init()
    pygame.display.set_caption ('Tic-Tac-Toe')

    while True:
        game = Game()
        game.startGame()

        done = True
        while done:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
                elif event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
                    done = False

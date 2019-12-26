import pandas as pd
import numpy as np

class TransitionTable:
    def __init__(self):
        self.transition_table = [[-1 for _ in range(75)] for _ in range(53)]
        self.state_status = {}
        self.key_to_column = {}
        self.column_to_key = {}

        table_csv = pd.read_csv("tables/transition_table.csv")
        columns = table_csv.columns.tolist()

        for column, key in enumerate(columns):
            self.key_to_column[key] = column
            self.column_to_key[column] = key

        for state, row in table_csv.iterrows():
            self.state_status[state] = False if row[0] == 'N' else True

            for i in range(1, len(row)):
                key = columns[i]
                if np.isnan(row[i]):
                    self.transition_table[state][self.key_to_column[key]] = -1
                else:
                    self.transition_table[state][self.key_to_column[key]] = int(row[i])

    def move(self, state, char):
        if char in self.key_to_column:
            return self.transition_table[state][self.key_to_column[char]]
        else:
            return None

    def is_final_state(self, state):
        if state == -1:
            return False
        return self.state_status[state]

    def get_token_type(self, state):
        if state == 8 or state == 10 or state == 13:
            return 'numero'
        elif state == 14:
            return 'id'
        else:
            return None

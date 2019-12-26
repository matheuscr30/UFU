import pandas as pd
import numpy as np

class PredictiveTable:
    def __init__(self):
        self.predictive_table = {}
        self.productions_by_id = {
            1: ['programa', 'bloco'],
            2: ['inicio', 'declaracao', 'comandos', 'fim'],
            3: ['tipo', 'id', ';', 'declaracao'],
            4: ['e'],
            5: ['int'],
            6: ['char'],
            7: ['real'],
            8: ['se', '(', 'condicao', ')', 'bloco', 'comandos'],
            9: ['enquanto', '(', 'condicao', ')', 'bloco', 'comandos'],
            10: ['id', 'atrop', 'expressao', ';', 'comandos'],
            11: ['e'],
            12: ['termo', 'relop', 'termo'],
            13: ['termo', 'expressao\''],
            14: ['artop', 'termo', 'expressao\''],
            15: ['atrop', 'termo', 'expressao\''],
            16: ['e'],
            17: ['id'],
            18: ['numero'],
            19: ['(', 'expressao', ')'],
            20: ['=='],
            21: ['<>'],
            22: ['<'],
            23: ['>'],
            24: ['<='],
            25: ['>='],
            26: ['+'],
            27: ['-'],
            28: ['*'],
            29: ['/'],
            30: ['=']
        }

        table_csv = pd.read_csv("tables/predictive_table.csv", index_col=0)
        columns = table_csv.columns.tolist()

        for index, row in table_csv.iterrows():
            self.predictive_table[index] = {}
            for i in range(0, len(row)):
                if np.isnan(row[i]):
                    self.predictive_table[index][columns[i]] = -1
                else:
                    self.predictive_table[index][columns[i]] = int(row[i])

    def move(self, terminal, not_terminal):
        if terminal in self.predictive_table and not_terminal in self.predictive_table[terminal]:
            return self.predictive_table[terminal][not_terminal]
        else:
            return -1

    def get_production_by_id(self, id):
        return self.productions_by_id[id]

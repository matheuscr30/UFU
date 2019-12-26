import pandas as pd
import numpy as np
import string

def create_predictive_table():
    index = pd.Index(['S', 'bloco', 'declaracao', 'tipo', 'comandos', 'condicao', 'expressao',
    'expressao\'', 'termo', 'relop', 'artop', 'atrop'], 'rows')

    columns = pd.Index(['programa', 'inicio', 'fim', 'id', ';', 'int', 'char', 'real', 'se', '(', ')', 'enquanto', '==', '<>', '<', '<=', '>', '>=',
    '+', '-', '*', '/', '=', '$', 'numero'], 'cols')

    table = pd.DataFrame(columns=columns, index=index)
    table = set_productions(table)
    table.to_csv('tables/predictive_table.csv', encoding='utf-8')

def set_productions(table):
    table['programa']['S'] = 1
    table['inicio']['bloco'] = 2

    table['fim']['declaracao'] = 4
    table['fim']['comandos'] = 11

    table['id']['declaracao'] = 4
    table['id']['comandos'] = 10
    table['id']['condicao'] = 12
    table['id']['expressao'] = 13
    table['id']['termo'] = 17

    table[';']['expressao\''] = 16

    table['int']['declaracao'] = 3
    table['int']['tipo'] = 5

    table['char']['declaracao'] = 3
    table['char']['tipo'] = 6

    table['real']['declaracao'] = 3
    table['real']['tipo'] = 7

    table['se']['declaracao'] = 4
    table['se']['comandos'] = 8

    table['(']['condicao'] = 12
    table['(']['expressao'] = 13
    table['(']['termo'] = 19

    table[')']['expressao\''] = 16

    table['enquanto']['declaracao'] = 4
    table['enquanto']['comandos'] = 9

    table['==']['relop'] = 20
    table['<>']['relop'] = 21
    table['<']['relop'] = 22
    table['<=']['relop'] = 24
    table['>']['relop'] = 23
    table['>=']['relop'] = 25

    table['+']['expressao\''] = 14
    table['+']['artop'] = 26
    table['-']['expressao\''] = 14
    table['-']['artop'] = 27
    table['*']['expressao\''] = 14
    table['*']['artop'] = 28
    table['/']['expressao\''] = 14
    table['/']['artop'] = 29

    table['=']['expressao\''] = 15
    table['=']['atrop'] = 30

    table['numero']['condicao'] = 12
    table['numero']['expressao'] = 13
    table['numero']['termo'] = 18

    return table

def create_transition_table():
    columns = ['FS']
    columns.extend([str(x) for x in range(0, 10)]) # 0 - 9
    columns.extend(string.ascii_uppercase) # A - Z
    columns.extend(string.ascii_lowercase) # a - z
    columns.extend(['(', ')', ';', '+', '-', '*', '/', '=', '<', '>', '.', '_'])

    table = pd.DataFrame(columns=columns, index=np.arange(53))
    table = set_final_states(table)
    table = set_transitions(table)
    table.to_csv('tables/transition_table.csv', encoding='utf-8', index=False)

def set_final_states(table):
    table['FS'][0] = 'N'
    table['FS'][1] = 'S'
    table['FS'][2] = 'S'
    table['FS'][3] = 'S'
    table['FS'][4] = 'S'
    table['FS'][5] = 'S'
    table['FS'][6] = 'S'
    table['FS'][7] = 'S'
    table['FS'][8] = 'S'
    table['FS'][9] = 'N'
    table['FS'][10] = 'S'
    table['FS'][11] = 'N'
    table['FS'][12] = 'N'
    table['FS'][13] = 'S'
    table['FS'][14] = 'S'
    table['FS'][15] = 'N'
    table['FS'][16] = 'N'
    table['FS'][17] = 'N'
    table['FS'][18] = 'S'
    table['FS'][19] = 'N'
    table['FS'][20] = 'N'
    table['FS'][21] = 'N'
    table['FS'][22] = 'S'
    table['FS'][23] = 'N'
    table['FS'][24] = 'N'
    table['FS'][25] = 'S'
    table['FS'][26] = 'N'
    table['FS'][27] = 'N'
    table['FS'][28] = 'N'
    table['FS'][29] = 'S'
    table['FS'][30] = 'N'
    table['FS'][31] = 'S'
    table['FS'][32] = 'N'
    table['FS'][33] = 'N'
    table['FS'][34] = 'S'
    table['FS'][35] = 'N'
    table['FS'][36] = 'N'
    table['FS'][37] = 'N'
    table['FS'][38] = 'N'
    table['FS'][39] = 'N'
    table['FS'][40] = 'N'
    table['FS'][41] = 'N'
    table['FS'][42] = 'S'
    table['FS'][43] = 'N'
    table['FS'][44] = 'N'
    table['FS'][45] = 'N'
    table['FS'][46] = 'N'
    table['FS'][47] = 'N'
    table['FS'][48] = 'N'
    table['FS'][49] = 'N'
    table['FS'][50] = 'S'
    table['FS'][51] = 'S'
    table['FS'][52] = 'N'
    return table

def set_transitions(table):
    for x in range(0, 10):
        x_str = str(x)
        table[x_str][0] = 8
        table[x_str][8] = 8
        table[x_str][9] = 10
        table[x_str][10] = 10
        table[x_str][11] = 13
        table[x_str][12] = 13
        table[x_str][13] = 13

        for j in range(14, 51):
            table[x_str][j] = 14

    for x_lower in string.ascii_lowercase:
        x_upper = x_lower.upper()
        table[x_lower][0] = 14
        table[x_upper][0] = 14

        for j in range(14, 51):
            table[x_lower][j] = 14
            table[x_upper][j] = 14

    for x in range(14, 51):
        table['_'][x] = 14

    table['('][0] = 1
    table[')'][0] = 1
    table[';'][0] = 1
    table['+'][0] = 51
    table['-'][0] = 51
    table['*'][0] = 51
    table['/'][0] = 51

    table['='][0] = 2
    table['='][2] = 3

    table['<'][0] = 4
    table['>'][4] = 5
    table['='][4] = 6

    table['>'][0] = 7
    table['='][7] = 6

    table['.'][8] = 9
    table['E'][8] = 11
    table['E'][10] = 11
    table['+'][11] = 12
    table['-'][11] = 12

    table['r'][0] = 15
    table['e'][15] = 16
    table['a'][16] = 17
    table['l'][17] = 18

    table['c'][0] = 19
    table['h'][19] = 20
    table['a'][20] = 21
    table['r'][21] = 22

    table['i'][0] = 23
    table['n'][23] = 24
    table['t'][24] = 25
    table['i'][24] = 26
    table['c'][26] = 27
    table['i'][27] = 28
    table['o'][28] = 29

    table['s'][0] = 30
    table['e'][30] = 31

    table['f'][0] = 32
    table['i'][32] = 33
    table['m'][33] = 34

    table['p'][0] = 35
    table['r'][35] = 36
    table['o'][36] = 37
    table['g'][37] = 38
    table['r'][38] = 39
    table['a'][39] = 40
    table['m'][40] = 41
    table['a'][41] = 42

    table['e'][0] = 43
    table['n'][43] = 44
    table['q'][44] = 45
    table['u'][45] = 46
    table['a'][46] = 47
    table['n'][47] = 48
    table['t'][48] = 49
    table['o'][49] = 50

    return table

if __name__ == '__main__':
    create_transition_table()
    create_predictive_table()

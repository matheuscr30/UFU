from HelpersCsv import ParseCsv
from HelpersCsv import WriteCsv
import argparse, sys

parser = argparse.ArgumentParser()
parser.add_argument('--path', '-p', help="path of input data", type=str)
parser.add_argument('--hasheaders', '-hh', help="if file has headers", type=int, default=0)

def calculate_average_or_mode(data):
    if not len(data):
        return

    num_columns = len(data[0])
    filling_per_column = {}
    values_for_filling_per_column = []

    for row in data:
        for i in range(0, num_columns):
            val = row[i]

            if val.isdecimal():
                if i not in filling_per_column:
                    filling_per_column[i] = {'sum': 0, 'count': 0}

                filling_per_column[i]['sum'] += float(val)
                filling_per_column[i]['count'] += 1
            elif val != '?' and val != '':
                if i not in filling_per_column:
                    filling_per_column[i] = {}

                filling_per_column[i][val] = filling_per_column[i].get(val, 0) + 1

    for i in range(0, num_columns):
        if i not in filling_per_column:
            values_for_filling_per_column.append('')

        if 'sum' in filling_per_column[i]:
            val = filling_per_column[i]['sum'] / filling_per_column[i]['count']
            values_for_filling_per_column.append(val)
        else:
            max_count = 0
            val_choosen = None

            for val, count in filling_per_column[i].items():
                if count > max_count:
                    max_count = count
                    val_choosen = val

            values_for_filling_per_column.append(val_choosen)

    return values_for_filling_per_column

def fill_missing_values(data, values_for_filling):
    if not len(data):
        return

    for row in data:
        for i in range(0, len(row)):
            if row[i] == '?' or row[i] == '':
                row[i] = values_for_filling[i]

    return data

if __name__ == '__main__':
    args = parser.parse_args()

    pcsv = ParseCsv(args.path, has_headers=args.hasheaders)
    data = pcsv.get_data()

    values_for_filling = calculate_average_or_mode(data)
    new_data = fill_missing_values(data, values_for_filling)

    wcsv = WriteCsv()
    wcsv.write_data(new_data)

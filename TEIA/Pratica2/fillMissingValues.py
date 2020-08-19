from ParseCsv import ParseCsv

def calculate_average_or_mode(data):
    if not len(data):
        return

    auxFillingPerColumn = {}
    valuesForFillingPerColumn = []

    for row in data:
        for i in range(0, len(row)):
            val = row[i]

            if val.isdecimal():
                if i not in auxFillingPerColumn:
                    auxFillingPerColumn[i] = {'sum': 0, 'count': 0}

                auxFillingPerColumn[i]['sum'] += float(val)
                auxFillingPerColumn[i]['count'] += 1
            elif val != '?' and val != '':
                if i not in auxFillingPerColumn:
                    auxFillingPerColumn[i] = {}

                auxFillingPerColumn[i][val] = auxFillingPerColumn[i].get(val, 0) + 1

    for i in range(0, len(data[0])):
        if i not in auxFillingPerColumn:
            valuesForFillingPerColumn.append('')

        if 'sum' in auxFillingPerColumn[i]:
            valuesForFillingPerColumn.append(auxFillingPerColumn[i]['sum'] / auxFillingPerColumn[i]['count'])
        else:
            maxCount = 0
            valChoosen = None

            for val, count in auxFillingPerColumn[i].items():
                if count > maxCount:
                    maxCount = count
                    valChoosen = val

            valuesForFillingPerColumn.append(valChoosen)

    print(valuesForFillingPerColumn)


if __name__ == '__main__':
    path = './student-por.csv'
    pcsv = ParseCsv(path, has_headers=True)
    data = pcsv.get_data()

    calculate_average_or_mode(data)

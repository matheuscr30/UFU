class ParseCsv():
    def __init__(self, path, has_headers=False):
        self.path = path
        self.file = open(path, 'r')
        self.has_headers = has_headers
        self.headers = []
        self.data = []

    def split_line(self, line):
        line = line.strip('\n')

        if not len(line):
            return None

        # If the rows are separated by commas
        data = line.split(',')

        # If not parse by ;
        if len(data) <= 1:
            data = line.split(';')

        # Strip leading and ending spaces
        data = [v.strip() for v in data]
        return data

    def get_data(self):
        if self.has_headers:
            line = self.file.readline()
            self.headers = self.split_line(line)

        for line in self.file:
            data_line = self.split_line(line)

            if data_line:
                self.data.append(data_line)

        self.file.close()
        return self.data


class WriteCsv():
    def __init__(self, path=''):
        self.path = path
        self.filename = 'result.csv'
        self.file = open(self.path + self.filename, 'w+')

    def join_line(self, data_line):
        data_line = [str(v) for v in data_line]
        line = ','.join(data_line)
        line += '\n'
        return line

    def write_data(self, data):
        for data_line in data:
            line = self.join_line(data_line)
            self.file.write(line)

        self.file.close()

class ParseCsv():
    def __init__(self, path, has_headers=False):
        self.path = path
        self.file = open(path, 'r')
        self.has_headers = has_headers
        self.headers = []
        self.data = []

    def split_line(self, line):
        line = line.strip('\n')

        # If the rows are separated by commas
        data = line.split(',')
        if len(data) > 1:
            return data

        # If not parse by ;
        data = line.split(';')
        return data

    def get_data(self):
        if self.has_headers:
            line = self.file.readline()
            self.headers = self.split_line(line)

        for line in self.file:
            self.data.append(self.split_line(line))

        return self.data

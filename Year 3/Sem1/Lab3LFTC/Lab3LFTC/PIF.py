class PIF:
    def __init__(self):
        self.data = []

    def add(self, codTblID, guid):
        self.data.append((codTblID, guid))

    def __str__(self):
        return str(self.data)

    def getData(self):
        return self.data

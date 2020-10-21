
operators = ["+", "-", "*", "/", "este", "maiMic", "maiMare", "maiMicEgal", "egal", "nuEgal", "maiMareEgal"]
separators = ["[", "]", "(", ")", "{", "}", ",", ":", ";", " "]
reserved = ["char", "string", "int", "float", "bool", "const", "totFacemPasi", "totFacem", "totFacemDaca", "daca", "altDaca", "dacaNu", "citeste", "scrie"]

spec = operators + separators + reserved;
codificationTable = {"constant": 0, "identifier": 1}

for i in range(len(spec)):
    codificationTable[spec[i]] = i + 2
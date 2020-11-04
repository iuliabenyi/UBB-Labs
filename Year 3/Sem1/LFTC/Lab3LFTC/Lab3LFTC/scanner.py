from specifications import *
import re

class Scanner:
    def isIdentifier(token):
        #first character letter, the next ones letters, digits and _
        return re.match(r"^[a-zA-Z]([a-zA-Z]|[0-9]|_){,7}$", token) is not None

    def isConstant(token):
        #something between ""
        return re.match('^(0|[+-]?[1-9][0-9]*)$', token) is not None or re.match('^\".*\"$', token) is not None

    def isOperator(token):
        return token in operators

    def isSeparator(token):
        return token in separators

    def fullOperator(line, i):
        token = ''
        while i < len(line) and Scanner.isOperator(line[i]):
            token += line[i]
            i += 1
        return token, i

    def fullSeparator(line, i):
        token = ''
        while i < len(line) and Scanner.isSeparator(line[i]):
            token += line[i]
            i += 1
        return token, i

    def getStr(line, indx):
        token = ''
        quotes = 0
        while indx < len(line) and quotes < 2:
            if line[indx] == '"':
                quotes += 1
            token += line[indx]
            indx += 1
        return token, indx

    def scanning(line):
        token = ''
        indx = 0
        while indx < len(line):
            if line[indx] == '"':
                if token:
                    yield token
                token, indx = Scanner.getStr(line, indx)
                yield token
                token = ''  # make empty
            elif Scanner.isOperator(line[indx]):
                if token:
                    yield token
                token, indx = Scanner.fullOperator(line, indx)
                yield token
                token = ''  # make empty
            elif line[indx] in separators:
                if token:
                    yield token
                #token, indx = Scanner.fullSeparator(line, indx)
                token, indx = line[indx], indx + 1
                yield token
                token = ''  # make empty
            else:
                token += line[indx]
                indx += 1
        if token:
            yield token

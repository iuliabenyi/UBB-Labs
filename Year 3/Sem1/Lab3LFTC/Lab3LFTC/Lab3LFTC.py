from scanner import *
from SymTbl import * #a0a
from PIF import *

def main():
    file = open('p3err.txt', 'r')
    output = open("output.txt", "a")
    st = SymTbl()
    pif = PIF()

    line_index = 0
    for line in file:
        line_index += 1
        if line[0] == '#':
            print("\n\n==========================================================\n")
            print("Line at index {} is a comment.".format(line_index))
            print("\n\n==========================================================\n")
            continue

        if line[-1] == '\n':
            line = line[0:-1]  # Skip \n

        ok = 1
        for token in Scanner.scanning(line):
            if token in spec:
                pif.add(codificationTable[token], -1)
            elif Scanner.isIdentifier(token):
                # Add and return id or just return id
                pif.add(codificationTable['identifier'], st.put(token))
            elif Scanner.isConstant(token):
                # Add and return id or just return id
                pif.add(codificationTable['constant'], st.put(token))
            else:
                print("\n\n==========================================================\n")
                print("Unknown token '{}' at line {}!".format(token, line_index))
                print("\n\n==========================================================\n")
                ok = 0
    if ok == 1:
        print("\n\n==========================================================\n")
        print("Everything is ok")
        print("\n\n==========================================================\n")

    print("\n\n==========================================================\n")
    print("Symbol table: ")
    st.display()
    print("\n\n==========================================================\n")
    print("Program internal form: {}".format(pif))
    print("\n\n==========================================================\n")

if __name__ == '__main__':
    main()
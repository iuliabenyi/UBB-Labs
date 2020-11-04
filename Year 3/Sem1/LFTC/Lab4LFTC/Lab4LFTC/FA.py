
class FA:
    def __init__(self, Q, E, q0, F, S):
        self.Q = Q # set of states 
        self.E = E # set of input symbol 
        self.q0 = q0 # initial state 
        self.F = F # final state
        self.S = S # transitions

    # get what's after '='
    def parseInfo(line):
        return line.strip().split(' ')[2:]

    def readFA(file):
        with open(file) as f:
            Q = FA.parseInfo(f.readline())
            E = FA.parseInfo(f.readline())
            q0 = FA.parseInfo(f.readline())[0] # the letter from the initial state
            F = FA.parseInfo(f.readline())

            f. readline() # the line with just 'S'

            S = []
            for line in f:
                first = line.strip().split('->')[0].strip().replace('(', '').replace(')', '').split(',')[0]
                second = line.strip().split('->')[0].strip().replace('(', '').replace(')', '').split(',')[1]
                third = line.strip().split('->')[1].strip()
                S.append(((first, second), third))

            return FA(Q, E, q0, F, S)

    def displayQ(self):
        return "{ " + ', '.join(self.Q) + " }\n"

    def displayE(self):
        return "{ " + ', '.join(self.E) + " }\n"

    def displayF(self):
        return "{ " + ', '.join(self.F) + " }\n"

    def displayS(self):
        return "{ " + str(self.S) + " }\n"

    def menu(self):
        print("1 - Display the set of states")
        print("2 - Display the alphabet")
        print("3 - Display the transitions")
        print("4 - Display the set of final states")
        print("0 - Exit")
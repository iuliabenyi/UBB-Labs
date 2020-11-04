from FA import *



def main():
    fa = FA.readFA("FA.in")
    while(True):
        fa.menu()
        cmd = int(input())
        if cmd == 0:
            exit(0)
        elif cmd == 1:
            print(fa.displayQ())
        elif cmd == 2:
            print(fa.displayE())
        elif cmd == 3:
            print(fa.displayS())
        elif cmd == 4:
            print(fa.displayF())
        else:
            print("Wrong input!")

if __name__ == '__main__':
    main()
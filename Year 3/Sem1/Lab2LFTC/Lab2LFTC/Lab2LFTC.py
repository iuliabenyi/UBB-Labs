from SymTbl import *

symTbl = SymTbl(5)
print('a1: ' + str(symTbl.put('a1')))
print('name1: ' + str(symTbl.put('name1')))
print('name2: ' + str(symTbl.put('name2')))
print('name3: ' + str(symTbl.put('name3')))
print('name3: ' + str(symTbl.put('name3')))
print('123455: ' + str(symTbl.put('123455')))

print('aaaaaaaaaaaaaaaaa: ' + str(symTbl.lookup('aaaaaaaaaaaaaaaaa')))
print('123455: ' + str(symTbl.lookup('123455')))
symTbl.display()

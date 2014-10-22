#coding=utf-8 
import os
import codecs

names = []
fileNum = []
lineNum = []
maxLineDict = {}
for name in os.listdir('.'):
    if name == 'summary.py':
        continue
    names.append(name)
    fileNum.append(0)
    lineNum.append(0)
    dir = os.path.join('.', name)
    for file in os.listdir(dir):
        fh = open(os.path.join(dir, file), "r")
        l = len(fh.readlines())
        fh.close()
        fileNum[-1] = fileNum[-1] + 1
        lineNum[-1] = lineNum[-1] + l
        maxLineDict[l] = file
for i in range(len(names)):
    for j in range(i + 1, len(names)):
        if lineNum[i] < lineNum[j]:
            names[i], names[j] = names[j], names[i]
            fileNum[i], fileNum[j] = fileNum[j], fileNum[i]
            lineNum[i], lineNum[j] = lineNum[j], lineNum[i]
names.append("Total")
fileNum.append(sum(fileNum))
lineNum.append(sum(lineNum))
for i in range(len(names)):
    space = ''.join([' ' for j in range(24 - len(names[i]))])
    print(names[i] + space + "File: " + str(fileNum[i]) + "\t\tLine: " + str(lineNum[i]))
print()
count = 0
for key in maxLineDict.keys():
    count = count + 1
    if len(maxLineDict) - count > 10:
        continue
    space = ''.join([' ' for i in range(10 - len(str(key)))])
    print(str(key) + space)
import os

names = []
fileNum = []
lineNum = []
for name in os.listdir('.'):
    if name == 'summary.py':
        continue
    names.append(name)
    fileNum.append(0)
    lineNum.append(0)
    dir = os.path.join('.', name)
    for file in os.listdir(dir):
        fh = open(os.path.join(dir, file), "r")
        fileNum[-1] = fileNum[-1] + 1
        lineNum[-1] = lineNum[-1] + len(fh.readlines())
        fh.close()
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
    
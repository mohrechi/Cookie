a = raw_input()
b = raw_input()
index, count = 0, 0
while True:
    index = a.find(b, index)
    if index == -1:
        break
    index += len(b)
    count += 1
print count

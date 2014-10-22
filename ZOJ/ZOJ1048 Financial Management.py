sum = 0.0
for i in range(12):
    n = float(input())
    sum += n
print("$" + "%.2f" % (sum / 12))
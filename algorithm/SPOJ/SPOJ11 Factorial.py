for case in range(int(raw_input(""))):
    n = int(raw_input(""))
    s = 0
    i = 5
    while i <= n:
        s += n/i
        i *= 5
    print(s)

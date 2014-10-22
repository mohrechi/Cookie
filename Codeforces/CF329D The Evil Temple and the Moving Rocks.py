n, x = map(int, raw_input().split())
if n == 5:
    print ">...v"
    print "v.<.."
    print "..^.."
    print ">...."
    print "..^.<"
    print 1, 1
elif n == 3:
    print ">vv"
    print "^<."
    print "^.<"
    print 1, 3
else:
    print ">" + ">" * 33 + ".>" * 32 + "v."
    for i in range(49):
        print "^v" + "<." * 32 + "<" * 33 + "."
        print "^" + ">" * 33 + ".>" * 32 + "v."
    print "^" + "<." * 32 + "<" * 33 + "<."
    print 1, 1

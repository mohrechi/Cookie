n, m = map(int, raw_input().split())
graph = set()
for i in range(m):
    u, v = map(int, raw_input().split())
    graph.add(u)
    graph.add(v)
print n - 1
for u in range(1, n + 1):
    if u not in graph:
        for v in range(1, n + 1):
            if v != u:
                print str(u) + " " + str(v)
        break

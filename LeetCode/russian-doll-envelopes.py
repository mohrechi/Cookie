class Solution(object):
    def cmp(self, a, b):
        if a[0] != b[0]:
            return a[0] - b[0]
        return b[1] - a[1]

    def maxEnvelopes(self, envelopes):
        envelopes.sort(self.cmp)
        stk = []
        for env in envelopes:
            h = env[1]
            if len(stk) == 0 or h > stk[-1]:
                stk.append(h)
            else:
                if len(stk) == 1:
                    if h < stk[0]:
                        stk[0] = h
                else:
                    l, r = 0, len(stk) - 1
                    pos = r
                    while l <= r:
                        mid = (l + r) >> 1
                        if h < stk[mid]:
                            r = mid - 1
                            pos = min(pos, mid)
                        else:
                            l = mid + 1
                    if pos == 0 or h > stk[pos - 1]:
                        stk[pos] = h
        return len(stk)

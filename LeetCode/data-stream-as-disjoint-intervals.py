class SummaryRanges(object):

    def __init__(self):
        self.ints = []
        

    def addNum(self, val):
        if len(self.ints) == 0:
            self.ints = [Interval(val, val)]
        else:
            b = 0
            l, r = 1, len(self.ints) - 1
            while l <= r:
                mid = (l + r) >> 1
                if val >= self.ints[mid].end:
                    l = mid + 1
                    b = max(b, mid)
                else:
                    r = mid - 1
            for i in xrange(b, len(self.ints)):
                if self.ints[i].start <= val <= self.ints[i].end:
                    return
                if val < self.ints[i].start:
                    if i == 0:
                        if val == self.ints[i].start - 1:
                            self.ints[0] = Interval(val, self.ints[0].end)
                        else:
                            self.ints = [Interval(val, val)] + self.ints
                    else:
                        if self.ints[i - 1].end + 1 == val and val == self.ints[i].start - 1:
                            self.ints = self.ints[:i-1] + [Interval(self.ints[i - 1].start, self.ints[i].end)] + self.ints[i+1:]
                        elif self.ints[i - 1].end + 1 == val:
                            self.ints[i - 1] = Interval(self.ints[i - 1].start, val)
                        elif val == self.ints[i].start - 1:
                            self.ints[i] = Interval(val, self.ints[i].end)
                        else:
                            self.ints = self.ints[:i] + [Interval(val, val)] + self.ints[i:]
                    return
            if self.ints[-1].end + 1 == val:
                self.ints[-1] = Interval(self.ints[-1].start, val)
            else:
                self.ints.append(Interval(val, val))
        

    def getIntervals(self):
        return self.ints

class NestedIterator(object):

    def __init__(self, nestedList):
        self.idx = 0
        self.lst = []
        for v in nestedList:
            self.flatten(v)

    def flatten(self, nestedList):
        if nestedList.isInteger():
            self.lst.append(nestedList.getInteger())
        else:
            for v in nestedList.getList():
                self.flatten(v)

    def next(self):
        v = self.lst[self.idx]
        self.idx += 1
        return v

    def hasNext(self):
        return self.idx < len(self.lst)

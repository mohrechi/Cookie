class Twitter(object):

    def __init__(self):
        self.date = 0
        self.published = {}
        self.pushList = {}
        self.messages = {}

    def checkInit(self, userId):
        if userId not in self.published:
            self.published[userId] = []
        if userId not in self.pushList:
            self.pushList[userId] = set([userId])
        if userId not in self.messages:
            self.messages[userId] = []

    def postTweet(self, userId, tweetId):
        self.checkInit(userId)
        self.date -= 1
        tweet = (self.date, userId, tweetId)
        self.published[userId].append(tweet)
        for push in self.pushList[userId]:
            self.messages[push].append(tweet)

    def getNewsFeed(self, userId):
        self.checkInit(userId)
        self.messages[userId].sort()
        return map(lambda x: x[2], self.messages[userId][:10])

    def follow(self, followerId, followeeId):
        self.checkInit(followerId)
        self.checkInit(followeeId)
        if followerId not in self.pushList[followeeId]:
            self.pushList[followeeId].add(followerId)
            print self.published[followeeId]
            self.messages[followerId] += self.published[followeeId]

    def unfollow(self, followerId, followeeId):
        self.checkInit(followerId)
        self.checkInit(followeeId)
        if followerId != followeeId and followerId in self.pushList[followeeId]:
            self.pushList[followeeId].remove(followerId)
            self.messages[followerId] = filter(lambda x: x[1] != followeeId, self.messages[followerId])

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        return not [True for s in ransomNote if ransomNote.count(s) > magazine.count(s)]

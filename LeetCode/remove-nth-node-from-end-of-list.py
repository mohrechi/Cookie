# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        if head is None:
            return head
        slow = head
        fast = head
        while n > 0:
            n -= 1
            fast = fast.next
        prev = None
        while fast is not None:
            fast = fast.next
            prev = slow
            slow = slow.next
        if prev is None:
            return head.next
        if slow is not None:
            prev.next = slow.next
        return head

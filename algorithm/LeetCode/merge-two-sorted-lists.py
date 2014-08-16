# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        head = None
        node = None
        while l1 is not None and l2 is not None:
            if l1.val < l2.val:
                if node is not None:
                    node.next = l1
                else:
                    head = l1
                node = l1
                l1 = l1.next
            else:
                if node is not None:
                    node.next = l2
                else:
                    head = l2
                node = l2
                l2 = l2.next
        while l1 is not None:
            if node is not None:
                node.next = l1
            else:
                head = l1
            node = l1
            l1 = l1.next
        while l2 is not None:
            if node is not None:
                node.next = l2
            else:
                head = l2
            node = l2
            l2 = l2.next
        return head

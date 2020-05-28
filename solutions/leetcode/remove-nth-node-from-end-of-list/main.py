# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        first = second = head
        second_prev = None
        for i in range(n):
            first = first.next

        while first is not None:
            first = first.next
            second_prev = second
            second = second.next

        if second_prev is not None:
            second_prev.next = second.next
        else:
            head = head.next
            
        return head

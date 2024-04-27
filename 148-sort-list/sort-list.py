# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        sentinel = ListNode(next = head)
        while head:
            arr.append(head.val)
            head = head.next
        arr.sort()
        c = 0 
        head2 = sentinel.next
        while head2:
            head2.val = arr[c]
            c += 1
            head2 = head2.next
        return sentinel.next
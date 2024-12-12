# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists is None or len(lists) == 0 :
            return None
        return self._mergeKLists(lists,0,len(lists)-1)
    def _mergeKLists(self,lists,start,end):
        if start==end:
            return lists[start]
        mid = start + (end-start)//2
        left = self._mergeKLists(lists,start,mid)
        right = self._mergeKLists(lists,mid+1,end)
        return self._merge(left,right)
    def _merge(self,left,right):
        result = ListNode(-1)
        curr = result
        while left is not None and right is not None:
            if left.val > right.val:
                curr.next = right
                right = right.next
            else:
                curr.next = left
                left = left.next
            curr = curr.next
        if left is None:
                curr.next = right
        elif right is None:
                curr.next = left
        return result.next
                
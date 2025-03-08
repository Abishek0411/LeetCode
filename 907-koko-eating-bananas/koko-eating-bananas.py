import math
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right =1, max(piles)

        def canFinisheating(k):
            hours_needed = sum(math.ceil(pile/k) for pile in piles)
            return hours_needed <= h
        
        while left<right:
            mid = (left+right)//2
            if canFinisheating(mid):
                right = mid
            else:
                left = mid+1
        return left
class Solution(object):
    def containsDuplicate(self, nums):
        exists = set()
        for num in nums:
            if num in exists:
                return True
            exists.add(num)
        return False
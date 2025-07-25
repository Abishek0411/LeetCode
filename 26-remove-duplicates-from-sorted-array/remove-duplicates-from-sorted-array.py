class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        l = 1
        for r in range(1, len(nums)):
            if nums[r] != nums[r-1]:  # [l-1] actually
                nums[l] = nums[r]
                l+=1
        return l
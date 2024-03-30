# Intuition
The Two Sum problem asks us to find two numbers in an array that sum up to a given target value. We need to return the indices of these two numbers.

# Approach
An efficient approach is to use a hash table. We can iterate through the array once, and for each element, check if the target minus the current element exists in the hash table. If it does, we have found a valid pair of numbers. If not, we add the current element to the hash table.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)

# Code
```
class Solution(object):
    def twoSum(self, nums, target):
        prevMap = {}

        for i, n in enumerate(nums):
            diff = target- n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i  
```

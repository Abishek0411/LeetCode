# Intuition
The intuition is to group words that are anagrams of each other together. Anagrams are words that have the same characters but in a different order.

# Approach
using hash table

# Complexity
- Time complexity:
O(m*n)

- Space complexity:
O(m*n)

# Code
```
class Solution(object):
    def groupAnagrams(self, strs):
        res = defaultdict(list) #mapping charCount to list of Anagrams

        for s in strs:
            count = [0] * 26  #a ... z

            for c in s:
                count[ord(c) - ord("a")] += 1

            res[tuple(count)].append(s)

        return res.values()
        
```

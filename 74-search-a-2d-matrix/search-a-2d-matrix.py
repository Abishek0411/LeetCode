class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])

        top, bot = 0, ROWS-1
        while top <= bot:
            row = (top+bot)//2
            if target > matrix[row][-1]:
                top = row+1
            elif target < matrix[row][0]:
                bot = row-1
            else:
                break  # Target exists in the current row
            
        if not top<=bot:
            return False
        #  we don’t know what the final row value was when the loop exited — it was only defined inside the loop scope.
        row = (top+bot)//2
        l, r = 0, COLS-1
        while l<=r:
            m = (l+r)//2
            if target > matrix[row][m]:
                l = m+1
            elif target < matrix[row][m]:
                r = m-1            
            else:
                return True
        return False
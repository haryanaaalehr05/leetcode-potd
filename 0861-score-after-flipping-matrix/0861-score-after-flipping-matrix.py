class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        def flipRow(r):
            for c in range(C):
                grid[r][c] = 1 - grid[r][c]

        def flipCol(c):
            for r in range(R):
                grid[r][c] = 1 - grid[r][c]

        def checkRow(nums):
            return int(''.join([str(n) for n in nums]), 2)

        R, C = len(grid), len(grid[0])

        for r in range(R):
            if grid[r][0] == 0:
                flipRow(r)

        for c in range(1, C):
            if sum(grid[r][c] for r in range(R)) * 2 < R:
                flipCol(c)

        return sum(checkRow(row) for row in grid)
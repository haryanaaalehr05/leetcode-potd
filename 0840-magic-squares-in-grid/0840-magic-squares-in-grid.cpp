class Solution {
public:
   bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        // Check if the numbers are distinct and between 1 to 9
        vector<int> nums(9);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9) return false;
                nums[val - 1]++;
            }
        }
        for (int num : nums) {
            if (num != 1) return false;
        }
        
        // Check if rows, columns and diagonals sum to 15
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        if (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] != sum) return false;
        if (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] != sum) return false;
        if (grid[r][c] + grid[r+1][c] + grid[r+2][c] != sum) return false;
        if (grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] != sum) return false;
        if (grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] != sum) return false;
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int r = 0; r <= rows - 3; ++r) {
            for (int c = 0; c <= cols - 3; ++c) {
                if (isMagicSquare(grid, r, c)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
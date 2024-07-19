class Solution {
public:
      vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Find the minimum element in each row
        vector<int> minRow(m, INT_MAX);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < minRow[i]) {
                    minRow[i] = matrix[i][j];
                }
            }
        }
        
        // Check if this minimum element is also the maximum in its column
        for (int i = 0; i < m; ++i) {
            int minElem = minRow[i];
            bool isLucky = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][find(matrix[i].begin(), matrix[i].end(), minElem) - matrix[i].begin()] > minElem) {
                    isLucky = false;
                    break;
                }
            }
            if (isLucky) {
                result.push_back(minElem);
            }
        }
        
        return result;
    }
};
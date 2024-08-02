class Solution {
public:
     int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        int k = std::count(nums.begin(), nums.end(), 1);
        
        // Double the array to handle circular nature
        std::vector<int> extendedNums(nums.begin(), nums.end());
        extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

        // Find the max number of 1s in any window of size k
        int currentOnes = 0;
        for (int i = 0; i < k; ++i) {
            currentOnes += extendedNums[i];
        }
        
        int maxOnes = currentOnes;
        for (int i = k; i < extendedNums.size(); ++i) {
            currentOnes += extendedNums[i] - extendedNums[i - k];
            maxOnes = std::max(maxOnes, currentOnes);
        }
        
        // Minimum swaps needed
        return k - maxOnes;
     }
};
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int ans = 0; // Minimum number of flips
        int flippedTime = 0; // Running count of flipped subarrays

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k && nums[i - k] == 2) {
                // Undo the effect of a previous flip
                --flippedTime;
            }

            if (flippedTime % 2 == nums[i]) {
                // Need to flip the current subarray
                if (i + k > nums.size()) {
                    // Impossible to flip all 0s to 1s
                    return -1;
                }
                ++ans;
                ++flippedTime;
                nums[i] = 2; // Mark the flipped position
            }
        }

        return ans;
    }
};
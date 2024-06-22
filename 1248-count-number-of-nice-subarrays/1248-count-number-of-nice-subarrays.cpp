class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        std::unordered_map<int, int> count; // Stores the count of prefix sums

    count[0] = 1; // Initialize with one way to have zero odd numbers (empty subarray)
    int ans = 0; // Final count of nice subarrays
    int t = 0; // Running count of odd numbers

    for (int num : nums) {
        t += num & 1; // Check if num is odd

        if (count.find(t - k) != count.end()) {
            ans += count[t - k]; // Add the count of valid subarrays
        }

        count[t]++; // Increment the count for the current prefix sum
    }

    return ans;
    }
};
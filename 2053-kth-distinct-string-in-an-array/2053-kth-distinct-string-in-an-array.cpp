class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> countMap;
        
        // Count the occurrences of each string
        for (const std::string& str : arr) {
            countMap[str]++;
        }
        
        // Find the k-th distinct string
        for (const std::string& str : arr) {
            if (countMap[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }
        
        return ""; // Return an empty string if there are fewer than k distinct strings
    }
};
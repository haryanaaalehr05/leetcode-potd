class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen = 0;
        int currCost = 0;
        int i = 0;

        for (int j = 0; j < s.size(); ++j) {
            currCost += abs(s[j] - t[j]);

            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                ++i;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};

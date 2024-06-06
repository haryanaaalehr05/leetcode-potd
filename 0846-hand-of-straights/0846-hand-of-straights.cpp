class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       map<int, int> count; // Count the frequency of each card value
        for (const int card : hand) {
            ++count[card];
        }

        for (const auto& [start, _] : count) {
            const int value = count[start];
            if (value > 0) {
                for (int i = start; i < start + groupSize; ++i) {
                    count[i] -= value;
                    if (count[i] < 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
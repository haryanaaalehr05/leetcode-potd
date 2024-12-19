class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0; // To track the maximum value seen so far
        int chunks = 0; // To count the number of chunks
        
        for (int i = 0; i < arr.size(); ++i) {
            maxVal = max(maxVal, arr[i]); // Update the maximum value
            // If the maximum value equals the current index, we can form a chunk
            if (maxVal == i) {
                chunks++;
            }
        }
        
        return chunks;
    }
};

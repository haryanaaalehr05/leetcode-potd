class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       int n = difficulty.size();
    
    // Pair the difficulty and profit together
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.push_back({difficulty[i], profit[i]});
    }
    
    // Sort the jobs based on difficulty
    sort(jobs.begin(), jobs.end());
    
    // Sort the worker abilities
    sort(worker.begin(), worker.end());
    
    int maxProfit = 0, i = 0, best = 0;
    
    // Traverse through the sorted workers
    for (int ability : worker) {
        // Update the best profit that can be obtained with the current ability
        while (i < n && jobs[i].first <= ability) {
            best = max(best, jobs[i].second);
            i++;
        }
        // Add the best profit for the current worker
        maxProfit += best;
    }
    
    return maxProfit;
    }
};
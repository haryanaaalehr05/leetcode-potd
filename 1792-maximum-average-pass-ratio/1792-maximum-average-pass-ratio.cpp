class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
 auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap to store gain and class data
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes)
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});

        while (extraStudents--) {
            auto [_, classData] = pq.top(); pq.pop();
            int pass = classData.first, total = classData.second;
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
        }

        double avg = 0;
        while (!pq.empty()) {
            auto [_, classData] = pq.top(); pq.pop();
            avg += (double)classData.first / classData.second;
        }

        return avg / classes.size();
    }
};
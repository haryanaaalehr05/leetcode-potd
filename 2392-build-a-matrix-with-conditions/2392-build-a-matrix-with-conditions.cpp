class Solution {
public:
     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        vector<int> rowPos(k + 1), colPos(k + 1);

        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            matrix[rowPos[i]][colPos[i]] = i;
        }

        return matrix;
    }

    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        vector<vector<int>> graph(k + 1);

        for (const auto& condition : conditions) {
            int u = condition[0], v = condition[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : graph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() != k) {
            return {};
        }

        return order;
    }
};
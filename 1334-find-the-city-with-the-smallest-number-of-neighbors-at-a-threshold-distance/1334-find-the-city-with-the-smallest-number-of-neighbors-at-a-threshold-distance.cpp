class Solution {
public:
   int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
        
        // Distance to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Step 2: Fill the distance matrix with given edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;  // Because the graph is bidirectional
        }
        
        // Step 3: Apply Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Step 4: Find the city with the smallest number of reachable cities within distanceThreshold
        int resultCity = -1;
        int minReachable = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachable;
                }
            }
            
            // Check for the city with the fewest reachable cities
            if (reachable < minReachable || (reachable == minReachable && i > resultCity)) {
                minReachable = reachable;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};
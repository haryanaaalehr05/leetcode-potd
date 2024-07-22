class Solution {
public:
   vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Step 1: Pair the heights and names together
        vector<pair<int, string>> people;
        int n = names.size();
        for (int i = 0; i < n; ++i) {
            people.push_back({heights[i], names[i]});
        }

        // Step 2: Sort the pairs based on the heights in descending order
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first; // compare heights in descending order
        });

        // Step 3: Extract the names from the sorted pairs
        vector<string> sortedNames;
        for (const auto& person : people) {
            sortedNames.push_back(person.second);
        }

        return sortedNames;
   }
};
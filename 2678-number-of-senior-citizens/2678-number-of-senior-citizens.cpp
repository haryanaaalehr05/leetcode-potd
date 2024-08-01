class Solution {
public:
   int countSeniors(std::vector<std::string>& details) {
        int seniorCount = 0;
        for (const std::string& detail : details) {
            // Extract the age part of the string (11th and 12th characters)
            int age = std::stoi(detail.substr(11, 2));
            if (age > 60) {
                seniorCount++;
            }
        }
        return seniorCount;
    }
};
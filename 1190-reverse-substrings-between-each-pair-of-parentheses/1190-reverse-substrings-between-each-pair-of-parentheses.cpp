class Solution {
public:
   string reverseParentheses(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == ')') {
                string temp;
                
                // Pop characters until finding an opening parenthesis '('
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                
                // Pop the '(' from the stack
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                
                // Push the reversed string back onto the stack
                for (char ch : temp) {
                    st.push(ch);
                }
            } else {
                // Push other characters onto the stack
                st.push(c);
            }
        }
        
        // Collect the result from the stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Since the stack reverses the order, reverse the result string before returning
        reverse(result.begin(), result.end());
        
        return result;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() % 2 != 0) return false;

        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || s[i] != st.top()) return false; // right brackets redundent or brackets are not matched
            else st.pop(); // brackets are matched
        }
        return st.empty(); // true if all matched, false if left brackets redundent
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
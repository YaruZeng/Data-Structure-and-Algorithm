class Solution {
public:
    string removeDuplicates(string s) {
        string result; // use string as a stack
        for (char c : s) {
            if (result.empty() || c != result.back()) {
                result.push_back(c);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
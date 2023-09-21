class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};

        if (ransomNote.size() > magazine.size()) return false;

        for (int i = 0; i < magazine.size(); i++) {
            hash[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            hash[ransomNote[i] - 'a']--;
            if (hash[ransomNote[i] - 'a'] < 0) return false;
        }

        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
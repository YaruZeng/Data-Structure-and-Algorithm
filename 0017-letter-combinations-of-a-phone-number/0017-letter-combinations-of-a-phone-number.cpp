class Solution {
public:
    string s;
    vector<string> result;

    string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void backtracking(const string& digits, int index) {
        if (s.size() == digits.size()) {
            result.push_back(s);
            return;
        }

        int letterIndex = digits[index] - '0';
        string letter = letterMap[letterIndex];
        for (int i = 0; i < letter.size(); i++) {
            s.push_back(letter[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        backtracking(digits, 0);
        return result;
    }
};
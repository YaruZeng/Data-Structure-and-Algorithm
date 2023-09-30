class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int k, int targetSum, int sum, int startIndex) {
        if (sum > targetSum) return;
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            sum += i;
            backtracking(k, targetSum, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    } 

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
    }
};
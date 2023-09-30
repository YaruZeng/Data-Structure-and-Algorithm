class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<vector<int>>& graph, int x) {
        if (x == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            backtracking(graph, graph[x][i]);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        backtracking(graph, 0);
        return result;
    }
};
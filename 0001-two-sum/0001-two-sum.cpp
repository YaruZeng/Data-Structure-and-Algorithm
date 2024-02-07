class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (umap.find(complement) != umap.end()) {
                return {umap[complement], i};
            }
            umap.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap; // to store traversed nums and their indices
        
        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if (umap.count(compliment)) { // if find the compliment in the traversed nums
                return {umap[compliment], i}; // return the two indices
            } else {
                umap[nums[i]] = i; // if not, store the traversed num:i pair into the map
            }
        }
        return {}; // no valid result
    }
};
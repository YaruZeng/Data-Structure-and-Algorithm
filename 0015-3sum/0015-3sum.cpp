class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort nums ascendingly

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return result;

            if (i > 0 && nums[i] == nums[i - 1]) continue; // avoid repeatitive nums[i]

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++; // avoid repeatitive nums[left]
                    while (left < right && nums[right] == nums[right - 1]) right--; // avoid repeatitive nums[right]
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
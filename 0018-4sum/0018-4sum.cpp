class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); k++) { // the first number
            if (nums[k] > target && nums[k] >= 0) break;

            if (k > 0 && nums[k] == nums[k - 1]) continue;

            for (int i = k + 1; i < nums.size(); i++) { // the second number 
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) break; // cannot use return result, case: [-3,-2,-1,0,0,1,2,3] when [nums[k], nums[i]] is [-2,3]

                if (i > k + 1 && nums[i] == nums[i - 1]) continue;

                int left = i + 1; // the third number 
                int right = nums.size() - 1; // the forth number 

                while (left < right) {
                    if ((long) nums[i] + nums[k] + nums[left] + nums[right] < target) left++;
                    else if ((long) nums[i] + nums[k] + nums[left] + nums[right] > target) right--;
                    else {
                        result.push_back(vector<int>{nums[i], nums[k], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(1)
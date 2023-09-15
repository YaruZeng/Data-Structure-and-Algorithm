class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // bruce force
        // for (int i = 0; i < nums.size(); i++) {
        //     nums[i] = nums[i] * nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        
        // two pointers: start from two ends, get the larger one stored in the result
        
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        
        for (int k = nums.size() - 1; k >= 0; k--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[k] = nums[left] * nums[left++];
            } else {
                result[k] = nums[right] * nums[right--];
            }
        }
        return result;
    }
};
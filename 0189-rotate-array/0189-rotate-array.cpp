class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    
    // time complexity: O(n), space complexity: O(1); case: nums = [1,2,3,4,5,6,7], k = 3
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); // in case that k > nums.size()
        reverse(nums, 0, nums.size() - k - 1); // nums = [4,3,2,1,5,6,7]
        reverse(nums, nums.size() - k, nums.size() - 1); // nums = [4,3,2,1,7,6,5]
        reverse(nums, 0, nums.size() - 1); // nums = [5,6,7,1,2,3,4]
    }
};
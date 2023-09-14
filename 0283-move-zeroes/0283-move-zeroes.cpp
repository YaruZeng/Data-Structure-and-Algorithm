class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // define two pointers, left stores the non-zero numbers, right iterates numbers
        int left = 0;
        int right = 1;
        
        while (right != nums.size()) {
            if (nums[left] != 0) { // avoid situations where the first num is non-zero, e.g.[2,1]
                left++;
                right++;
            } else if (nums[right] != 0) { // encounter a non-zero number
                nums[left] = nums[right];
                left++;
                nums[right] = 0;
                right++;
            } else {
                right++;
            }
        }
    }
};
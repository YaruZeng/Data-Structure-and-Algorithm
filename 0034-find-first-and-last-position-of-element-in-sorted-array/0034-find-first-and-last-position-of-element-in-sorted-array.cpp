class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPosition = -1;
        int endPosition = -1;
        int left = 0;
        int right = nums.size() - 1;
        
        // to find the starting position
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                startPosition = mid;
                right = mid - 1; // make sure the position is the starting one
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        
        // to find the ending position
        
        left = 0; 
        right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                endPosition = mid;
                left = mid + 1; // make sure the position is the ending one
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return {startPosition, endPosition};
    }
};
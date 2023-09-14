class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int notTargetIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[notTargetIndex] = nums[i];
                notTargetIndex++;
            }
        }
        return notTargetIndex;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
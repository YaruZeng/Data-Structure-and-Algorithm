class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // Solution1: two whiles
//         int left = 0, right = 0;
//         int sum = 0;
//         int minLen = INT_MAX;
        
//         while (right < nums.size()) {
//             sum += nums[right];
//             while (sum >= target) {
//                 sum -= nums[left];
//                 minLen = min(minLen, right - left + 1);
//                 left++;
//             }
//             right++;
//         }
//         return minLen == INT_MAX ? 0 : minLen;
        
        // Solution2: for + while
        
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
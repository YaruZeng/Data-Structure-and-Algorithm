class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      if (nums[0] == 0 && n != 1) return false;
      if (nums[0] == 0 && n == 1) return true;

      // # loop through the array to record the maximum distance can be reached
      int max_dist = 0;

      for (int i = 0; i <= max_dist; i++) {
        int dist = i + nums[i]; // 1
        if (dist > max_dist) { // 1
          max_dist = dist; 
        }
          
      if (max_dist >= n - 1) { // 4
        return true;
      }

      }

      // # check if we can reach the last index


      return false; 
    }
};
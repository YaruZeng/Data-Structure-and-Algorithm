class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                umap[num1 + num2]++; // record (num1 + num2: count) pairs
            }
        }

        int count = 0; // count the number of target tuples

        for (int num3 : nums3) {
            for (int num4 : nums4) {
                count += umap[0 - (num3 + num4)]; // sum the number of target tuples
            }
        }

        return count;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2) the worst case is when the nums in nums1 and nums2 are all different
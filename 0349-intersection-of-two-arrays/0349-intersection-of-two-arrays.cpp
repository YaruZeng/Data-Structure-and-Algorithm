class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_set(nums1.begin(), nums1.end()); // transfer nums1 to a set
        unordered_set<int> result; // output cannot contain repeatitive nums

        for (int i = 0; i < nums2.size(); i++) {
            if (nums1_set.find(nums2[i]) != nums1_set.end()) { // look for nums2[i] in nums1
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

// Time Complexity: O(mn)
// Space Complexity: O(n)
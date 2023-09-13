class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // use three pointers: two for traversing nums1 and nums2 in inverted order, one for store the larger number
        
        int i = m - 1; // index for nums1
        int j = n - 1; // index for nums2
        int k = m + n - 1; // index in nums1 to get correct number
        
        while (j >= 0) { // traverse all nums in nums2, if nums1 have more numbers, remain them as the correct order
            if (i >= 0 && nums1[i] > nums2[j]) { // avoid infinite loop
            // if m < n, add smaller numbers of nums2 to the start of nums1, e.g.nums1 = [2, 3], nums2 = [1, 2, 4]
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
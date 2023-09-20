class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;

        while (1) {
            int newN = getSum(n);
            if (newN == 1) return true;
            if (set.find(newN) != set.end()) return false; // loops endlessly in a cycle which does not include 1
            else set.insert(newN); // record the number 
            n = newN;
        }
    }
};

// Time Complexity: O(logN)
// Space Complexity: O(logN)
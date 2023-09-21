class Solution {
public:
    class MyQueue { // build a monotone decreasing queue
    public:
        deque<int> que;

        void push(int val) { 
            while (!que.empty() && val > que.back()) { // make sure the que is monotone decreasing
                que.pop_back();
            }
            que.push_back(val); 
        }

        void pop(int val) {
            if (!que.empty() && val == que.front()) { // pop only when the value is equal to the front value
                que.pop_front();
            }
        }

        int getMaxValue() { // the front value is always the max
            return que.front();
        }
    };


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue que;
        for (int i = 0; i < k; i++) { // push the first k values
            que.push(nums[i]);
        }
        result.push_back(que.getMaxValue()); 

        for (int i = k; i < nums.size(); i++) { // slice the window
            que.pop(nums[i - k]); // pop the last value
            que.push(nums[i]); // push a new value
            result.push_back(que.getMaxValue());
        }
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(k)
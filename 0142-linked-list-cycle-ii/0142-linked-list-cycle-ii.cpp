/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // define two pointers: slow and fast, slow moves 1 step at a time, fast moves 2 steps at a time
        // x: the distance between the head and the beginning of the cycle
        // y: the distance between the beginning of the cycle and the meeting point in the cycle
        // z: the rest of the distance in the cycle
        // slow: x + y
        // fast: x + y + n * (z + y)
        // 2 * (x + y) = x + y + n * (z + y)
        // x = n * (z + y) - y
        // x = (n - 1) * (z + y) + z
        // slow and fast must meet when slow enter the cycle for the first time
        // n = 1, x = z 
        // so the two distances: from head to the cycle start, from the meeting point to the cycle start
        // are equal

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // find the meeting point
                ListNode* meetingPoint = slow;
                ListNode* newPointer = head;
                while (meetingPoint != newPointer) { // to find the cycle start
                    meetingPoint = meetingPoint->next;
                    newPointer = newPointer->next;
                }
                return newPointer;
            }
        }
        return NULL;
    }
};
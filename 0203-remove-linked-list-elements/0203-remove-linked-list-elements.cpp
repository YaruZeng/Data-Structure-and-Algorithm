/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // create a dummyHead so that the same deletion logic can be applied to the head node
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* current = dummyHead;
        
        while (current->next != NULL) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
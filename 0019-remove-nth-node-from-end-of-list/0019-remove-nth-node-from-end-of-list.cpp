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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (n--) fast = fast->next;
        
        if (fast == NULL) { // n = size, remove head
            ListNode* temp = head->next;
            delete head;
            head = nullptr;
            return temp; 
        }
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* deleteNode = slow->next; // delete target node
        slow->next = slow->next->next;
        delete deleteNode;
        deleteNode = nullptr;
        
        return head;
    }
};
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
    int length(ListNode* head) { // get the length of the list
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        if (lenA < lenB) { // make sure A is the longer one
            swap(lenA, lenB);
            swap(curA, curB);
        }
        
        int gap = lenA - lenB;
        
        while (gap--) curA = curA->next; // aligh the length from cur to the end
        while (curA) { // look for the intersection
            if (curA == curB) { // nodes are the same not only value
                return curA; 
            } else { 
                curA = curA->next; curB = curB->next;
            }
        }
        
        return NULL;
    }
};
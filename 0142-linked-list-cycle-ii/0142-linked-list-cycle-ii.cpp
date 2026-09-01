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
    ListNode* find(ListNode* slow, ListNode* fast){
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return find(head, fast);
        }
        return NULL;
    }
};
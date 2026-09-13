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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        ListNode* newHead = t2;
        ListNode* prev = t1;
        while(t2!=NULL && t1!=NULL && t1->next!=NULL){
            t1->next = t2->next;
            t2->next = t1;
            t1 = t1->next;
            if(t1!=NULL && t1->next!=NULL) t2 = t1->next;
            else break;
            if(prev!=NULL) prev->next = t2;
            prev = t1;
        }
        return newHead;
    }
};
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                ans->next = l1;
                ans = l1;
                l1 = l1->next;
            }
            else{
                ans->next = l2;
                ans = l2;
                l2 = l2->next;
            }
        }
        while(l1!=NULL){
            ans->next = l1;
            ans = l1;
            l1 = l1->next;
        }
        while(l2!=NULL){
            ans->next = l2;
            ans = l2;
            l2 = l2->next;
        }
        return dummy->next;
    }
};
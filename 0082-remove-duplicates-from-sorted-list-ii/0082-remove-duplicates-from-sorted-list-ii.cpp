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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(temp!=NULL){
            
            if(temp->next!=NULL && temp->val==temp->next->val){
                int value = temp->val;
                while(temp!=NULL && temp->val==value){
                    temp = temp->next;
                }
            }
            else{
                prev->next = temp;
                prev = prev->next;
                temp = temp->next;
            }

        }
        prev->next = NULL;
        
        return dummy->next;
    }
};
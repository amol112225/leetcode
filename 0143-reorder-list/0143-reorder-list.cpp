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

using ln = ListNode;
class Solution {
public:
    ln* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        return prev;
    }

    void show(ListNode* head) {
        ln *temp = head;

        while(temp) {
            cout << temp->val << ' ';
            temp = temp -> next;
        }
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = head;
        while(last->next!=NULL) last = last->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = NULL;
        if(fast==NULL) middle = slow;
        else middle = slow;
        reverse(middle);

        
        ListNode* t1 = head;
        ListNode* t2 = last;

        while((t1->next!=last && t2->next!=NULL)){
            ListNode* temp1 = t1->next;
            ListNode* temp2 = t2->next;
            t1->next = t2;
            t2->next = ((temp1 == last) ? NULL : temp1);
            t1 = temp1;
            t2 = temp2;
        }

    }
};
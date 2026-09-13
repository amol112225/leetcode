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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        int cnt = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev1 = dummy;
        for(int i=1; i<left; i++){
            prev1 = prev1->next;
        }
        ListNode* node1 = prev1->next;
        
        ListNode* node2 = node1;
        for(int i=1; i<=right-left; i++) node2 = node2->next;
        ListNode* front2 = node2->next;
        node2->next = NULL;
        prev1->next = reverseList(node1);
        node1->next = front2;
        return dummy->next;

    }
};
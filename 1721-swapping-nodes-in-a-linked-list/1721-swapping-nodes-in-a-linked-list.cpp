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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return head;
        
        int cnt = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;


        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        if(k==n-k+1) return head;


        ListNode* node1 = head;
        ListNode* prev1 = dummy;
        for(int i=1; i<k; i++){
            prev1 = node1;
            node1 = node1->next;
        }


        ListNode* node2 = head;
        ListNode* prev2 = dummy;
        for(int i=1; i<n-k+1; i++){
            prev2 = node2;
            node2 = node2->next;
        }
        
        if(node1->next == node2){
            prev1->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            
        }
        else if(node2->next == node1){
            prev2->next = node1;
            node2->next = node1->next;
            node1->next = node2;
        }
        else{
            ListNode* nxt2 = node2->next;
            ListNode* nxt1 = node1->next;
            prev1->next = node2;
            prev2->next = node1;
            node2->next = nxt1;
            node1->next = nxt2;
        }
        
        return dummy->next;
    }
};
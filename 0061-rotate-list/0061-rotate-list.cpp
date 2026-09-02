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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        k = k%n;
        if(n==k || k==0) return head;
        temp = head;
        int cnt = n-k-1;
        while(cnt!=0){
            temp = temp->next;
            cnt--;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* tail = newHead;
        while(tail->next!=NULL) tail = tail->next;
        tail->next = head;
        return newHead;


    }
};
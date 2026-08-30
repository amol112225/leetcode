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
    ListNode *collision(ListNode*l1, ListNode*l2, int d){
        while(d>0){
            d--;
            l2 = l2->next;
        }
        while(l1!=NULL){
            if(l1==l2) return l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        return NULL;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        int n1 = 0;
        while(temp!=NULL){
            n1++;
            temp = temp->next;
        }
        temp = headB;
        int n2 = 0;
        while(temp!=NULL){
           n2++;
            temp = temp->next;
        }
        if(n1<n2){
            return collision(headA, headB, n2-n1);
        }
        return collision(headB, headA, n1-n2);
    }
};
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
    ListNode* findKnode(ListNode* temp, int k){
        while(k>1){
            if(temp==NULL) return NULL;
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverse(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* kNode = findKnode(temp, k);
            if(kNode==NULL){
                if(prevNode!=NULL) prevNode->next = temp;
                break;
            }
            nextNode = kNode->next;
            kNode->next = NULL;
            reverse(temp);
            if(temp==head) head = kNode;
            else prevNode->next = kNode;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
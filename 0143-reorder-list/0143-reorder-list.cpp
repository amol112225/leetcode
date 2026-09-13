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
    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        vector<int>arr1;
        int i=0;
        int j=n-1;
        while(i<=j){
            arr1.push_back(arr[i]);
            i++;
            arr1.push_back(arr[j]);
            j--;
        }
        temp = head;
        int ind = 0;
        while(temp!=NULL){
            temp->val = arr1[ind];
            ind++;
            temp = temp->next;
        }
        

    }
};
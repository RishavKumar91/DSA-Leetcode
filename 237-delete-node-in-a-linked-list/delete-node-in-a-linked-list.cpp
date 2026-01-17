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
    void deleteNode(ListNode* node) {
        // ListNode * t = node; 
        // while(t->next!=NULL){
        //     t->val = t->next->val;
        //     t = t->next;
       //     if(t->next->next==NULL) t->next = NULL;
        // }
    
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
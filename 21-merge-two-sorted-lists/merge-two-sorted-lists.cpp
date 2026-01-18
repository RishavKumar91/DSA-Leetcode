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
        ListNode * dumm = new ListNode(-1);
        ListNode * dumm2 =  new ListNode(-1);
        ListNode * tmp = dumm;ListNode *a;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val) {
                a = new ListNode(list1->val); 
                list1 = list1->next;}
            else{
                a = new ListNode(list2->val); 
                list2 = list2->next;}
            tmp->next = a;
            tmp = tmp->next;
        }
        while(list1!=NULL){
            a = new ListNode(list1->val); 
                list1 = list1->next;
                tmp->next = a;
            tmp = tmp->next;
        }
        while(list2!=NULL){
            a = new ListNode(list2->val); 
                list2 = list2->next;
                tmp->next = a;
            tmp = tmp->next;
        }
    return dumm->next;
    }
};
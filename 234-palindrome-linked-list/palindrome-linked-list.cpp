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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prrv = new ListNode(-1); prrv->next  = head;
        while(fast && fast->next){
            fast = fast->next->next ; 
            slow = slow->next; prrv = prrv->next;
        }
        ListNode* now = slow , * prv = NULL ;
        while(now){
            ListNode *nxt = now->next;
            now->next = prv ;
            prv = now ;
            now = nxt ; 
        }
        ListNode * p1 = head , *p2 = prv ;
        while(p2){
            if(p2->val != p1->val) return 0;
            p1 = p1->next ; p2 = p2->next;
        }
    return 1;
    }
};

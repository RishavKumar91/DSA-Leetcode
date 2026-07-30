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
        while(fast && fast->next){
            fast = fast->next->next ; 
            slow = slow->next; 
        }
        ListNode* now = slow , * prv = NULL ;
        while(now){
            ListNode *nxt = now->next;
            now->next = prv ;
            prv = now ;
            now = nxt ; 
        }
        slow = head ; fast = prv ;
        while(fast){
            if(fast->val != slow->val) return 0;
            slow = slow->next ; fast = fast->next;
        }
    return 1;
    }
};

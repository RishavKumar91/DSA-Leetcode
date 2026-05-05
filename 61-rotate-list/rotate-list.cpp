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
        if(!head || k==0 || !head->next ) return head;
        int n = 1;
        ListNode *tail = head;
        while(tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n ;
        if(k==0) return head;

        tail->next = head;
        
        ListNode * nayatail = head;
        for(int i = 0;i<n-k-1;i++) {
            nayatail = nayatail->next;
        }

        ListNode * nayahead = nayatail->next;
        nayatail->next = NULL;
    return nayahead;
    }
};
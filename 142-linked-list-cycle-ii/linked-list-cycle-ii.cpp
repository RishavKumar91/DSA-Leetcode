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
    ListNode *detectCycle(ListNode *head) {
        ListNode * tmp = head;
        unordered_set<ListNode *> st;
        while(tmp != NULL){
            if(st.count(tmp)) return tmp;
            st.insert(tmp);
            tmp = tmp->next;
        }
    return NULL;
    }
};
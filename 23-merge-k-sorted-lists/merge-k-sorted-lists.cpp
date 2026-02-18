class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) return NULL;

        for(int i = 0; i < lists.size() - 1; i++) {
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
        }

        return lists.back();
    }
};

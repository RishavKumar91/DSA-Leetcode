class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> mh(cmp);
        for(auto x : lists)
            if(x) mh.push(x);

        ListNode dummy(-1);
        ListNode* tmp = &dummy;
        while(!mh.empty()){
            auto node = mh.top();
            mh.pop();
            tmp->next = node;
            tmp = tmp->next;
            if(node->next)
                mh.push(node->next);
        }
        return dummy.next;
    }
};


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;

//         if(list1->val < list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
//     ListNode* part(vector<ListNode*>& lists,int start,int end){
//         if(start>end) return NULL;
//         if(start==end) return lists[start];
//         int mi = start + (end-start)/2;
//         ListNode *first = part(lists,0,mi);
//         ListNode *last = part(lists,mi+1,end);
//         return mergeTwoLists(first,last);
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         return part(lists,0,lists.size()-1);
//     }
// };
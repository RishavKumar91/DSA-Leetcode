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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode * d = new ListNode(-1);
        ListNode * t = d;
        int a=0, carr=0;
        // while(l1!=NULL || l2!=NULL){
        //     a = l1->val + l2->val;
        //     a += carr;
        //     ListNode * nw = new ListNode(a%10);
        //     if(a>=10) carr = 1;
        //     else carr=0;
        //     t->next = nw;
        //     t = t->next;
        //     l1 = l1->next; l2 = l2->next;
        //     while(l1==NULL && l2!=NULL){
        //         a = l2->val;
        //         a+=carr;
        //         ListNode * nw = new ListNode(a%10 );
        //         if(a>=10) carr = 1;
        //         else carr=0;
        //         t->next = nw;
        //         t = t->next;
        //         l2= l2->next;
        //         if(l2==NULL) break;
        //     }
        //     while(l2==NULL && l1!=NULL){
        //         a = l1->val;
        //         a+=carr;
        //         ListNode * nw = new ListNode(a%10 );
        //         if(a>=10) carr = 1;
        //         else carr=0;
        //         t->next = nw;
        //         t = t->next;
        //         l1= l1->next;
        //         if(l1==NULL) break;
        //     }
        // }
        // if(carr==1){
        //     ListNode * nw = new ListNode(1);
        //     t->next= nw;
        // }
        // return d->next;
        while(list1 || list2 || carr!=0){
            a=0;
            if(list1!=NULL){
                a = list1->val;
                list1= list1->next;
            }
            if(list2!=NULL){
                a += list2->val;
                list2= list2->next;
            }
            a+=carr;
            carr = a/10;
            a=a%10;
            ListNode * nw = new ListNode(a);
            t->next = nw;
            t = t->next;
        }
        return d->next;
    }
};
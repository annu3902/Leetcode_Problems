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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * p1=list1;
        ListNode * p2=list1;

        while(a-1){
            p1=p1->next;
            // p2=p2->next;
            a--;
        }

        // int curr = a;
        while(b){
            p2=p2->next;
            b--;
        }
        ListNode * temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        // cout<<temp->val<<" ";
        // cout<<p2->val<<" ";
        temp->next=p2->next;
        p1->next=list2;

        return list1;
    }
};
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
    ListNode* solve(ListNode* &list1, ListNode* &list2, ListNode* &head){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val <= list2->val){
            if(head==NULL) head = list1;
            list1->next = solve(list1->next, list2,head);
            return list1;
        }

        else{
            if(head==NULL) head = list2;
            list2->next = solve(list2->next, list1,head);
            return list2;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        return solve(list1,list2,head);
    }
};

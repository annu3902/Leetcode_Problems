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

    ListNode* solve(ListNode* head){
        if(!head->next) return head;
        ListNode* nextNode = solve(head->next);
        if(head->val < nextNode->val)
            // delete(head);
            head = nextNode;
        else{
            head->next = nextNode;
        }
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        return solve(head);
    }
};
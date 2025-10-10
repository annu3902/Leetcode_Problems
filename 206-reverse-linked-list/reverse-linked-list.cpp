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
    void dfs(ListNode*& head, ListNode*& prev, ListNode*& curr){
        if(curr == nullptr){
            head = prev;    
            return;
        }

        dfs(head, curr, curr->next);
        curr->next = prev;
        
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        dfs(head, prev, curr);
        return head;
    }
};
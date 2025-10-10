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
private :
    ListNode* ans = NULL;

    void dfs(ListNode*& fast, ListNode* & slow){
        if(!fast || !fast->next){
            ans = slow;
            return;
        }

        dfs(fast->next->next, slow->next);
        return;
    }
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        dfs(fast, slow);
        
        return ans;
    }
};
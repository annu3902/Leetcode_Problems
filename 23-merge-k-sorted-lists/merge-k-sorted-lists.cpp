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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        else{
            l2->next= mergeTwoLists(l1, l2->next);
            return l2;
        }

    }

    ListNode* solve(vector<ListNode*>& lists, int start, int end){
        // if only one list is present
        if(start == end) return lists[start];
        // if more than one list is present
        int mid = start + (end-start)/2;

        ListNode* L1 = solve(lists, start, mid);
        ListNode* L2 = solve(lists, mid+1, end);

        return mergeTwoLists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int start = 0;
        int end = lists.size()-1;
        return solve(lists, start, end);
    }
};
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
    ListNode* sortList(ListNode* head) {
        map<int, int> freq;

        ListNode* temp=head;
        while(temp!=NULL){
            freq[temp->val]++;
            temp=temp->next;
        }

        temp=head;
        for(pair<int,int> it : freq){
            int first = it.first;
            int second = it.second;
            cout<<first<<" "<<second<<" ";
            while(second){
                temp->val=first;
                second--;
                temp=temp->next;
            }
        }
        return head;
    }
};
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
    int getLength(ListNode* &head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> partition;
        // n <= k
        // n-> no. of nodes
        int cnt=0;
        int n = getLength(head);
        
        // 1. partition vector bnao
        if(n <= k){
            while(n){
                partition.push_back(1);
                cnt++;
                n--;
            }

            while(cnt < k){
                partition.push_back(0);
                cnt++;
            }
        }

        // n > k
        else{
            int cnt = 0;
            while(k){
                int ans = round(n/k);
                partition.push_back(ans);
                n -= ans;
                k--;
            }
        }

        // for(int x : partition){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        // 2. list ka division according to partition NUmber
        vector<ListNode*> result;
        sort(partition.begin(), partition.end());
        reverse(partition.begin(), partition.end());
        
        for(int i=0; i<partition.size(); i++){
            int partitionNo = partition[i];
            // cout<<partitionNo<<" ";

            ListNode* temp = head;
            ListNode* prev = NULL;
            ListNode* dummy = new ListNode(-1);
            ListNode* ans = dummy;

            while(partitionNo > 0 && temp){
                dummy->next = temp;
                dummy = temp;
                prev = temp;
                temp = temp->next;
                partitionNo--;
            }

            dummy->next = NULL;
            result.push_back(ans->next);
            head = temp;
        }

        return result;
    }
};
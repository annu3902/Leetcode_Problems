/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null) return list2;
        else if(list2 == null) return list1;

        ListNode curr = null;
        if(list1.val <= list2.val){
            curr = list1;
            list1 = list1.next;
        }else{
            curr = list2;
            list2 = list2.next;
        }

        ListNode head = curr;

        // ListNode curr = (list1.val <= list2.val) ? list1 : list2;

        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                curr.next = list1;
                curr = curr.next;
                list1 = list1.next;
            }else{
                curr.next = list2;
                curr = curr.next;
                list2 = list2.next;
            }
        }

        if(list2 != null){
            curr.next = list2;
        }else if(list1 != null){
            curr.next = list1;
        }

        return head;
    }
}
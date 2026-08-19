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
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null) return head;

        ListNode odd = head;
        ListNode even = odd.next;
        ListNode currOdd = odd;
        ListNode currEven = even;

        while(currOdd != null && currEven != null){
            if(currEven != null){
                currOdd.next = currEven.next;
                currOdd = currOdd.next;
            }
            if(currOdd != null){
                currEven.next = currOdd.next;
                currEven = currEven.next;
            }
        }

            ListNode temp = odd;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = even;

        return head;
    }
}
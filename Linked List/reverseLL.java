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
    public ListNode reverseList(ListNode head) {
        ListNode curr=head;
        ListNode prev= null;
        while(curr!=null){

            // 1 2 3 4 5
            //          1
            ListNode next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }




        return prev;




    }
}